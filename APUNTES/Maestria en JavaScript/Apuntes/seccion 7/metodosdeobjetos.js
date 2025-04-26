//agregar metodos al metodo constructor en javascript

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

//instancia de un objeto
let persona1 = new Persona("Juan", "Pérez", "juan@gmail.com", 30);
console.log(persona1.nombreCompleto()); //llamada del metodo nombreCompleto