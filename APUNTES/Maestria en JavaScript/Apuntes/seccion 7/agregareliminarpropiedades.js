//como agregar o eliminar propiedades de un objeto en  javascript

//declaracion de un objeto
let persona = {
    nombre: "Juan",
    apellido: "Pérez",
    email: "luis@gmail.com",
    edad: 30,
    nombreCompleto: function() {
        return this.nombre + " " + this.apellido;
    },

}

//agregar una nueva propiedad al objeto
persona.telefono = "5587957504";
console.log(persona); // { nombre: 'Juan', apellido: 'Pérez', email, telefono '

//eliminar una propiedad del objeto
delete persona.telefono;
console.log(persona); // { nombre: 'Juan', apellido: 'Pérez', email'

//eliminar funcion del objeto
delete persona.nombreCompleto;
console.log(persona); // { nombre: 'Juan', apellido: 'Pérez', email'