//recorrer arreglos en javascript
//declaracion de un arreglo
let colores = new Array('red', 'pink', 'yellow', 14);
const autos = ['mazda', 'toyota', 'ford', 2023, true];
const autos2 = Array.of('mazda', 'toyota', 'ford', 2023, true);

//acceso por indice
//SINTAXIS
// nombreArreglo[indice]
console.log(autos[0]); //mazda
console.log(autos[1]); //toyota
console.log(autos[2]); //ford

//metodo for
for (let i = 0; i < autos2.length; i++) {
    console.log(autos2[i]);
}

//metodo forEach
//SINTAXIS
// nombreArreglo.forEach(function(elemento, indice, arreglo){ //codigo a ejecutar });
colores.forEach(function(elemento, indice, arreglo) {
    console.log(`Elemento: ${elemento}, Indice: ${indice}, Arreglo: ${arreglo}`);
});
