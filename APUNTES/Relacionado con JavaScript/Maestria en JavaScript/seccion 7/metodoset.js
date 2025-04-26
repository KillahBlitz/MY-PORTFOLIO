//metodo set para modificar el valor de una propiedad de un objeto en javascript

//declaracion de un objeto
let persona = {
    nombre: "Juan",
    apellido: "Pérez",
    email: "luis@gmail.com",
    edad: 30,
    idioma: "es",
    get lang(){
        return this.idioma.toUpperCase(); //tuUperCase() convierte el texto a mayusculas
    },
    //metodo set para modificar el valor de una propiedad de un objeto en javascript
    set lang(lang){
        this.idioma = lang.toUpperCase(); //toUpperCase() convierte el texto a mayusculas
    },
    get nombreCompleto() {
        return this.nombre + " " + this.apellido;
    },
}

//llamada de lang
console.log(persona.lang); //llamada de la propiedad lang
//modificacion de la propiedad lang
persona.lang = "en"; //modificacion de la propiedad lang