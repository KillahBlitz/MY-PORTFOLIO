import pickle
import random
import time
from os import system

#variables globales
def get_player(all_pokemonsF):
    return {
        "player_n": input("ingresa tu nombre gamer: "),
        "pokemon_invertory": [random.choice(all_pokemonsF) for a in range(3)],
        "combats": 0,
        "pokeballs": 0,
        "health_potion": 0
    }


def any_player_pokemon_lives(profile):
    return  sum([pokemon["current_health"] for pokemon in profile["pokemon_invertory"]])>0

def get_pokemon_info(poke):
    return "{} || {} || {}/{}".format(poke['namep'],
                                            poke['level'],
                                            poke['current_health'],
                                            poke['base_health'])

def choose_pokemon(profile):
    chosen = None
    while not chosen:
        print("elige tu pokemon para luchar")
        print("--- POKEMON INVENTORY ---")
        print("Nombre || Nivel || Vida")
        for i in range(len(profile["pokemon_invertory"])):
            print(f"{i}: {get_pokemon_info(profile['pokemon_invertory'][i])}")
        try:
            return profile["pokemon_invertory"][int(input(">>> "))]
        except (ValueError, IndexError):
            print("Opcion invalida")
            input("Presiona enter para continuar...")
            system("cls")


def fight(profile,enemy):
    print("--- NUEVO COMBATE ---")
    player_pokemon = choose_pokemon(profile)
    system("cls")
    print(f"{get_pokemon_info(player_pokemon)} vs {get_pokemon_info(enemy)}")
    input("Presiona enter para comenzar...")
    system("cls")



    print("--- FIN DEL COMBATE ---")
    input("Presiona enter para comenzar...")


def creditos():
    opc1 = 0
    while opc1 != 1:
        system("cls")
        print("Este videojuego es creado por Killah")
        print("Con la finalidad de concluir el curso en mastermind")
        print("Impartido por NateGentile")
        print("Introduccion a python")
        print("version 2.3v \n\n")
        opc1 = int(input("         1.Salir\n >>"))
        if opc1 == 1:
            system("cls")
        else:
            system("cls")


def load_menu(all_pokemonsF):
    # disenio de menu
    allpok = all_pokemonsF
    booleano = True
    while booleano:
        system("cls")
        print("||||||||     ||||||   ||    || ||||||||||  ||||        ||||   ||||||   ||||         ||")
        print("||      || ||      || ||  ||   ||          ||  ||    ||  || ||      || ||  ||       ||")
        print("||      || ||      || ||||     ||||||||||  ||    ||||    || ||      || ||   ||      ||")
        print("||||||||   ||      || ||||     ||          ||            || ||      || ||     ||    ||")
        print("||         ||      || ||  ||   ||          ||            || ||      || ||       ||  ||")
        print("||           ||||||   ||    || ||||||||||  ||            ||   ||||||   ||         ||||")
        print("by Killah")

        print("                                     1.Jugar")
        print("                                     2.Creditos")
        print("                                     3.Salir")

        # Pedir la opción al usuario
        opc = int(input(">>"))
        if opc == 1:
            profile = get_player(allpok)
            system("cls")
            while any_player_pokemon_lives(profile):
                enemy = random.choice(allpok)
                fight(profile,enemy)

            print("perdiste!!!")
            print(f"Record de combate: {profile['combats']}")
        elif opc == 2:
            creditos()
        elif opc == 3:
            print("saliste")
            input("Presiona enter para salir...")
            booleano = False
        else:
            print("opcion invalida, intentalo de nuevo.")
            input("Presiona enter para continuar...")
            system("cls")


def load_data():
    try:
        with open("pokefile.pkl", "rb") as pokefile:
            print("cargando pokemones...")
            all_pokemons = pickle.load(pokefile)
            print("los pokemones han sido cargados!!!")
            input("pulsa enter para empezar a jugar...")
            system("cls")
        return all_pokemons
    except Exception as e:
        print(f"ERROR: {e} favor de cargar los pokemones con pokeload.py desde el script en la terminal")
        return 0





def main():
    time.sleep(1)
    all_pokemonsF = load_data()
    if all_pokemonsF == 0:
        return 0
    else:
        load_menu(all_pokemonsF)
if __name__ == "__main__":
    main()