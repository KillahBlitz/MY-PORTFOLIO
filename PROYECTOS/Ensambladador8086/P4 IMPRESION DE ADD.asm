mov al, 1100b      ;registro low
mov bl, 1010b      ;registro bajo de b
mov ah, 5          ;registro high
mov bh, 5          ;registro alto en b
mov cl, 15h        ;registro en hexadecimal, sin el 0 no se hace f, puesto que esta en hexadecimal
mov dl, 0abh       ;registro low en hexadecimal con 0
mov ch, 0111110b   ;registro high en c en binario
mov dh, 1010b      ;registro high en d en binario

add al, bl
add bl, al
add ah, bh
add bh, dh
add bh, bh


add ah, ah
add dh, ch
add ch, dh
add dh, dh 




;primeros pasos, introduccion a lenguaje ensamblador


mov al,9

add al,9
add al,9
add al,9
add al,8 
add al,7
add al,6
add al,5
add al,4
add al,3
add al,2
add al,1
add al,0



mov ah, 01 ;funciones van en ah, funcion 01 es ingresar un caracter, siendo mi primer valor 
int 21h ;en el registro AL devuelve el valor en hechadecimal del numero ingresado 
sub al, 30h ;resta de los 30 en hexadecimal

mov bl,al ; asi guardo el valor hexadecimal del primer dijito moviendolo de al a bl


mov ah, 01 ;vuelvo a repetir la funcion de ingresar un numero siendo mi segundo valor 
int 21h
sub al, 30h

mov bh, al

;para poder sumar en decimal, debemos restarle al codigo ASCII 30 puesto a su poscicion del 1 al 9 

add bl,bh ;primera suma


mov ah, 01 ;tercer valor 
int 21h
sub al, 30h 


add bl, al ;segunda suma
add cl, bl