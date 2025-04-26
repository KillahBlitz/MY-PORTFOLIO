//calcular las estaciones del año
//declaracion de variables
let mes = 12;
let estacion;

//calcular la estacion del año
if ( 1 <= mes && mes <= 3 ){
    estacion = "Inverno";
}
else if ( 4 <= mes && mes <= 6 ){
    estacion = "Primavera";
}
else if ( 7 <= mes && mes <= 9 ){
    estacion = "Verano";
}
else if ( 10 <= mes && mes <= 12 ){
    estacion = "Otoño";
}
else {
    estacion = "Mes no valido";
}
//imprimir la estacion del año
console.log("La estacion del año es: " + estacion);