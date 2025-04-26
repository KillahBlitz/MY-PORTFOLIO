//funciones tipo flecha en javascript
//declaracion de una funcion tipo expresion
let sumar = function(a, b) { return a + b; };
//declaracion de una funcion tipo flecha
const sumarfuncionflecha = (a, b) => a + b;
//declaracion de una funcion tipo flecha con un solo argumento
const cuadrado = a => a * a;
//declaracion de una funcion tipo flecha sin argumentos
const saludar = () => 'Hola Mundo!';
//declaracion de una funcion tipo flecha con un solo argumento y un solo return
const cuadrado2 = a => a * a;

resultado = sumarfuncionflecha(5, 10);
console.log(resultado); // 15