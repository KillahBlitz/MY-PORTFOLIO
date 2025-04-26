mov ah,01 ;Ingresa el primer numero
int 21h
sub al,30h
mov bl,al

mov ah,01 ;Ingresa el segundo numero 
int 21h
sub al,30h
add bl,al ;primera suma 
mov ch,bl
mov al,bl
aam


mov bx,ax
add bx,3030h

mov ah,02
mov dl,bh
int 21h

mov ah,02
mov dl,bl
int 21h

mov ah,01
int 21h
sub al,30h

add ch,al
mov dh,ch

mov al,ch
aam  

mov bx,ax
add bx,3030h

mov ah,02
mov dl,bh
int 21h

mov ah,02
mov dl,bl
add dl,30h
int 21h

