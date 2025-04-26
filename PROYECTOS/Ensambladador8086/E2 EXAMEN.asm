;ESTE PROGRAMA HACE LA SUMA Y MULTIPLICACION DE LOS NUMEROS ASIGNADOS
;INGRESANDO LOS NUMEROS 22235554

;declaracion de cadenas
.model small
.data
vacio db ' ',10,13,'$'
cadena db 'PROGRAMMA QUE SUMA Y MULTIPLICA LOS NUMEROS ASIGNADOS, SIENDO PARES SUMA Y MULTIPLICACION IMPARES',10,13,'$'
cadena0 db 'VALORES ASIGNADOS SON:',10,13,'$'
cadena1 db 'INGRESE SUS NUMEROS PARES PARA SUMAR (6, 4, 6, 4)',10,13,'$'
cadena2 db 'INGRESE SUS NUMEROS IMPARES PARA MULTIPLICAR (3, 7, 5, 3, 5, 1)',10,13,'$'
cadena3 db 'TUS SUMAS PARCIALES SON:',10,13,'$'
cadena4 db 'TUS MULTIPLICACIONES PARCIALES IMPRIMIBLES SON:',10,13,'$' 

;declaracion de mis variables
variable1 db 0
variable2 db 0
variable3 db 0
variable4 db 0
variable5 db 0
variable6 db 0
variable7 db 0
variable8 db 0
variable9 db 0
variableA db 0
variablet dd 0


;variables para impresion
    impresion1 dw 0
    impresion2 dw 0
    impresion3 dw 0
    impresion4 dw 0
    impresionm dw 0            
              
;declaracion de variables de las sumas parciales
variablesp1 db 0
variablesp2 db 0
variablesp3 db 0

;declaracion de variables de las multiplicaciones parciales
variablemp1 db 0
variablemp2 db 0
variablemp3 dd 0
variablemp4 dd 0



.code
mov ax,@data
mov ds,ax
mov dx,offset cadena
mov ah,09
int 21h



mov ax,@data
mov ds,ax
mov dx,offset cadena0
mov ah,09
int 21h



mov ax,@data
mov ds,ax
mov dx,offset cadena1
mov ah,09
int 21h



;INGRESO DE VALORES DEL NUMERO PARES

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



mov ax,@data
mov ds,ax
mov dx,offset VACIO
mov ah,09
int 21h


mov ax,@data
mov ds,ax
mov dx,offset cadena2
mov ah,09
int 21h

;INGRESO DE NUMEROS IMPARES


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
    
mov ah,01
int 21h
aas

    mov variable9,al
    
mov ah,01
int 21h
aas

    mov variableA,al
 
 
 
;SUMA DE LAS VARIABLES DE FORMA PARCIAL

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX




mov al,variable1
mov bl,variable2
add al,bl  
mov variablesp1,al
aam 
mov cx,ax
mov impresion1,cx


mov al,variablesp1
mov bl,variable3
add al,bl
mov variablesp2,al
aam 
mov cx,ax
mov impresion2,cx


mov al,variablesp2
mov bl,variable4
add al,bl
mov variablesp3,al
aam 
mov cx,ax
mov impresion3,cx
 
 
 
;INDICACIONES DE IMPRESION
mov ax,@data
mov ds,ax
mov dx,offset vacio
mov ah,09
int 21h

mov ax,@data
mov ds,ax
mov dx,offset cadena3
mov ah,09
int 21h

mov ax,@data
mov ds,ax
mov dx,offset vacio
mov ah,09
int 21h


mov cx,impresion1
add cx,3030h

mov ah,02
mov dl,ch
int 21h

mov ah,02
mov dl,cl
int 21h

XOR CX,CX

mov ax,@data
mov ds,ax
mov dx,offset vacio
mov ah,09
int 21h


 
 
mov cx,impresion2
add cx,3030h

mov ah,02
mov dl,ch
int 21h

mov ah,02
mov dl,cl
int 21h

XOR CX,CX

mov ax,@data
mov ds,ax
mov dx,offset vacio
mov ah,09
int 21h




mov cx,impresion3
add cx,3030h

mov ah,02
mov dl,ch
int 21h

mov ah,02
mov dl,cl
int 21h

XOR CX,CX

mov ax,@data
mov ds,ax
mov dx,offset vacio
mov ah,09
int 21h

XOR AX,AX
XOR BX,BX
XOR DX,DX
XOR CX,CX


;CODIGO DE MULTIPLICACION

mov al,variable5
mov bl,variable6
mul bl
mov variablemp1,al

aam
mov cx,ax
mov impresionm,cx


mov al,variable7
mov bl,variablemp1
mul bl
mov variablemp2,al


mov al,variable8
mov bl,variablemp2
mul bl
mov variablemp3,ax

XOR AX,AX
mov ax,variablemp3
mov bl,variable9
mul bx                   
mov variablemp4,ax 

NEG variablemp4
mov ax,variablemp4
mov variablet,ax




;IMPRESION DE RESULTADOS DE MULTIPLICACION
mov ax,@data
mov ds,ax
mov dx,offset vacio
mov ah,09
int 21h

mov ax,@data
mov ds,ax
mov dx,offset cadena4
mov ah,09
int 21h

mov ax,@data
mov ds,ax
mov dx,offset vacio
mov ah,09
int 21h

mov cx,impresionm
add cx,3030h

mov ah,02
mov dl,ch
int 21h

mov ah,02
mov dl,cl
int 21h

;CODIGO DE DIVISION 
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov bx,variablet
mov al  ,variablesp3

div bx
.exit  