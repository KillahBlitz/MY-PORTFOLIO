//declaracion y uso de funciones en javascript
//las funciones son bloques de codigo que se pueden reutilizar
//declaracion de la funcion
function miPrimeraFuncion(a, b){ //declaracion de la funcion, en () se pueden poner los argumentos o parametros
 console.log("suma: " + (a + b)); //suma de los argumentos a y b
}

//llamada a la funcion
miPrimeraFuncion(5, 10); //llamada a la funcion, se le pasan los argumentos 5 y 10
miPrimeraFuncion(20, 30); //llamada a la funcion, se le pasan los argumentos 20 y 30

//uso de la palabra reservada return
function miSegundaFuncion(a, b){ //declaracion de la funcion, en () se pueden poner los argumentos o parametros
    return a + b; //suma de los argumentos a y b y devuelve el resultado
}

//llamada a la funcion
z = miSegundaFuncion(5, 10); //llamada a la funcion, se le pasan los argumentos 5 y 10 y se guarda el resultado en la variable b
console.log("suma: " + z); //muestra el resultado de la suma en la consola