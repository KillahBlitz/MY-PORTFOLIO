//las clases en javascript

//creacion de una clase
class Persona{
    constructor(nombre, apellido){
        this.nombre = nombre;
        this.apellido = apellido;
    }
}

//instanciar una clase 
//creacion de objetos
let persona1 = new Persona('Luis','Garcia');
console.log(persona1);
//se pueden crear varios objetos de acuerdo a la clase que hay
let persona2 = new Persona('maria', 'restrepo');
console.log(persona2);