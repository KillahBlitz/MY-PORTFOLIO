//explicacion de la sentencia break, este se utiliza para salir de un bucle o switch, basicamente terminar un proceso

//se puede utilizar en un bucle for, while o do while, y en un switch

for(i=0; i<10; i++){
    if(i==5){
        console.log("se ha terminado el bucle"); //imprime un mensaje cuando i es igual a 5
        break; //cuando i es igual a 5, se termina el bucle
    }
    console.log(i); //imprime los numeros del 0 al 4
}