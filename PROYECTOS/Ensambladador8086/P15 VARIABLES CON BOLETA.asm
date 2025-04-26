;ESTE PROGRAMA HACE LA SUMA Y MULTIPLICACION DE LOS NUMEROS DE BOLETA 2022350554 SIN LOS 0
;INGRESANDO LOS NUMEROS 22235554

;declaracion de cadenas
.model small
.data
vacio db ' ',10,13,'$'
cadena db 'PROGRAMMA QUE SUMA Y MULTIPLICA LOS NUMEROS DE UNA BOLETA SIN 0',10,13,'$'
cadena1 db 'INGRESE SUS NUMEROS DE BOLETA:',10,13,'$' 

;declaracion de mis variables
variable1 db 0
variable2 db 0
variable3 db 0
variable4 db 0
variable5 db 0
variable6 db 0
variable7 db 0
variable8 db 0


;declaracion de variables de las sumas parciales
variablesp1 db 0
variablesp2 db 0
variablesp3 db 0
variablesp4 dw 0
variablesp5 dw 0
variablesp6 dw 0
variablesp7 dw 0


;declaracion de variables de las multiplicaciones parciales
variablemp1 db 0
variablemp2 db 0
variablemp3 dw 0
variablemp4 dd 0
variablemp5 dd 0
variablemp6 dd 0
variablemp7 dd 0


.code
mov ax,@data
mov ds,ax
mov dx,offset cadena
mov ah,09
int 21h


mov ax,@data
mov ds,ax
mov dx,offset cadena1
mov ah,09
int 21h



;INGRESO DE VALORES DEL NUMERO DE LA BOLETA

mov ah,01
int 21h
aas

    mov variable1,al

mov ah,01
int 21h
aas

    mov variable2,al
    
mov ah,01
int 21h
aas

    mov variable3,al

mov ah,01
int 21h
aas

    mov variable4,al

mov ah,01
int 21h
aas

    mov variable5,al
    
mov ah,01
int 21h
aas

    mov variable6,al
    
mov ah,01
int 21h
aas

    mov variable7,al
    
mov ah,01
int 21h
aas

    mov variable8,al
 
 
 
;SUMA DE LAS VARIABLES DE FORMA PARCIAL

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX




mov al,variable1
mov bl,variable2
add al,bl
mov variablesp1,al


mov al,variablesp1
mov bl,variable3
add al,bl
mov variablesp2,al


mov al,variablesp2
mov bl,variable4
add al,bl
mov variablesp3,al


mov al,variablesp3
mov bl,variable5
add al,bl
aam
mov variablesp4,ax


mov ax,variablesp4
mov bl,variable6
add ax,bx
mov variablesp5,ax


mov ax,variablesp5
mov bl,variable7
add ax,bx
    mov bx,ax     ;cambio de decena, lo que me forzo a utilizar aam nuevamente
    xor ax,ax
    mov al,bl
    aam
    add ah,bh
mov variablesp6,ax
xor bx,bx

mov ax,variablesp6
mov bl,variable8
add ax,bx
mov variablesp7,ax



;CODIGO DE MULTIPLICACIONES PARCIALES
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX


mov al,variable1
mov bl,variable2
mul bl

mov variablemp1,al



mov al,variable3
mov bl,variablemp1
mul bl

mov variablemp2,al



mov al,variable4
mov bl,variablemp2
mul bl
mov dl,bl
aam

mov variablemp3,ax



        xor ax,ax
        xor bx,bx
mov al,variable5
mov bl,dl
mul bl
mov dx,bx
aam
                          
mov variablemp4,ax  

.exit