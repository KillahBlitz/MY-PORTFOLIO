from os import system
from random import randint

def barradevida(pokemon, vidaaliada, vidaenemiga):
    vidabarra = "#" * int(vidaaliada/5)
    vidafaltante = " " * (20 - int(vidaaliada/5))
    if pokemon == 1:
        print("Barra de vida de pikachu")
        print("[{}{}]".format(vidabarra,vidafaltante))
    elif pokemon == 2:
        print("Barra de vida de bulbasur")
        print("[{}{}]".format(vidabarra,vidafaltante))
    elif pokemon == 3:
        print("Barra de vida de squirtle")
        print("[{}{}]".format(vidabarra,vidafaltante))
    vidabarra="#" * int(vidaenemiga/5)
    vidafaltante = " " * (20 - int(vidaenemiga/5))
    print("Barra de vida de Charmander")
    print("[{}{}]".format(vidabarra, vidafaltante))

    if vidaaliada<=0 and vidaenemiga>0:
        print("Haz Perdido!!!")
    elif vidaenemiga<=0 and vidaaliada>0:
        print("Haz Ganado!!!")
    elif vidaenemiga<=0 and vidaaliada<=0:
        print("Oh no, esto ha sido empate")

def pikachu():
    vidapikachu = 100
    vidacharmander = 100
    while vidapikachu > 0 and vidacharmander > 0:
        #turno enemigo
        print("Turno de Charmander")
        ataquecharmander = randint(1,3)
        if ataquecharmander == 1:
            print("Charmander ataca con Araniazo")
            vidapikachu -= 10
        elif ataquecharmander == 2:
            print("Charmander ataca con Ascuas")
            vidapikachu -= 15
        elif ataquecharmander == 3:
            print("Charmander ataca con Lanzallamas")
            vidapikachu -= 20
        print("Turno de Pikachu")
        ataquepikachu = None
        while ataquepikachu != 1 and ataquepikachu != 2 and ataquepikachu != 3:
            ataquepikachu = int(input("\n1. Grunido\n2. latigo\n3. Impactrueno\n"))
            if ataquepikachu == 1:
                print("Pikachu ataca con Grunido")
                vidacharmander -= 10
            elif ataquepikachu == 2:
                print("Pikachu ataca con Latigo")
                vidacharmander -= 15
            elif ataquepikachu == 3:
                print("Pikachu ataca con Impactrueno")
                vidacharmander -= 20
        print("La vida de Charmander es: {} y La vida de Pikachu es: {}".format(vidacharmander,vidapikachu))
        barradevida(1, vidapikachu, vidacharmander)
        input("enter para continuar...")
        system("cls")


def bulbasur():
    vidabulbasur = 100
    vidacharmander = 100
    while vidabulbasur > 0 and vidacharmander > 0:
        #turno enemigo
        print("Turno de Charmander")
        ataquecharmander = randint(1,3)
        if ataquecharmander == 1:
            print("Charmander ataca con Araniazo")
            vidabulbasur -= 10
        elif ataquecharmander == 2:
            print("Charmander ataca con Ascuas")
            vidabulbasur -= 15
        elif ataquecharmander == 3:
            print("Charmander ataca con Lanzallamas")
            vidabulbasur -= 20
        print("Turno de Bulbasur")
        ataquebulbasur = None
        while ataquebulbasur != 1 and ataquebulbasur != 2 and ataquebulbasur != 3:
            ataquebulbasur = int(input("\n1. Grunido\n2. Placaje\n3. Latigo Sepa\n"))
            if ataquebulbasur == 1:
                print("Bulbasur ataca con Grunido")
                vidacharmander -= 10
            elif ataquebulbasur == 2:
                print("Bulbasur ataca con Placaje")
                vidacharmander -= 15
            elif ataquebulbasur == 3:
                print("Bulbasur ataca con Latigo Sepa")
                vidacharmander -= 20
        print("La vida de Charmander es: {} y La vida de Bulbasur es: {}".format(vidacharmander,vidabulbasur))
        barradevida(2, vidabulbasur, vidacharmander)
        input("enter para continuar...")
        system("cls")



def squirtle():
    vidasquirtle = 100
    vidacharmander = 100
    while vidasquirtle > 0 and vidacharmander > 0:
        #turno enemigo
        print("Turno de Charmander")
        ataquecharmander = randint(1,3)
        if ataquecharmander == 1:
            print("Charmander ataca con Araniazo")
            vidasquirtle -= 10
        elif ataquecharmander == 2:
            print("Charmander ataca con Ascuas")
            vidasquirtle -= 15
        elif ataquecharmander == 3:
            print("Charmander ataca con Lanzallamas")
            vidasquirtle -= 20
        print("Turno de Squirtle")
        ataquesquirtle = None
        while ataquesquirtle != 1 and ataquesquirtle != 2 and ataquesquirtle != 3:
            ataquesquirtle = int(input("\n1. Latigo\n2. Placaje\n3. Burbuja\n"))
            if ataquesquirtle == 1:
                print("Squirtle ataca con Latigo")
                vidacharmander -= 10
            elif ataquesquirtle == 2:
                print("Squirtle ataca con Placaje")
                vidacharmander -= 15
            elif ataquesquirtle == 3:
                print("Squirtle ataca con latigo Sepa")
                vidacharmander -= 20
        print("La vida de Charmander es: {} y La vida de Squirtle es: {}".format(vidacharmander,vidasquirtle))
        barradevida(3, vidasquirtle, vidacharmander)
        input("enter para continuar...")
        system("cls")





inpot = None
while inpot != 1 and inpot != 2:
    print("empezar el videojuego?")
    inpot = int(input("\n1. Jugar\n2. Salir\n"))

if inpot == 1:
    selectpokemon=None
    while selectpokemon!=1  and selectpokemon!=2 and selectpokemon!=3:
        system("cls")
        print("escoje tu pokemon para pelear: ")
        selectpokemon=int(input("\n1. Pikachu\n2. Bulbasur\n3. Squirtle\n"))
        system("cls")
    if selectpokemon == 1:
        print("haz escogido a Pikachu")
        print("la pelea es contra un Charmander")
        pikachu()
    elif selectpokemon == 2:
        print("haz escogido a Bulbasur")
        print("la pelea es contra un Charmander")
        bulbasur()
    elif selectpokemon == 3:
        print("haz escogido a Squirtle")
        print("la pelea es contra un Charmander")
        squirtle()


elif inpot == 2:
    system("cls")
    input("Presiona enter para Salir...")