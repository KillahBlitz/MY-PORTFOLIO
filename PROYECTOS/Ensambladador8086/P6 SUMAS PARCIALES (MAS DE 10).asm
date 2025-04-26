; programa con errores, parte practica

;mov ah,01 ; linea sin error
;int 21    ; esta linea le falta es el h, fundamental para ejecutar funcion
;sub al,30h; linea sin error
;mov bl,al ; linea sin error


;mov ah,01 ; linea sin error
;int 21h   ; linea sin error
;sub al,30 ; esta linea le falta el h,que resta 30 en decimal cuando el codigo ASCII esta en hexadecimal
;mov cl, bl; esta linea mueve el registro bl a cl, cuando nosotros trabajamos en al y lo que queremos es el registro al en otro



;suma de dos numeros

mov ah, 01   ;primer dijito
int 21h     
sub al, 30h
mov bl, al 

mov ah, 02   ;Icono de suma 
mov dl, '+' 
int 21h     
            
mov ah, 01   ;segundo digito
int 21h     
sub al,30h  
add bl,al   

              
mov ah, 02   ;Icono de igual
mov dl, 3Dh 
int 21h     

add bl, 30h  ;suma de los numeros
mov ah, 02  
mov dl, bl 
int 21h




mov ah,02  ;salto de linea
mov dl,0Ah
int 21h

mov ah,02
mov dl,0Dh
int 21h 



;practica de sumas utilizando aam, podiendo imprimir numeros con decimas de dos dijitos

mov ah, 01 ;esta linea es para ingresar el primer numero
int 21h     
sub al, 30h
mov bl, al ;importante, puesto que las funciones estan en ah, perjudicando a al, movemos nuestro registro en otro, que en este caso es bl

mov ah, 02 ;icono de suma 
mov dl, '+' 
int 21h

mov ah,01 ;segundo numero ingresado
int 21h
sub al,30h
add bl,al ;aqui directamente sumo bl, a al, por lo que la suma se guarda en al


mov ah,02 ;icono de igual
mov dl,3Dh
int 21h

mov al,bl ;muevo mi registro a bl
aam     ;esta funcion nos divide los numeros en decenas y unidades para poder imprimir numeros en donde x es el resultado, tal que 0<x<100
mov bx,ax ;como expandi el tamaño del registro, ahora no usamos el registro bajo, si no el registro completo
add bx,3030h ;sumo en hexadecimal 30 unidades en cada uno

mov ah,02 ;esta funcion, recordando que es la impresion, pero como ocupamos el registro bx, primero imprimimos las decenas, que se encuentran
mov dl,bh ;en el registro alto del registro, en este caso es bh
int 21h

mov ah,02 ;al igual que la anterior, esta funcion imprime, pero en este caso el registro bajo, que son las unidades, por lo que
mov dl,bl ;imprime lo que hay en el registro  bajo, en este caso es bl
int 21h


;nota: dl se utiliza como bufer (canal), investigar el significado de bufer. 