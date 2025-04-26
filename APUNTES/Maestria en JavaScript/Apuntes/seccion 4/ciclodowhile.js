//explicacion del ciclo do while en javascript

// El ciclo do while ejecuta el bloque de código una vez y luego verifica la condición. Si la condición es verdadera, el bloque de código se ejecuta nuevamente. Este proceso se repite hasta que la condición sea falsa.
// La sintaxis es la siguiente:
// do {
//     // bloque de código a ejecutar
// } while (condición);
// En este ejemplo, el ciclo do while se utiliza para mostrar los números del 1 al 5 en la consola.

let i = 1; // Inicializamos la variable i en 1

do {
    console.log(i); // Mostramos el valor de i en la consola
    i++; // Incrementamos i en 1
}
while (i <= 5); // La condición es que i sea menor o igual a 5
// En este caso, el ciclo se ejecutará 5 veces, mostrando los números del 1 al 5 en la consola. Una vez que i sea mayor que 5, el ciclo se detendrá y no se ejecutará más.
// En resumen, el ciclo do while es útil cuando queremos asegurarnos de que el bloque de código se ejecute al menos una vez, independientemente de la condición inicial.