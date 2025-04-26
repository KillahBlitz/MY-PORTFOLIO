//objetos en javascript
//declaracion de variables
let x = 10;
let nombre = "Juan";

//declaracion de un objeto, le podemos asignar varias variables y varias funciones
let persona = {
    //atributos o propiedades
    nombre: "Juan",
    apellido: "Pérez",
    email: "luis@gmail.com",
    edad: 30,
    //metodos o funciones
    nombrecompleto: function() {
        return this.nombre + " " + this.apellido; //this hace referencia al objeto persona
    },
}

console.log(persona.nombre); // accedemos a la propiedad nombre del objeto persona
console.log(persona.apellido); // accedemos a la propiedad apellido del objeto persona
console.log(persona.email); // accedemos a la propiedad email del objeto persona
console.log(persona.edad); // accedemos a la propiedad edad del objeto persona
console.log(persona); // accedemos a todo el objeto persona
console.log(persona.nombrecompleto()); // accedemos al metodo nombrecompleto del objeto persona