//tipo de dato boleano
var boleano = false;
console.log(typeof boleano); //tipo de dato booleano
console.log(boleano); //tipo de dato booleano

//funcion
//las funciones tambien son cosiderados un tipo de dato
function mifuncion() {
  console.log("Hola desde la funcion");
}
mifuncion(); //llamando a la funcion
console.log(typeof mifuncion); //tipo de dato function

//tipo de clase es una funcion
class Persona {
    constructor(nombre, apellido) {
        this.nombre = nombre;
        this.apellido = apellido;
    }
    saludar() {
        console.log("Hola soy " + this.nombre + " " + this.apellido);
    }
}

var persona1 = new Persona("Juan", "Perez");
persona1.saludar(); //Hola soy Juan Perez
console.log(typeof Persona); //tipo de dato function del objeto Persona

//tipo de dato indefinido
var indefinido; //variable sin valor
console.log(typeof indefinido); //tipo de dato undefined

//variable nula
var nula = null; //variable con valor nulo
console.log(typeof nula); //tipo de dato object (null es un objeto en js)