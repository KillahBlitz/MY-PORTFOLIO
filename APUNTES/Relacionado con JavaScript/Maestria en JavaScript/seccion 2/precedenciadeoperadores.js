//precedencia de operadores arithmeticos
let a=3, b=2, c=1, d=4;

//precedencia de operadores arithmeticos
//el programa lee de izquierda a derecha y de arriba hacia abajo
//el programa lee primero la multiplicacion y luego la suma
let z = a*b+c/d; // 3*2+1/4 = 6+.25 = 6.25
console.log(z); // 6.25
//el programa lee primero la multiplicacion o divisiob y luego la suma o resta

z = c+a*b/d; // 1+3*2/4 = 1+6/4 = 1+1.5 = 2.5
console.log(z); // 2.5

//parentesis
z = (c+a)*b/c; // (1+3)*2/1 = 4*2/1 = 8/1 = 8
console.log(z); // 8