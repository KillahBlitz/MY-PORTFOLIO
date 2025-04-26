//uso de prototype para agregar metodos y propiedades a un objeto

//declaracion de constructor de objetos tipo persona
function Persona(nombre, apellido, email, edad) {
    this.apellido = apellido;
    this.nombre = nombre;
    this.email = email;
    this.edad = edad;
    this.nombreCompleto = function() {
        return this.nombre + " " + this.apellido;
    };
}

//declaracion de un objeto
persona = new Object(); //declaracion de un objeto vacio
persona = {
    nombre,
    apellido,
    email,
    edad,
    idioma: "es",
    get lang(){
        return this.idioma.toUpperCase();
    },
    set lang(lang){
        this.idioma = lang.toUpperCase();
    },
    get nombreCompleto() {
        return this.nombre + " " + this.apellido;
    },
}

//agregar propiedades al constructor Persona
Persona.prototype.telefono = "1234567890"; //agregar propiedad telefono al constructor Persona

//instanciar un objeto
let padre = new Persona("orlando", "vargas", "orlando@gmail.com", 30);
padre.telefono = "9876543210"; //asignar valor a la propiedad telefono
console.log(padre.telefono); //llamada de la propiedad telefono

//instanciar otro objeto
let madre = new Persona("martha", "velazquez", "martha@gmail.com", 28);
madre.telefono = "1234567890"; //asignar valor a la propiedad telefono
console.log(madre.telefono); //llamada de la propiedad telefono