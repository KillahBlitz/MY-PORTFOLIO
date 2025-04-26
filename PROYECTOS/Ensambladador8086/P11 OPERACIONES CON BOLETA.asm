;suma, multiplicacion y division de mi boleta

;BOLETA  2022350554
;NOTA: me salto los 0 pq la multiplicacion de 0 da 0 y el programa deja de tener sentido


;SUMA


;Resultado debe dar 2
mov ah,01
int 21h
aas
    mov bl,al
    
;Resultado debe dar 4
mov ah,01
int 21h
aas

    add bl,al

;Resultado debe dar 6
mov ah,01
int 21h
aas

    add bl,al

;Resultado debe dar 9
mov ah,01
int 21h
aas

    add bl,al

;Resultado debe dar 14   
mov ah,01
int 21h
aas

    add bl,al

;Resultado debe dar 19
mov ah,01
int 21h
aas

    add bl,al

;Resultado debe dar 24
mov ah,01
int 21h
sub al, 30h

    add bl,al

;Resultado debe dar 28
mov ah,01
int 21h
aas

    add bl,al
    
    
    
    
;IMPRESION RESULTADO DE MI SUMA

        mov ah,02
        mov dl,0Ah
        int 21h

        mov ah,02
        mov dl,0Dh
        int 21h 


mov cl,bl
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


        mov ah,02
        mov dl,0Ah
        int 21h

        mov ah,02
        mov dl,0Dh
        int 21h 


;MULTIPLICACION

mov bx,0000h

;Resultado debe dar 2
mov ah,01
int 21h
aas
    mov bl,al


;Resultado debe dar 4
mov ah,01
int 21h
aas

    mul bl
    mov bl,al

    
;Resultado debe dar 8
mov ah,01
int 21h
aas

    mul bl
    mov bl,al
    
    
;Resultado debe dar 24
mov ah,01
int 21h
aas

    mul bl
    mov bl,al


;Resultado debe dar 120    
mov ah,01
int 21h
aas

    mov ah,00h
    mul bx
    mov bx,ax


;Resultado debe dar 600    
mov ah,01
int 21h
aas

    mov ah,00h
    mul bx
    mov bx,ax
    
    
;Resultado debe dar 3000    
mov ah,01
int 21h
aas

    mov ah,00h
    mul bx
    mov bx,ax


;Resultado debe dar 12000    
mov ah,01
int 21h
aas

    mov ah,00h
    mul bx
    mov bx,ax

;la impresion no es posible con un numero tan grande
mov bx,ax

;SOLO MOSTRARE MI RESULTADO QUE ME DIO

        mov ah,02
        mov dl,0Ah
        int 21h

        mov ah,02
        mov dl,0Dh
        int 21h 


mov ah,02
mov dl,'1'
int 21h

mov ah,02
mov dl,'2'
int 21h

mov ah,02
mov dl,'0'
int 21h

mov ah,02
mov dl,'0'
int 21h

mov ah,02
mov dl,'0'
int 21h

mov ax,bx
mov bx, 0000h
mov bl,cl

div bl                          