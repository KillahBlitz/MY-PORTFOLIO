//sentencia de switch en javascript
let x = 2; //variable a evaluar
let dia = "lunes"; //variable a evaluar
let esVerano = true; //variable a evaluar

//Ejemplo de switch booleana
switch(esVerano) {
    case true:
        console.log("Es verano");
        break;
    case false:
        console.log("No es verano");
        break;
    default:
        console.log("No se puede determinar si es verano o no");
        break;
}

//ejemplo de switch con un numero
switch(x) {
    case 1:
        console.log("x es 1");
        break;
    case 2:
        console.log("x es 2");
        break;
    case 3:
        console.log("x es 3");
        break;
    default:
        console.log("x no es 1, 2 o 3");
        break;
}

//Ejemplo de switch con un string
switch(dia) {
    case "lunes":
        console.log("Hoy es lunes");
        break;
    case "martes":
        console.log("Hoy es martes");
        break;
    case "miercoles":
        console.log("Hoy es miercoles");
        break;
    default:
        console.log("No es lunes, martes o miercoles");
        break;
}