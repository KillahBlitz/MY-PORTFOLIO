import random

#Adivinando el numero random

Var1 = random.randint(0,10)

Var2 = int(input("cual es el numero que deseas comparar entre el 1 y el 10?: "))

if Var1 == Var2:
    print("Felicidades, Acabas de ganar!!!!")
else:
    print("La verdad ni yo sabia el numero, pero no, el numero es {}".format(Var1))

