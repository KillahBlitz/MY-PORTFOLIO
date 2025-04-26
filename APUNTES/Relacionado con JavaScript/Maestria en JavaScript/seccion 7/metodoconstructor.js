//usar un constructor en un objeto en javascript
//meotodo constructor de objetos tipo persona
function Persona(nombre, apellido, email, edad) {
    this.apellido = apellido;
    this.nombre = nombre;
    this.email = email;
    this.edad = edad;
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
console.log(persona1); //llamada de la propiedad nombre
let persona2 = new Persona("Luis", "Pérez", "luis@gmail.com", 30);
console.log(persona2); //llamada de la propiedad nombre
let persona3 = new Persona("Pedro", "Pérez", "pedro@gmail.com", 30);
console.log(persona3); //llamada de la propiedad nombre