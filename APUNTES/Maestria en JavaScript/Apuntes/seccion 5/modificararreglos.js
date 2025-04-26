//modificacion de elementos de un arreglo en javascript
// //declaracion de un arreglo
let autos = ['mazda', 'toyota', 'ford', 'volkswagen', 'chevrolet'];
// //modificacion de un elemento del arreglo
// //SINTAXIS
// // nombreArreglo[indice] = nuevoValor;
autos[0] = 'nissan'; //modifica el primer elemento del arreglo
autos[1] = 'honda'; //modifica el segundo elemento del arreglo
autos[2] = 'subaru'; //modifica el tercer elemento del arreglo

//aniadir un elemento al final del arreglo
// //SINTAXIS
// // nombreArreglo.push(nuevoValor);
autos.push('fiat'); //aniade el elemento fiat al final del arreglo
// //aniadir un elemento al inicio del arreglo
// //SINTAXIS
// // nombreArreglo.unshift(nuevoValor);
autos.unshift('audi'); //aniade el elemento audi al inicio del arreglo
// //aniadir un elemento en una posicion especifica del arreglo
// //SINTAXIS
// // nombreArreglo.splice(indice, 0, nuevoValor);
autos.splice(2, 0, 'mercedes'); //aniade el elemento mercedes en la posicion 2 del arreglo

//imprimir el arreglo en modo lista
for (let i = 0; i < autos.length; i++) {
    console.log((i+1) + "." + autos[i]);
}
