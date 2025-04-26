.model small
.data
vacio db ' ',10,13,'$'
texto db 'hola mundo',10,13,'$'
texto2 db 'Este programa hace multiplicaciones sucesivas',10,13,'$'
texto3 db 'Ingresa el valor a:',10,13,'$'
texto4 db 'Ingresa el valor b:',10,13,'$'  
num1 db ?
num2 db 0
.code



mov ax,@data
mov ds,ax
mov dx, offset texto
mov ah, 09
int 21h

mov ah,01
int 21h
aas


;todo lo que se ha realizado hasta este momento
;.data .com y .exe se les llama directivas su sinonimo es seudoinstrucciones y seudodirectivas
;uso de cadenas
;los corchete son una direccion y siempre estan en hexadecimal y entre corchetes  [0000Dh]
;ds es segmento de dato  

;al ver la direccion de memoria vemos un arreglo de 2 arreglos, pues uno es la instruccion que esta siendo ejecutada y la consiguiente es la direccion ip que nos dice la siguiente instruccion

;parte practica, multiplicaciones sucesivas



mov ax,@data
mov ds,ax
mov dx, offset texto2
mov ah, 09
int 21h

mov ax,@data
mov ds,ax
mov dx, offset texto3
mov ah, 09
int 21h  

mov ah,01
int 21h
sub ax,3030h
mov num1, al

        mov ax,@data
        mov ds,ax
        mov dx, offset vacio
        mov ah, 09
        int 21h

mov ax,@data
mov ds,ax
mov dx, offset texto4
mov ah, 09
int 21h

mov ah,01
int 21h
sub ax,3030h
mov num2, al

        mov ax,@data
        mov ds,ax
        mov dx, offset vacio
        mov ah, 09
        int 21h


mov al, num1
mul num2