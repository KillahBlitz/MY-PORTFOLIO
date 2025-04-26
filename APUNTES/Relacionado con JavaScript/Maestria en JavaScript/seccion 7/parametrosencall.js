//pasar parametros a una funcion utlizando call

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
    nombreCompleto: function(profesion, telefono) {
        return this.nombre + " " + this.apellido + " " + profesion + " " + telefono;
    },
}
//otro objeto declarado
let persona2 = new Object(); //declaracion de un objeto vacio
persona2 = {
    nombre: "orlando",
    apellido: "vargas",
}
//la funcion call funciona para llamar a un metodo de un objeto y asignar el contexto de otro objeto, es un tipo de herencia

//llamada de la funcion
console.log(persona.nombreCompleto("doctor", "555")); //llamada de la funcion nombreCompleto del objeto persona, el contexto es el objeto persona
console.log(persona.nombreCompleto.call(persona2, "ingeniero", "888")); //llamada de la funcion nombreCompleto del objeto persona2, el contexto es el objeto persona