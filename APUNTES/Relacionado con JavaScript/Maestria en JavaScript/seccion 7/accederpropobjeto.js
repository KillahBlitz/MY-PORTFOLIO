//acceder a las porpiedades de un objeto en javascript

let persona = {
    nombre: "Juan",
    apellido: "Pérez",
    email: "luis@gmail.com",
    edad: 30,
    nombreCompleto: function() {
        return this.nombre + " " + this.apellido;
    },

}

//acceder de forma dierecta a las propiedades del objeto
console.log(persona.nombre); // Juan
console.log(persona.apellido); // Pérez

//acceder a las propiedades de un objeto de forma indirecta
console.log(persona["nombre"]); // Juan
console.log(persona["apellido"]); // Pérez

//acceder a las propiedades de un objeto con el bucle for in
for (propiedad in persona) {
    console.log(propiedad + ": " + persona[propiedad]);
    console.log(persona[propiedad]);
}