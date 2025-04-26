//metodo get para obtener el valor de una propiedad de un objeto en javascript

//declaracion de un objeto
let persona = {
    nombre: "Juan",
    apellido: "Pérez",
    email: "luis@gmail.com",
    edad: 30,
    nombreCompleto: function() {
        return this.nombre + " " + this.apellido;
    },
    get nombreCompletado() {
        return this.nombre + " " + this.apellido;
    },
}

//impirimir el contenido de una funcion 
console.log(persona.nombreCompleto);
//imprimir la funcion de una funcionss
console.log(persona.nombreCompleto());
//para estas complicaciones ocupanos el metodo get para obtener el valor de una propiedad de un objeto en javascript
//llamada de la propiedad nombreCompletado
console.log(persona.nombreCompletado);