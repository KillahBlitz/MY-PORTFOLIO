//operadores de comparacion
let a=3, b=2, c = "3";

//comparacion de igualdad
let z = a == c; // true puesto que compara el valor y no el tipo
let z1 = a == b; // false
console.log(z); // true
console.log(z1); // false

//comparacion de igualdad estricta
let z3 = a === c; // false puesto que compara el valor y el tipo
console.log(z3); // false

//comparacion de desigualdad
let z4 = a != c; // false puesto que 3 es igual a 3
let z2 = a != b; // true puesto que 3 es diferente de 2
console.log(z4); // false
console.log(z2); // true

//comparacion de desigualdad estricta
let z5 = a !== c; // true puesto que 3 es diferente de "3"
console.log(z5); // true