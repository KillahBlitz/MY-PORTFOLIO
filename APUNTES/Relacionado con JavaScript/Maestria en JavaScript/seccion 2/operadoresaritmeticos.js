//opeardores aritmeticos
//declaracion de variables
let a = 3, b = 2;
let z = a + b; //suma
console.log("La suma de " + a + " + " + b + " es: " + z);
let x = a - b; //resta
console.log("La resta de " + a + " - " + b + " es: " + x);
let y = a * b; //multiplicacion
console.log("La multiplicacion de " + a + " * " + b + " es: " + y);
let w = a / b; //division
console.log("La division de " + a + " / " + b + " es: " + w);
let m = a % b; //modulo
console.log("El modulo de " + a + " % " + b + " es: " + m);
let p = a ** b; //exponente
console.log("El exponente de " + a + " ** " + b + " es: " + p);

//modos de incremento y decremento
//preincremento
let i = ++a; //incremento
console.log("El incremento de ++" + (a-1) + " es: " + i + " pero ambos valores son iguales");
//predecremento
let j = --a; //decremento
console.log("El decremento de --" + (a-1) + " es: " + j + " pero ambos valores son iguales");


let q = a++; //incremento
console.log("El incremento de " + q + "++ es: " + a + " pero q tiene el valor orginal y a es el que se incremento");
let r = a--; //decremento
console.log("El decremento de " + r + "-- es: " + a + " pero q tiene el valor orginal y a es el que se incremento");
a++; //incremento simple
a--; //decremento simple
