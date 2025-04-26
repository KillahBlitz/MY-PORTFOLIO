from os import system
from random import  randint


def ruleta_rusa():
    t = True
    while t:
        bala = int(input("selecciona que bala quieres accionar (del 1 al 6): "))
        if bala == randint(1,6):
            print("haz muerto :(")
        else:
            print("vaya suerte, no ha pasado nada :)")
        reintento = int(input("quieres volver a intentarlo? \n1.Si \n2.No\n"))
        if  reintento== 1:
            t = True
            input("buena suerte chico, pulsa cualquier tecla para continuar...")
            system("cls")
        else:
            t = False
            input("okay es valido, pulsa cualquier tecla para continuar...")
            system("cls")


def potencia(num):
    return num*num


def fibonaccirecursivo(num):
    if num <= 1:
        return 1
    return fibonaccirecursivo(num - 1) + fibonaccirecursivo(num - 2)


def fibonaccinorecursivo(num):
    # Implementación no recursiva de la serie de Fibonacci
    if num == 0:
        return 0
    elif num == 1:
        return 1
    a, b = 0, 1
    for _ in range(2, num + 1):
        a, b = b, a + b
    return b


def potenciada(num,pot):
    numbase = num
    for n in range(pot):
        num = num * numbase
    return num


def stringfuncion(*args):
    arreglodestrings = []
    ty = True
    a = 0
    thenewword = ""
    while ty:
        system("cls")
        palabra = input("quieres agregar algun termino (si no presiona 1): ")
        arreglodestrings.append(palabra)
        if palabra == '1':
            ty = False
    for name in arreglodestrings:
        if a<=len(name):
            thenewword = name
            a = len(name)
    return  thenewword


def sumadordelistas():
    arreglodeints = []
    ty = True
    resultado = 0
    while ty:
        system("cls")
        numero = int(input("quieres agregar algun termino (si no presiona 0): "))
        arreglodeints.append(numero)
        if numero == 0:
            ty = False
    for n in arreglodeints:
        resultado = resultado + n
    return  resultado


def paroimpar(n):
    if n%2 == 0:
        return True
    else:
        return False


def areyousure(nono):
    if nono:
        return True
    else:
        return False


def todoenmayus(cadena):
    mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    minusculas = "abcdefghijklmnopqrstuvwxyz"
    resultado = ""

    for caracter in cadena:
        if caracter in minusculas:
            indice = minusculas.index(caracter)
            resultado += mayusculas[indice]
        else:
            resultado += caracter

    return resultado


def adiviname():
    randomnum = randint(1,100)
    verdadero = True
    while verdadero:
        n = int(input("en que numero crees que pienso amigo: "))
        if randomnum == n:
            print("vaya suerte, le haz atinado")
            print("ahora sal de este bucle")
            verdadero = False
        else:
            input("estas mal, intenta de nuevo...")
            system("cls")


def listadecompras():
    shoplist = []
    ty = True
    bandera = None
    while ty:
        e = input("que elemento quieres agregar?: ")
        for elemento in shoplist:
            if elemento == e:
                bandera = True
            else:
                bandera = False
        if bandera:
            print("{} ya esta en la lista de compras".format(e))
            input("presiona enter para continuar...")
        else:
            shoplist.append(e)
            print("{} agregado".format(e))
            input("presiona enter para continuar...")
        system("cls")
        tn = True
        while tn:
            print("deseas agregar algo mas? \n1.Si \n2.No \n3.Ver lista de compras\n")
            decision = int(input(""))
            if decision == 1:
                ty = True
                tn = False
            elif decision == 2:
                ty = False
                tn = False
                system("cls")
            elif decision == 3:
                for elemento in shoplist:
                    print(elemento,"\n")
                input("presiona enter para continuar...")
                system("cls")
                ty = False
                tn = True




def menu():
    quitt = True
    while quitt:
        system("cls")
        print("1.Ejercicio 1A (ruleta rusa)")
        print("2.Ejercicio 2A (potencia)")
        print("3.Ejercicio 1B (fibonacci recursivo)")
        print("4.Ejercicio 2B (fibonacci no recursivo)")
        print("5.Ejercicio 3B (potencias selectivas)")
        print("6.Ejercicio 1C (La string mas larga)")
        print("7.Ejercicio 2C (Sumando lista)")
        print("8.Ejercicio 3C (Par o Impar)")
        print("9.Ejercicio 4C (Ruleta rusa pero te pregunta si estas seguro)")
        print("10.Ejercicio 5C (Todo a mayusculas)")
        print("11.Ejercicio 6C (adivina el numero)")
        print("12.Ejercicio 7C (lista de compras)")
        opc = int(input("cual ejercicio deseas acceder? (0 para salir): "))

        system("cls")
        if opc == 1:
            ruleta_rusa()
        elif opc == 2:
            numeropotenciado = int(input("que numero quieres potenciar al cuadrado?: "))
            numeropotenciado = potencia(numeropotenciado)
            print("el resultado es: {}".format(numeropotenciado))
            input("presiona cualquier tecla para continuar...")
        elif opc == 3:
            int(input("cuantos numeros quieres de la serie?: "))
            print("el resultado es:")
            for numero in range(10):
                print(", ",fibonaccirecursivo(numero), end="")
            input("\npresiona cualquier tecla para continuar...")
        elif opc == 4:
            numero = int(input("cuantos numeros quieres de la serie?: "))
            numero = fibonaccinorecursivo(numero)
            print("el resultado es: {}".format(numero))
            input("presiona cualquier tecla para continuar...")
        elif opc == 5:
            numeropotenciado = int(input("que numero quieres potenciar?: "))
            potencias = int(input("que numero quieres potenciar?: "))
            numeropotenciado = potenciada(numeropotenciado, potencias)
            print("el resultado es: {}".format(numeropotenciado))
            input("presiona cualquier tecla para continuar...")
        elif opc == 6:
            word = stringfuncion()
            print("la string mas larga es: {}".format(word))
        elif opc == 7:
            r = sumadordelistas()
            print("la suma total es {}".format(r))
        elif opc == 8:
            num = int(input("ingresa el numero que quieres comparar: "))
            ToF = paroimpar(num)
            if ToF:
                print("el numero es par")
            else:
                print("el numero es impar")
        elif opc == 9:
            nono = input("de verdad quieres jugar? (presiona 0 para no jugar): ")
            if nono == '0':
                yes = areyousure(True)
            else:
                yes = areyousure(False)
            if yes:
                ruleta_rusa()
        elif opc == 10:
            c = input("muestrame el texto que pase a mayusculas: ")
            print("resultado: {}".format(todoenmayus(c)))
        elif opc == 11:
            adiviname()
        elif opc == 12:
            listadecompras()
        elif opc == 0:
            input("presiona cualquier tecla para salir...")
            quitt = False







def main():
    menu()


if __name__ == "__main__":
    main()