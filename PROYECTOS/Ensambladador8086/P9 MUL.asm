;multiplicacion

mov al, 5 ;aqui mi registro debe estar en al donde se multiplicara
mov bl, 3 ;el numero que se multiplicara con al 
mul bl    ;mul es la instruccion, al por defecto al es el que multipkica a cualquier registro, en este caso bl

;NOTA hay que mover el registro al porque ahi se guardara el resultado y asi no lo perdemos


;EJEMPLO

mov ah,01
int 21h
sub al,30h

        mov bl,al
    

mov ah,02
mov dl,'*'
int 21h

mov ah,01
int 21h
sub al,30h  

        mov cl,al 

mov ah,02
mov dl,'='
int 21h


        mov al,cl
        mul bl
        
add al,30h        

mov ah,02
mov dl,al
int 21h

;parte practica, suma, resta, multiplicacion


;suma

mov ah,02
mov dl,0Ah
int 21h

mov ah,02
mov dl,0Dh
int 21h


mov ah,01
int 21h
sub al,30h
        mov bl,al
        
 
mov ah,02
mov dl,'+'
int 21h

mov ah,01
int 21h
sub al,30h
        mov cl,al
        add bl,cl
        mov cl,bl
                mov al,bl
                aam
                mov bx,ax
                add bx,3030h
        
mov ah,02
mov dl,'='
int 21h

mov ah,02
mov dl,bh
int 21h

mov ah,02
mov dl,bl
int 21h


;en mi programa vamos a ocupar el resultado anterior para seguir las operaciones

;resta, la resta el resultado debe ser menor que diez, entonces siendo x el resultado x<10

mov ah,02
mov dl,'-'
int 21h


mov ah,01
int 21h
sub al,30h
        
        sub cl,al
        mov al,cl
        aam
        mov bx,ax
        add bx,3030h


mov ah,02
mov dl,'='
int 21h

mov ah,02
mov dl,bh
int 21h

mov ah,02
mov dl,bl
int 21h


;limpiamos los registros

mov ax,0000h
mov bx,0000h
mov dx,0000h


;multiplicacion

mov ah,02
mov dl,'*'
int 21h

mov ah,01
int 21h
sub al,30h
       
        mov bl,al

mov ah,02
mov dl,'='
int 21h

            mov al,bl
        mul cl
        mov cl,al
            mov bl,al
        aam
        mov cx,ax
        add cx,3030h
        
        
mov ah,02
mov dl,ch
int 21h

mov ah,02
mov dl,cl
int 21h 

;limpiamos los registros

mov ax,0000h
mov cx,0000h
mov dx,0000h


;dos restas

mov ah,02
int 21h
sub al,30h

        mov       