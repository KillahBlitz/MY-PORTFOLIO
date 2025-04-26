mov al,9
mov bl,9
mul bl
mul bl
mul bx
mul bx
mul bx


mov al,5
mov bl,5
mul bl;25  19 en hexadecimal
mul bl;125 7D en hexadecimal
mul bx;625 271 en hexadecimal, aqui se daña porque el registro es de 8 bits y pasaa a ser de 12 bits
;por lo que pasa en bx
mul bx;3125 C35 en hexadecimal
mul bx;15,625? 3D09 en hexadecimal ahora estamos cerca de superar el limite
mul bx;llegamos al limite de los bits en ax, por lo que el resultado mueve su resto a dl, resultado en hexadecimal, 1 312D


mov ax, 0000h
mov bx, 0000h
mov cx, 0000h
mov dx, 0000h


;multiplicaciones del numero 7 hasta que llenemos los 16 bits del registro ax


mov al, 7
mov bl, 7
mul bl ;49 Decimal y 31 en hexadecimal 
mul bx ;343 Decimal y 157 en hexadecimal, ya se pasa a el registro bx
mul bx ;2401 Decimal y 961 en hexadecimal
mul bx ;16,807 Decimal y 41A7 en hexadecimal cerca de sobrepasar los 16 bits
mul bx ;117,649 Decimal y 1 CB91 en hexadecimal, ahora ya pasa al registro dl

mov ax, 0000h
mov bx, 0000h
mov cx, 0000h
mov dx, 0000h

mov ah,01
int 21h
aas
mov bl,al

mov ah,01
int 21h
aas


mul bl ;el resultado quedara en al

mov bl,al ;respaldo

mov ah,01
int 21h
aas

mul bl

mov bl,al

mov ah,01
int 21h
aas

mul bl

mov bx,ax

mov ah,01
int 21h
aas

mul bx

mov bx,ax