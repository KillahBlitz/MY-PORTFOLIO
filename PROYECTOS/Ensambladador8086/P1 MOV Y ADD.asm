;clase 08 febrero 2023
; comentarios

; sintaxis de instruccion mover


;mov ax, 6; mover valores inmediatos
         ; tamaño
         ; sistemas de numeracion
         

; operando fuente y operando destino
; AX acumulador AH, AL
; BX base de BH, BL
; CX contador CH, CL
; DX datos


;mov bx,cx
;mov bx,ax
;mov bl,cl


; ejemplos

;mov ax, 45
;mov bx, 0BAh
;mov cx, 101010011b
;mov dx, 1000

;mov bx,cx ; solo se mueven si son dato del mismos bits
;mov bx,ax
;mov bl,cl       

; suma de datos

;add ax,1

;add bx, 001h 


;ejercicio

mov ax, 45
mov bx, 55
mov cx, 01Ah
mov dx, 0A1h

add ax,bx
add cx,dx

mov ax, 1010011b
mov bx, 1011b
mov cx, 50o
mov dx, 32o

add ax,bx
add cx,dx 

mov ax, 1010011b
mov bx, 1000
mov cx, 50o
mov dx, 032h

add ax,bx
add cx,dx

mov ax, 1010011001001111b
mov bx, 101001111001b
mov cx, 00101101b
mov dx, 0110b

mov ax, 4567
mov bx, 899
mov cx, 20
mov dx, 3 

mov ax, 0FFFFh
mov bx, 045Ah
mov cx, 03Eh
mov dx, 0Ch  

mov ax, 034h
mov bx, 34
mov cx, 101101111101b
mov dx, 777o

mov ax, bx
mov dx, cx