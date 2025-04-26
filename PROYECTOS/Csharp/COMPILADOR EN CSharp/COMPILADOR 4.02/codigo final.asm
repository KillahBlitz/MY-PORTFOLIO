macro float
mov cl, 10
mul cl
endm
 
 
macro negativo
neg ax
mov resultado,ax
mov cl, 10
mov ah,02
mov dl,'-'
int 21h
mov ax,resultado
endm
 
 
macro algoritmia99full
aam
mov bx,ax
add bx,3030h
 
mov ah,02
mov dl,bh
int 21h
mov ah,02
mov dl,bl
int 21h
endm
 
macro algoritmiadecfull
mov bx,10
div bx
mov cl,dl
aam
mov bx,ax
add bx,3030h
mov ah,02
mov dl,bh
int 21h
mov ah,02
mov dl,bl
int 21h
mov bl, cl
add bl,30h
mov ah,02
mov dl,bl
int 21h
endm
 
macro algoritmia1000full
mov bx,100
div bx
mov cl,dl
aam
mov bx,ax
add bx,3030h
mov ah,02
mov dl,bh
int 21h
mov ah,02
mov dl,bl
int 21h
mov al, cl
aam
mov bx,ax
add bx,3030h
mov ah,02
mov dl,bh
int 21h
mov ah,02
mov dl,bl
int 21h
endm
 
.model small
.data
T1 dw 0
T2 dw 0
T3 dw 0
T4 dw 0
T5 dw 0
T6 dw 0
T7 dw 0
T8 dw 0
T9 dw 0
m dw 0
 
aux dw 0
resultado dw 0
resultadodec dw 0
 
Res db 10, 13, 'RESULTADO', 10,13,'$' 
ERRORDIV db 10, 13, 'NO SE PUEDE DIVIDIR ENTRE 0', 10,13,'$' 
 
.code
mov ax, @data
mov ds,ax
mov dx, offset Res
mov ah,09h
int 21h
 
xor ax,ax
xor bx,bx
xor cx,cx
xor dx,dx
 
 
mov ax,5
 
mov bx,9
 
 
mul bx
mov T1,ax
 
mov ax,T1
mov aux,ax
 
mov bx,7
 
 
cmp bx,0000d
je errord
jnz nerrord
errord:
mov ax, @data
mov ds,ax
mov dx, offset ERRORDIV
mov ah,09h
int 21h
jmp salir
nerrord:
div bx
mov T2,ax
 
mov ax,3
 
mov bx,3
 
 
mul bx
mov T3,ax
 
mov ax,T2
mov aux,ax
 
mov bx,T3
 
 
add ax,bx
mov T4,ax
 
mov ax,1
 
mov bx,5
 
 
mul bx
mov T5,ax
 
mov ax,T4
mov aux,ax
 
mov bx,T5
 
 
sub ax,bx
mov T6,ax
 
mov ax,1
neg ax
 
mov bx,T6
 
 
mul bx
mov T7,ax
 
mov ax,1
 
mov bx,3
neg bx
 
 
mul bx
mov T8,ax
 
mov ax,T7
mov aux,ax
 
mov bx,T8
 
 
sub ax,bx
mov T9,ax
 
mov ax,T9
mov m,ax
 
mov resultado,ax
 
 
xor ax,ax
xor bx,bx
xor cx,cx
xor dx,dx
 
mov ax,resultado
cmp ax,0d
js esnegativo
jns espositivo
esnegativo:
negativo
espositivo:
xor dx,dx
cmp ax,99d
jbe algoritmia99
ja algoritmiadec
 
algoritmia99:
algoritmia99full
jmp salir
algoritmiadec:
cmp ax,999d
jbe algoritmiadec1
ja algoritmia1000
algoritmiadec1:
algoritmiadecfull
jmp salir
algoritmia1000:
algoritmia1000full
jmp salir
 
 
 
salir:
.exit
