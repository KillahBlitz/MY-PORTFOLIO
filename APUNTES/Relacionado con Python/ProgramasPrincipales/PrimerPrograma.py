#Intento de programas

#creacion de variables donde input es donde el usuario ingresa un valor
usrname = input("Cual es tu nombre?: ") #funcion para entrar un valor o variable
print("tu nombre es: " + usrname) #imprime lo que este dentro del argumento
a = int(input("ingresa un primer numero: ")) #ingreso de numeros en variables
b = int(input("ingresa un segundo numero: "))
c = int(input("ingresa un tercer numero: "))

i1= max(a,b,c) #funcion que encuentra el maximo y el minimo de variables
i2= min(a,b,c)
print("tu valor mas grande es: {}".format(i1)) #impresion de resultados, el .format nos permite concatenar numeros
print("tu valor mas pequenio es: {}".format(i2)) #el format se conoce como metodo
