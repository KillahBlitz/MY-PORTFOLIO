;INICIO DEL PROGRAMA, DECLARACION DE CADENAS
.model small
.data


;CADENAS DE TEXTO
cadena00 db 'ESTE PROGRAMA REALIZA LA DETERMINANTE DE UNA MATRIZ 3X3', 10,13,'$'
cadena01 db 'INGRESA LOS NUMEROS QUE DESEAS DETERMINAR', 10,13,'$'
cadena02 db 10,13,'NO SE INGRESO UN NUMERO, FAVOR DE VOLVER A INTENTARLO', 10,13,'$'
cadena03 db 10,13,'LA MATRIZ ES:', 10,13,'$'
cadena04 db 10,13,'PARA PODER REALIZAR LA DETERMINANTE ES:', 10,13,'$'
cadena05 db 10,13,'DE TAL FORMA QUE LAS MULTIPLICACIONES SON LAS SIGUIENTES:', 10,13,'$'
cadena06 db 10,13,'REDUCIENDO:', 10,13,'$'





;CADENAS DE INGRESO DE DATOS
cadena0 db 10,13,'Ingresa el dato 11:', 10,13,'$'
cadena1 db 10,13,'Ingresa el dato 12:', 10,13,'$'
cadena2 db 10,13,'Ingresa el dato 13:', 10,13,'$'
cadena3 db 10,13,'Ingresa el dato 21:', 10,13,'$'
cadena4 db 10,13,'Ingresa el dato 22:', 10,13,'$'
cadena5 db 10,13,'Ingresa el dato 23:', 10,13,'$'
cadena6 db 10,13,'Ingresa el dato 31:', 10,13,'$'
cadena7 db 10,13,'Ingresa el dato 32:', 10,13,'$'
cadena8 db 10,13,'Ingresa el dato 33:', 10,13,'$'


var11 db 0
var12 db 0 
var13 db 0
var21 db 0
var22 db 0
var23 db 0
var31 db 0
var32 db 0
var33 db 0 

varm1 dd 0
varm2 dd 0
varm3 dd 0
varm4 dd 0
varm5 dd 0
varm6 dd 0

varf1 dd 0
varf2 dd 0
varfinal dd 0



;PRINCIPIO DEL PROGRAMA, INDICA QUE HACE EL PROGRAMA
.code
mov ax, @data
mov ds,ax
mov dx, offset cadena00
mov ah,09h
int 21h


mov ax, @data
mov ds,ax
mov dx, offset cadena01
mov ah,09h
int 21h

;INGRESANDO LOS DATOS











;DATO 11
    salto0:
mov ax, @data
mov ds,ax
mov dx, offset cadena0
mov ah,09h
int 21h

mov ah,01
int 21h
sub ax,3030h


        cmp al,10d
        ja mayor0
        jb menor0


    mayor0:
    
mov ax, @data
mov ds,ax
mov dx, offset cadena02
mov ah,09h
int 21h
jmp salto0


    menor0:

add ax,3030h    
mov var11,al
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX
jmp ingreso0


;DATO 12
    ingreso0:
    salto1:
mov ax, @data
mov ds,ax
mov dx, offset cadena1
mov ah,09h
int 21h

mov ah,01
int 21h
sub ax,3030h


        cmp al,10d
        ja mayor1
        jb menor1


    mayor1:
    
mov ax, @data
mov ds,ax
mov dx, offset cadena02
mov ah,09h
int 21h
jmp salto1


    menor1:

add ax,3030h    
mov var12,al
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX
jmp ingreso1


;DATO 13
    ingreso1:
    salto2:
mov ax, @data
mov ds,ax
mov dx, offset cadena2
mov ah,09h
int 21h

mov ah,01
int 21h
sub ax,3030h


        cmp al,10d
        ja mayor2
        jb menor2


    mayor2:

mov ax, @data
mov ds,ax
mov dx, offset cadena02
mov ah,09h
int 21h
jmp salto2


    menor2:

add ax,3030h
mov var13,al
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX
jmp ingreso2


;DATO 21
    ingreso2:
    salto3:
mov ax, @data
mov ds,ax
mov dx, offset cadena3
mov ah,09h
int 21h

mov ah,01
int 21h
sub ax,3030h


        cmp al,10d
        ja mayor3
        jb menor3


    mayor3:

mov ax, @data
mov ds,ax
mov dx, offset cadena02
mov ah,09h
int 21h
jmp salto3


    menor3:

add ax,3030h
mov var21,al
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX
jmp ingreso3



;DATO 22
    ingreso3:
    salto4:
mov ax, @data
mov ds,ax
mov dx, offset cadena4
mov ah,09h
int 21h

mov ah,01
int 21h
sub ax,3030h


        cmp al,10d
        ja mayor4
        jb menor4


    mayor4:

mov ax, @data
mov ds,ax
mov dx, offset cadena02
mov ah,09h
int 21h
jmp salto4


    menor4:

add ax,3030h
mov var22,al
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX
jmp ingreso4


;DATO 23
    ingreso4:
    salto5:
mov ax, @data
mov ds,ax
mov dx, offset cadena5
mov ah,09h
int 21h

mov ah,01
int 21h
sub ax,3030h


        cmp al,10d
        ja mayor5
        jb menor5


    mayor5:

mov ax, @data
mov ds,ax
mov dx, offset cadena02
mov ah,09h
int 21h
jmp salto5


    menor5:

add ax,3030h
mov var23,al
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX
jmp ingreso5


;DATO 31
    ingreso5:
    salto6:
mov ax, @data
mov ds,ax
mov dx, offset cadena6
mov ah,09h
int 21h

mov ah,01
int 21h
sub ax,3030h


        cmp al,10d
        ja mayor6
        jb menor6


    mayor6:

mov ax, @data
mov ds,ax
mov dx, offset cadena02
mov ah,09h
int 21h
jmp salto6


    menor6:

add ax,3030h
mov var31,al
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX
jmp ingreso6


;DATO 32
    ingreso6:
    salto7:
mov ax, @data
mov ds,ax
mov dx, offset cadena7
mov ah,09h
int 21h

mov ah,01
int 21h
sub ax,3030h


        cmp al,10d
        ja mayor7
        jb menor7


    mayor7:

mov ax, @data
mov ds,ax
mov dx, offset cadena02
mov ah,09h
int 21h
jmp salto7


    menor7:

add ax,3030h
mov var32,al
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX
jmp ingreso7


;DATO 32
    ingreso7:
    salto8:
mov ax, @data
mov ds,ax
mov dx, offset cadena8
mov ah,09h
int 21h

mov ah,01
int 21h
sub ax,3030h


        cmp al,10d
        ja mayor8
        jb menor8


    mayor8:

mov ax, @data
mov ds,ax
mov dx, offset cadena02
mov ah,09h
int 21h
jmp salto8


    menor8:

add ax,3030h
mov var33,al
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX
jmp continuacion0

    







;IMPRESION DE LA MATRIZ, COMO ES QUE ESTAN ORDENADOS LOS DATOS.    
    continuacion0:
    
    
        mov ax, @data
        mov ds,ax
        mov dx, offset cadena03
        mov ah,09h
        int 21h
    
mov ah,02
mov dl,'|'
int 21h

 
 
mov ah,02
mov dl,var11
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,var12
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,var13
int 21h




mov ah,02
mov dl,'|'
int 21h



        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        


mov ah,02
mov dl,'|'
int 21h

              
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'|'
int 21h
  


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 

mov ah,02
mov dl,'|'
int 21h
        

mov ah,02
mov dl,var21
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,var22
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,var23
int 21h
       

mov ah,02
mov dl,'|'
int 21h


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 

mov ah,02
mov dl,'|'
int 21h
        
              
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,' '
int 21h
       

mov ah,02
mov dl,'|'
int 21h


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        

mov ah,02
mov dl,'|'
int 21h

mov ah,02
mov dl,var31
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,var32
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,var33
int 21h 


mov ah,02
mov dl,'|'
int 21h


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
;IMPRESION DE COMO SE SACA LA DETERMINANTE DE LA MATRIZ POR METODO DE SARRUS

mov ax, @data
mov ds,ax
mov dx, offset cadena04
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        

mov ah,02
mov dl,'|'
int 21h

 
 
mov ah,02
mov dl,var11
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,var12
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,var13
int 21h




mov ah,02
mov dl,'|'
int 21h



        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        


mov ah,02
mov dl,'|'
int 21h

              
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'\'
int 21h
 
 
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'|'
int 21h
  


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 

mov ah,02
mov dl,'|'
int 21h
        

mov ah,02
mov dl,var21
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,var22
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,var23
int 21h
       

mov ah,02
mov dl,'|'
int 21h


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 

mov ah,02
mov dl,'|'
int 21h
        
              
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'\'
int 21h
 
 
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'\'
int 21h


mov ah,02
mov dl,' '
int 21h
       

mov ah,02
mov dl,'|'
int 21h


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        

mov ah,02
mov dl,'|'
int 21h

mov ah,02
mov dl,var31
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,var32
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,var33
int 21h 


mov ah,02
mov dl,'|'
int 21h


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        


mov ah,02
mov dl,'|'
int 21h

              
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'\'
int 21h
 
 
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'\'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'|'
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        


mov ah,02
mov dl,'|'
int 21h

              
mov ah,02
mov dl,var11
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,var12
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,var13
int 21h


mov ah,02
mov dl,'|'
int 21h
  
  
        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        


mov ah,02
mov dl,'|'
int 21h

              
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'\'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'|'
int 21h
 
 
        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        


mov ah,02
mov dl,'|'
int 21h

              
mov ah,02
mov dl,var21
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,var22
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,var23
int 21h


mov ah,02
mov dl,'|'
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        




 
  




















mov ah,02
mov dl,'|'
int 21h

 
 
mov ah,02
mov dl,var11
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,var12
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,var13
int 21h




mov ah,02
mov dl,'|'
int 21h



        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        


mov ah,02
mov dl,'|'
int 21h

              
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'/'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'|'
int 21h
  


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 

mov ah,02
mov dl,'|'
int 21h
        

mov ah,02
mov dl,var21
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,var22
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,var23
int 21h
       

mov ah,02
mov dl,'|'
int 21h


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 

mov ah,02
mov dl,'|'
int 21h
        
              
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'/'
int 21h
 
 
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'/'
int 21h


mov ah,02
mov dl,' '
int 21h
       

mov ah,02
mov dl,'|'
int 21h


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        

mov ah,02
mov dl,'|'
int 21h

mov ah,02
mov dl,var31
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,var32
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,var33
int 21h 


mov ah,02
mov dl,'|'
int 21h


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        


mov ah,02
mov dl,'|'
int 21h

              
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'/'
int 21h
 
 
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'/'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'|'
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        


mov ah,02
mov dl,'|'
int 21h

              
mov ah,02
mov dl,var11
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,var12
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,var13
int 21h


mov ah,02
mov dl,'|'
int 21h
  
  
        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        


mov ah,02
mov dl,'|'
int 21h

              
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'/'
int 21h
 
 
mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'|'
int 21h
 
 
        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        


mov ah,02
mov dl,'|'
int 21h

              
mov ah,02
mov dl,var21
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,var22
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,var23
int 21h


mov ah,02
mov dl,'|'
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
        
;LA REPRESENTACION ARITMETICA DE LA OPERACION
mov ax, @data
mov ds,ax
mov dx, offset cadena05
mov ah,09h
int 21h



            mov ah,02
            mov dl,'['
            int 21h



mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var11
int 21h
mov ah,02
mov dl,')'
int 21h

mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var22
int 21h
mov ah,02
mov dl,')'
int 21h

mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var33
int 21h
mov ah,02
mov dl,')'
int 21h


        mov ah,02
        mov dl,'+'
        int 21h


mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var12
int 21h
mov ah,02
mov dl,')'
int 21h

mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var23
int 21h
mov ah,02
mov dl,')'
int 21h

mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var31
int 21h
mov ah,02
mov dl,')'
int 21h


        mov ah,02
        mov dl,'+'
        int 21h


mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var21
int 21h
mov ah,02
mov dl,')'
int 21h

mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var32
int 21h
mov ah,02
mov dl,')'
int 21h

mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var13
int 21h
mov ah,02
mov dl,')'
int 21h

            mov ah,02
            mov dl,']'
            int 21h

            mov ah,02
            mov dl,'-'
            int 21h

            mov ah,02
            mov dl,'['
            int 21h



mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var13
int 21h
mov ah,02
mov dl,')'
int 21h

mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var22
int 21h
mov ah,02
mov dl,')'
int 21h

mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var31
int 21h
mov ah,02
mov dl,')'
int 21h


        mov ah,02
        mov dl,'+'
        int 21h


mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var23
int 21h
mov ah,02
mov dl,')'
int 21h

mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var32
int 21h
mov ah,02
mov dl,')'
int 21h

mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var11
int 21h
mov ah,02
mov dl,')'
int 21h


        mov ah,02
        mov dl,'+'
        int 21h


mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var12
int 21h
mov ah,02
mov dl,')'
int 21h

mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var21
int 21h
mov ah,02
mov dl,')'
int 21h

mov ah,02
mov dl,'('
int 21h
mov ah,02
mov dl,var33
int 21h
mov ah,02
mov dl,')'
int 21h

            mov ah,02
            mov dl,']'
            int 21h
            
;REDUCIENDO LAS MULTIPLICACIONES
mov al,var11
mov bl,var22
mov cl,var33
sub al,30h
sub bl,30h
sub cl,30h
mul bl
mul cx

mov varm1,ax
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov al,var21
mov bl,var32
mov cl,var13
sub al,30h
sub bl,30h
sub cl,30h
mul bl
mul cx

mov varm2,ax
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov al,var12
mov bl,var23
mov cl,var31
sub al,30h
sub bl,30h
sub cl,30h
mul bl
mul cx

mov varm3,ax
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX



mov al,var13
mov bl,var22
mov cl,var31
sub al,30h
sub bl,30h
sub cl,30h
mul bl
mul cx

mov varm4,ax
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov al,var23
mov bl,var32
mov cl,var11
sub al,30h
sub bl,30h
sub cl,30h
mul bl
mul cx

mov varm5,ax
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov al,var12
mov bl,var21
mov cl,var33
sub al,30h
sub bl,30h
sub cl,30h
mul bl
mul cx

mov varm6,ax
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX




mov ax, @data
mov ds,ax
mov dx, offset cadena06
mov ah,09h
int 21h

        mov ah,02
        mov dl,'('
        int 21h

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX


mov ax,varm1
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
        mov dl,'+'
        int 21h

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX


mov ax,varm2
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
        mov dl,'+'
        int 21h

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX


mov ax,varm3
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
        mov dl,')'
        int 21h
               
        mov ah,02
        mov dl,'-'
        int 21h
        
        mov ah,02
        mov dl,'('
        int 21h
        
XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX


mov ax,varm4
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
        mov dl,'+'
        int 21h

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX


mov ax,varm5
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
        mov dl,'+'
        int 21h

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX


mov ax,varm6
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
        mov dl,')'
        int 21h


;REDUCIENDO OPERACIONES

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov ax,varm1
mov bx,varm2
mov dx,varm3

add ax,bx
add ax,dx

mov varf1,ax


XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov ax,varm4
mov bx,varm5
mov dx,varm6

add ax,bx
add ax,dx

mov varf2,ax

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov ax,varf1
mov bx,varf2
sub ax,bx


cmp ax,00h
jns positivo
js negativo


positivo:
mov varfinal,ax                       
jmp continuacion1

negativo:
neg ax
mov varfinal,ax
jmp continuacion1

continuacion1:

.exit