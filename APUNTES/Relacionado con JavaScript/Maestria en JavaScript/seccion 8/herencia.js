//la herencia en objetos en javascript

//creacion de la clase padre
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

    //metodo get para el apellido
    get apellido(){
        return this._apellido;
    }

    set apellido(apellido){
        this._apellido = apellido;
    }
}

//creacion de la clase hija
class empleado extends Persona{ //extends es una palabra reservada para indicar la herencia de la clase
    constructor(nombre,apellido,departamento){
        super(nombre,apellido) //es para ocupar el codigo del constructor de la clase padre
        this._departamento = departamento;
    }

    get departamento(){
     return this._departamento        
    }

    set departamento(departamento){
        this._departamento = departamento
    }
}

//instancia de objetos
//instancia de la clase padre
let persona1 = new Persona('luisa', 'aguilar');
//instancia de clase hija
let persona2 = new empleado('Angel', 'Camacho', 'Desarrollo');

console.log(persona1);
console.log(persona2);
//se pueden usar sus atributos y metodos de la clase padre en la clase hija