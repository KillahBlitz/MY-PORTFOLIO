import pickle
from requests_html import HTMLSession
import time

#codigo que nos permitira guardar los datos de cada uno de los 150 pokemon

#diccionario con los parametros de cada pokemon
pokemon_base = {
    "idpok": "",
    "namep": "",
    "current_health": 100,
    "base_health": 100,
    "level": 1,
    "type": None,
    "current_exp": 0
}

#url donde saco la base de datos de los pokemones
URL_BASE = "https://www.pokexperto.net/index2.php?seccion=nds/nationaldex/movimientos_nivel&pk="


#funcioon de usuario que extrae la informacion de los pokemones
def get_pok(index):
        try:
            # inicio sesion en la url, osea abro la url
            url = "{}{}".format(URL_BASE,index)
            session = HTMLSession()

            new_pokemon = pokemon_base.copy()
            pokemon_page = session.get(url)

            #codigo para recoger el nombre de los pokemones
            new_pokemon["namep"] = pokemon_page.html.find(".mini", first=True).text.split('\n')[0]

            #codigo para recoger el tipo de pokemon
            new_pokemon["type"] = []
            img_tags = pokemon_page.html.find(".pkmain", first=True).find(".bordeambos", first=True).find("img")
            for img in img_tags:
                new_pokemon["type"].append(img.attrs.get("alt", "Unknown"))  # Recuperar el atributo "alt"

            #codigo para recoger los ataques de los pokemones
            new_pokemon["attacks"] = []
            attacks_element = pokemon_page.html.find(".pkmain")[-1].find(".check3")
            for attack_item in attacks_element:
                try:
                    attack = {
                        "name": attack_item.find("td", first=True).find("a", first=True).text,
                        "type": attack_item.find("td")[1].find("img", first=True).attrs["alt"],
                        "main_level": attack_item.find("th", first=True).text,
                        "damage": int(attack_item.find("td")[3].text.replace("--", "0")),
                    }
                    new_pokemon["attacks"].append(attack)

                except Exception as e:
                    print(f"Error al procesar el ataque: {e}")

            #retorno de resultados
            new_pokemon["idpok"] = index
            print(f"{index}. {new_pokemon["namep"]}")
            return new_pokemon
        except Exception as e:
            # En caso de error (página vacía, elementos no encontrados, etc.), se salta al siguiente Pokémon.
            print(f"pokemon {index} no encontrado error: {e} no aniadido a la lista")

def get_all_pokemons():
    all_pokemons = []
    for index in range(150):
        all_pokemons.append(get_pok(index+1))
    with open("pokefile.pkl", "wb") as pokefile:
        pickle.dump(all_pokemons, pokefile)
    return all_pokemons

def main():
    time.sleep(1)
    print("Iniciando descarga de pokemones")
    get_all_pokemons()
    print("Todos los pokemones han sido descargados")
    print("pulsa enter para continuar...")
    input("")


if __name__ == "__main__":
    main()