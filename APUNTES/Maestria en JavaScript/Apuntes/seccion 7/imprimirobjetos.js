//formas de imprimir un objeto en javascript

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

//concatenar cada valor de cada propiedad del objeto
console.log("Nombre: " + persona.nombre + ", Apellido: " + persona.apellido + ", Email: " + persona.email + ", Edad: " + persona.edad);
//concatenar cada valor de cada propiedad del objeto con un for in
for (propiedad in persona) {
    console.log(propiedad + ": " + persona[propiedad]);
}
//usando el metodo objet.values() para obtener un array con los valores del objeto
let personaArray = Object.values(persona);
console.log(personaArray);
//usando el metodo JSON.strningify() para convertir el objeto en un string
let personaString = JSON.stringify(persona);
console.log(personaString);
