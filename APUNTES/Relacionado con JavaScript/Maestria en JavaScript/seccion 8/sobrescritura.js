//sobrescritura de metodos en javascript

//creacion de la clase padre
class Persona{
    constructor(nombre,apellido){
        this._nombre = nombre;
        this._apellido = apellido;
    }
    
    get nombre(){
        return this._nombre;
    }

    set nombre(nombre){
        this.nombre = nombre;
    }

    get apellido(){
        return this._apellido;
    }

    set apellido(apellido){
        this._apellido = apellido;
    }

    //metodo
    nombrecompleto(){
        return this._nombre + " " + this.apellido;
    }
}

//creacion de la clase hija
class empleado extends Persona{
    constructor(nombre,apellido,departamento){
        super(nombre,apellido)
        this._departamento = departamento;
    }

    get departamento(){
     return this._departamento        
    }

    set departamento(departamento){
        this._departamento = departamento
    }

    //sobre escritura del metodo
    nombrecompleto(){
        return super.nombrecompleto() + ", " + this._departamento; //aqui se aplica la sobrescritura
    }
}

//llamada del metodo desde la herencia ya sobreescrito
let persona2 = new empleado('urle', 'camacho', 'programador');
console.log(persona2.nombrecompleto());
