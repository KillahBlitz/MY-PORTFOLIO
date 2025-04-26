//metodos get y set en clases en javascript

//creacion de la clase
class Persona{
    constructor(nombre,apellido){
        this._nombre = nombre;
        this._apellido = apellido;
    }
    
    //metodo get para el nombre
    get nombre(){
        return this._nombre;
    }

    //metodo set para el nombre
    set nombre(nombre){
        this.nombre = nombre;
    }
}


//instancia de objeto
let persona1 = new Persona('luis','restrepo');
console.log(persona1.nombre); //aqui invocamos el metodo get nombre

//invocamos el metodo set nombre
persona1.nombre = 'Juan';
console.log(persona1.nombre);