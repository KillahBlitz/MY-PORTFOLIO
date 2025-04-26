from os import system

c=True
opc=0

def funcionalgebraica():
    print("                         |                     ****")
    print("                         |               ******    ")
    print("                         |           ****          ")
    print("                         |        *•*              ")
    print("                         |     ***                 ")
    print("                         |  ***                    ")
    print("                         | *                       ")
    print("                         |*                        ")
    print("                         *                         ")
    print("                         *                         ")
    print("-------------------------+-------------------------")
    print("                         *                         ")
    print("                         *                         ")
    print("                        *|                         ")
    print("                       * |                         ")
    print("                    ***  |                         ")
    print("                 ***     |                         ")
    print("              ***        |                         ")
    print("          ****           |                         ")
    print("    ******               |                         ")
    print("****                     |                         ")

def videojuego():
    system("cls")
    print("Estas en el espacio, eres el capitan de la tripulacion")
    nombret = input("cual es el nombre de tu tripulacion?: ")
    on = True
    off = True
    while on:
        print("la tripulacion {} esta en busca de un planeta para encontrar minerales".format(nombret))
        print("las opciones que tienes son: \nA)RunMerra \nB)BurnSaturn \nC)AlmosTwo")
        opciones = input("que planeta deseas visitar?: (seleccionala por letra)\n")
        if opciones=='A' or opciones=='a':
            while off:
                print("llegas a 10 millas antes de RunMerra pero te encuentras con otra tripulacion")
                print("ellos te piden la clave de la zona para poder continuar la ruta")
                print("pero tu no perteneces a la legion de tripulantes asi que te deciden dar una pista")
                print("te dicen que es la adicion de un numero par a el producto de un numero impar y un par")
                print("Cualquier numero resultante de esa operacion es la clave correcta")
                eleccion=int(input("que deseas hacer?: \n1.contestas la pregunta \n2.consultas tu calculadora\n"))
                if eleccion==1:
                    on = False
                    eleccion=int(input("Ingresa la clave correcta: "))
                    if eleccion%2==0:
                        print("puedes pasar sin problemas, llegas al planeta y te das cuenta que tiene lo que necesitas")
                        print("decides revisar y encuentrar Metralium, un material valioso que vale demasiado")
                        print("te haces rico y con tu fortuna expandes tu dominio siendo "
                            "{} la tripulacion mas importante del universo".format(nombret))
                        input("presiona enter para cerrar el juego...")
                        off=False
                    else:
                        off=False
                        print("la clave es incorrecta, deciden atacarte, danian tu motor principal")
                        print("no tienes escapatoria, solo queda entregarte o morir en el intento de escapar")
                        eleccion = input("que deseas hacer?: \nA) entregarte B) escapar\n")
                        if eleccion == 'A' or eleccion == 'a':
                            print("te entregas, te arrestan y la tripulacion {} se disparse, haz fracasado".format(nombret))
                            input("presiona enter para cerrar el juego...")
                        elif eleccion == 'B' or eleccion == 'b':
                            print("activas el viaje intercuantico pero en medio viaje tu nave falla y explota")
                            print("no se vuelve a saber de la tripulacion {} Haz fracasado".format(nombret))
                            input("presiona enter para cerrar el juego...")
                        else:
                            print("por chistosito aun asi pierdes >:c")
                            input("presiona enter para cerrar el juego...")
                elif eleccion==2:
                    on = False
                    print("Consultas tu calculadora cosmica para saber el significado de las operaciones:")
                    print("adicion +")
                    print("sustracion -")
                    print("producto *")
                    print("Cociente /")
                    input("presiona enter para continuar...")
                else:
                    print("ANDA, que haz encontrado un easter egg, en horabuena, un tripulante te dice la operacion")
                    print("a+b*c")
                    print("donde a es par, b es impar y c es par")
                    input("presiona enter para continuar...")

        elif opciones=='B' or opciones=='b':
            on = False
            while off:
                print("Decides ir hacia BurnSaturn encuentras el planeta pero tienes que hacer un calculo")
                print("tienes que calcular la funcion que te permita tener la trayectoria correcta y llegar a destino")
                print("pero hay un punto especifico antes de llegar a la funcion "
                            "donde se debe activar la velocidad intercuantica")
                seleccion=int(input("deseas calcular la funcion?: \n1.Si 2.No\n"))
                if seleccion==1:
                    print("la funcion que calculas y es 5x^(1/3)")
                    funcionalgebraica()
                    result = int(input("si X=8, cual es el valor de la funcion donde debes hacer el salto espacial?: "))
                    if result==10:
                        print("haz dado con el resultado, llegaste al planeta, sin embargo, no encuentras minerales")
                        print("pero si una poblacion dispuesta a servirte por la tecnologia que haz traido")
                        print("la tripulacion {} se vuelve una republica y te vuelves un gran emperador".format(nombret))
                        input("presiona enter para cerrar el juego...")
                        off=False
                    else:
                        print("hiciste mal el salto")
                        print("decides activar la velocidad intercuantica en un punto incorrecto "
                              "asi que viajas a otro lugar")
                        print("llegas a una base de debastadores, ellos arrasan con tu nave asi que la tripulacion "
                              "{} deesaparese sin dejar rastro".format(nombret))
                        input("presiona enter para cerrar el juego...")
                        off=False
                elif seleccion==2:
                    print("al no calcular la funcion decides ir sin calcular la trayectoria")
                    print("decides activar la velocidad intercuantica en un punto incorrecto "
                                                                "asi que viajas a otro lugar")
                    print("llegas a una base de debastadores, ellos arrasan con tu nave asi que la tripulacion "
                                                            "{} deesaparese sin dejar rastro".format(nombret))
                    input("presiona enter para cerrar el juego...")
                    off = False
                else:
                    print("esa eleccion es invalida")


        elif opciones == 'C' or opciones == 'c':
            print("lamentablemente en esa ruta no hay nada, llegas al planeta y solo hay rocas sin valor")
            print("decides regresar a tu base en {} Portal".format(nombret))
            input("da enter para continuar...")
            system("cls")
        else:
            print("Muy listo amigo, pero no, esa opcion no existe, escoje otra anda")
            input("da enter para continuar...")
            system("cls")



def creditos():
    c1 = True
    while c1:
        system("cls")
        print("Este videojuego es creado por Killah")
        print("Con la finalidad de concluir la primera parte del curso en mastermind")
        print("Impartido por NateGentile")
        print("Videojuego de mazmorras para la conclusion del tema If")
        print("Introduccion a python")
        print("version 1.0v \n\n")
        opc1 = int(input("         1.Salir\n >>"))
        if opc1 == 1:
            system("cls")
            c1 = False
        else:
            system("cls")


while c:
    print("La disputa espacial \n by Killah")

    print("                                     1.Jugar")
    print("                                     2.Creditos")
    print("                                     3.Salir")

    # Pedir la opción al usuario
    opc = int(input(">>"))
    if opc == 1:
        videojuego()
        c = False
    elif opc == 2:
        creditos()
    elif opc == 3:
        print("saliste")
        input("da enter para continuar...")
        c = False
    else:
        print("opcion invalida, intentalo de nuevo.")
        input("da enter para continuar...")
        system("cls")