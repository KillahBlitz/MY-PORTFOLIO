//funciones self-invoking
//funciones autoejecutables las que se ejecutan solas
//declaracion de una funcion autoejecutable
(function (a,b) {
    console.log("Hola soy una funcion autoejecutable"+ a + b);
})(4, 5);
// Explicación:
// Este código es un ejemplo de una función autoejecutable o IIFE (Immediately Invoked Function Expression).
// 1. `(function (a, b) { ... })`: Esto define una función anónima que toma dos parámetros `a` y `b`.
// 2. `console.log(...)`: Dentro de la función, se imprime un mensaje concatenando el texto con los valores de `a` y `b`.
// 3. `)(4, 5)`: Aquí se invoca inmediatamente la función, pasando los valores `4` y `5` como argumentos para `a` y `b`.
//    Esto significa que la función se ejecuta tan pronto como se define.
// 4. Resultado: En la consola se imprimirá: "Hola soy una funcion autoejecutable45".
//    Nota: No hay un espacio entre `a` y `b`, por lo que los números se concatenan directamente.