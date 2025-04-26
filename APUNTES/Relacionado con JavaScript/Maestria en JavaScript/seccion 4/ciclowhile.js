//ciclo while en javascript
let i = 0; //inicializamos la variable i en 0
let n = 10; //inicializamos la variable n en 10
let dia = "viernes"; //inicializamos la variable dia en "lunes"
let dias = ["lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo"]; //inicializamos la variable dias en un array con los dias de la semana
let j = 0; //inicializamos la variable j en 0

//ejemplo de ciclo while
while(i < n) { //mientras i sea menor que n
    console.log("El valor de i es: " + i); //imprimimos el valor de i
    i++; //incrementamos el valor de i en 1
}

//ejemplo de ciclo while con un string
while(j < dias.length) { //mientras j sea menor que la longitud del array dias
    if(dia === dias[j]) { //si dia es igual a dias[j]
        console.log("Hoy es " + dias[j]); //imprimimos el dia
        break; //salimos del ciclo
    }
    j++; //incrementamos el valor de j en 1
}