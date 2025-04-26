//atributos estaticos en javascript
class Persona{

    //atributo estatico, tambien se hereda
    static contadorpersona = 0;

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

    //metodos estaticos
    static saludar(){
        console.log("saludos desde el metodo static");
    }

    static saludar2(persona){
        console.log(persona.nombre + ' ' + persona.apellido);
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

    nombrecompleto(){
        return super.nombrecompleto() + ", " + this._departamento;
    }
}

//llamada del metodo desde la herencia ya sobreescrito
let persona2 = new empleado('urle', 'camacho', 'programador');
console.log(persona2.nombrecompleto());

//llamada del atributo estatico
console.log(Persona.contadorpersona);