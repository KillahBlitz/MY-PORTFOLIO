mov ah, 01  ;activando la funcion 01, el introducir un numero
int 21h     ;esta termina la funcion
sub al, 30h ;como los numeros estan en hexadecimal, resto 30 al numero original para poder sumar en decimal (codigo ASCII)

mov ah, 02  ;activo la funcion 02, que me imprime cualquier numero o signo que yo quisiese
mov dl, '+' ;anado el simbolo suma
int 21h     ;esta termina la funcion
            
mov ah, 01  ;activo la funcion 01
int 21h     ;termino la funcion
sub al,30h  ;ingreso otro numero que queremos sumar para que se sumen en decimal
add bl,al   ;la suma de los dos numeros


mov ah, 02  ;inicio la funcion 02
mov dl, 3Dh ;agrego el simbolo = con su codigo ASCII
int 21h     ;termino la funcion

add bl, 30h ;aqui lo que quiero es imprimir el resultado decimal, por lo que sumo 30 hexadecimal para que me imprima el resultado
;le sumo a bl porque ahi se guardo el resultado de mi suma, por lo que ahi esta el resultado decimal
mov ah, 02  ;aqui inicio la funcion 02
mov dl, bl  ;muevo el registro dl a bl y lo imprima
int 21h     ;termino la funcion

                                                                                                                             
                                                                                                                             
;nota: este programa sirve para numeros menores que 10 y mayores a 0 en el resultado, por lo que, si x es el resultado 0<x<10 


;parte practica


mov ah,02
mov dl,0Ah
int 21h

mov ah,02
mov dl,0Dh
int 21h 




;aam, es una instruccion que divide a un numero hexadecimal a decimal por sus unidades y decenas, si lo ponemos en ah, lo movemos a bx para
;que no haya conflicto en ah con las instrucciones


mov al,0fh
aam
mov bx,ax
add bx,3030h

mov ah,02
mov dl,bh
int 21h

mov ah,02
mov dl,bl
int 21h

;aam solo funciona cuando el numero que quiero separar esta en el registro al