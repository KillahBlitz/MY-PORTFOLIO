mov ah,01       ;valor para mitad 6
int 21h
sub al,30h


    mov bl,al
    
mov ah, 02 
mov dl, '+' 
int 21h     
       


mov ah,01      ;valor para mitad 2
int 21h
sub al,30h

    add bl,al
        mov cl,bl
        mov al,bl
    aam
    mov bx,ax
    add bx,3030h
    
    
mov ah, 02 
mov dl, '=' 
int 21h


mov ah,02
mov dl,bh
int 21h

mov ah,02
mov dl,bl
int 21h
       mov bl,cl

mov ah, 02 
mov dl, ',' 
int 21h

    sub bl,04h
    add bl,30h

    mov ah,02
    mov dl,bl
    int 21h
    

            mov ah,02
            mov dl,0Ah
            int 21h

            mov ah,02
            mov dl,0Dh
            int 21h

mov ah, 02 
mov dl, '+' 
int 21h

mov bl,cl

mov ah,01 ;valor 2 para la mitad de 10
int 21h
sub al,30h



    add al,bl
    mov cl,al
    aam
    mov bx,ax
    add bx,3030h
    
    
    
mov ah, 02 
mov dl, '=' 
int 21h

mov ah,02
mov dl,bh
int 21h

mov ah,02
mov dl,bl
int 21h

mov ah, 02 
mov dl, ',' 
int 21h

    mov al,cl
    sub al,05h
    add al,30h
    mov bl,al

mov ah,02
mov dl,bl
int 21h


            mov ah,02
            mov dl,0Ah
            int 21h

            mov ah,02
            mov dl,0Dh
            int 21h
            
mov ah, 02 
mov dl, '+' 
int 21h

mov bl,cl

mov ah,01 ;valor 4 para la mitad de 14
int 21h
sub al,30h



    add al,bl
    mov cl,al
    aam
    mov bx,ax
    add bx,3030h
    
    
    
mov ah, 02 
mov dl, '=' 
int 21h

mov ah,02
mov dl,bh
int 21h

mov ah,02
mov dl,bl
int 21h

mov ah, 02 
mov dl, ',' 
int 21h

    mov al,cl
    sub al,07h
    add al,30h
    mov bl,al

mov ah,02
mov dl,bl
int 21h


            mov ah,02
            mov dl,0Ah
            int 21h

            mov ah,02
            mov dl,0Dh
            int 21h
            
mov ah, 02 
mov dl, '+' 
int 21h

mov bl,cl

mov ah,01 ;valor 6 para la mitad de 20
int 21h
sub al,30h



    add al,bl
    aam
    mov bx,ax
    mov cx,ax
    add bx,3030h
    
    
    
mov ah, 02 
mov dl, '=' 
int 21h

mov ah,02
mov dl,bh
int 21h

mov ah,02
mov dl,bl
int 21h

mov ah, 02 
mov dl, ',' 
int 21h

    mov ax,cx
    sub ax,0100h
    mov bx,ax
    add bx,3030h

mov ah,02
mov dl,bh
int 21h

mov ah,02
mov dl,bl
int 21h          