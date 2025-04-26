//uso de vaiables
//declaracion de variables
let nombre;
nombre = "Juan";
//declaracion de variables y asignacion de valor
console.log(nombre);

//constantes
const apellido = "Pérez";
//apellido = "García"; // Error: Assignment to constant variable
console.log(apellido);

// `var` permite declarar variables con un alcance de función o global.
// Puede ser redeclarada y reasignada, pero tiene problemas de alcance (hoisting).
var nombre1 = "Juan"; // Declaración con `var`. Puede ser redeclarada y reasignada.
console.log(nombre1); // Imprime "Juan".

// `let` permite declarar variables con un alcance de bloque (dentro de llaves `{}`).
// No puede ser redeclarada en el mismo bloque, pero sí reasignada.
let edad = 25; // Declaración con `let`. Puede ser reasignada, pero no redeclarada en el mismo bloque.
edad = 26; // Reasignación permitida.
console.log(edad); // Imprime "26".

// `const` se usa para declarar constantes, cuyo valor no puede ser reasignado.
// Tiene un alcance de bloque, como `let`, pero no permite reasignación.
const apellido1 = "Pérez"; // Declaración con `const`. No puede ser reasignada ni redeclarada.
console.log(apellido1); // Imprime "Pérez".

// apellido = "García"; // Esto generaría un error: "Assignment to constant variable".