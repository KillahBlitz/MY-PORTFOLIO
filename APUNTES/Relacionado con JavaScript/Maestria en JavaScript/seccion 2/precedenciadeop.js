//precedencia de operadores

// Este código demuestra el uso de operadores de incremento (++), decremento (--), y la precedencia de operadores en JavaScript.
// 1. Se inicializan tres variables: x, y y z.
// 2. `++x` incrementa el valor de x antes de usarlo (pre-incremento), por lo que x pasa de 5 a 6.
// 3. `y--` usa el valor actual de y (10) en la operación y luego lo decrementa (post-decremento), por lo que y pasa a ser 9 después de la operación.
// 4. La suma `++x + y--` se evalúa como 6 (nuevo valor de x) + 10 (valor actual de y antes del decremento), resultando en 16.
// 5. Finalmente, se imprimen los valores de z, x y y, que son 16, 6 y 9 respectivamente.

let x=5;
let y=10;
let z= ++x + y--; // 6 + 10--
// 6 + 9 = 15

console.log(z); // 16
console.log(x); // 6
console.log(y); // 9