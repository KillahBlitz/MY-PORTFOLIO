//Operadores Lógicos
let a;
let valmin=0, valmax=10;

//Operador AND (&&) y OR (||)

//operador logico AND de la comparacion si esta dentro del rango de 0 a 10
a = 5; // Cambia el valor de a para probar diferentes casos
console.log("Ahora el valor de a es: " + a);
if (a >= valmin && a <= valmax) {
    console.log("El numero a esta dentro del rango de 0 a 10");
}else {
    console.log("El numero a no esta dentro del rango de 0 a 10");
}

a = 15; // Cambia el valor de a para probar diferentes casos
console.log("Ahora el valor de a es: " + a);
//operador logico OR de la comparacion si esta fuera del rango de 0 a 10
if (a < valmin || a > valmax) {
    console.log("El numero a no esta dentro del rango de 0 a 10");
}
else {
    console.log("El numero a esta dentro del rango de 0 a 10");
}