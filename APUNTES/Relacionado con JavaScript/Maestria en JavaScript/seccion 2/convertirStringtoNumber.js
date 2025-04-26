//convertir un string a un numero
let a = "18";

//revisar el tipo de dato
console.log(typeof a); //string

//convertir el string a un numero
//let edad = parseInt(a); //convertir a entero
let edad = Number(a); //convertir a numero

//revisar el tipo de dato
console.log(typeof edad); //number

if(edad >= 18){
    console.log("Puede votar");
}else{
    console.log("Es muy joven para votar votar");
}

//con operador ternario
let resultado = (edad >= 18) ? "Puede votar" : "Es muy joven para votar votar";
console.log(resultado);

//convertir un string a un numero decimal
let b = "18.5";
let decimal = parseFloat(b); //convertir a decimal
console.log(typeof decimal); //number

//convertir un numero a un string
let c = 18.5;
let str = c.toString(); //convertir a string
console.log(typeof str); //string