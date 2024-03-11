;Instrucciones de salto mayor-menor 

.model small
.data
var1 db 0
var2 db 0
var3 db 0
var4 db 0
var5 db 0
varsum db 0
varmul dw 0
vardiv db 0
mayo db 0
men db 0

texto0 db 10,13,"Programa que compara la suma, multiplicacion y division de cinco numeros",10,13,"$"
texto1 db 10,13,"ingresa primer numero:",10,13,"$"
texto2 db 10,13,"ingresa segundo numero:",10,13,"$"
texto3 db 10,13,"ingresa tercer numero:",10,13,"$"
texto4 db 10,13,"ingresa cuarto numero:",10,13,"$"
texto5 db 10,13,"ingresa quinto numero:",10,13,"$"

suma db 10,13,"la suma es:",10,13,"$"
multiplicacion db 10,13,"la multiplicacion fue realizada",10,13,"$"
division db 10,13,"la division fue realizada",10,13,"$"

mayoor db 10,13,"la suma es menor que la division",10,13,"$"
menoor db 10,13,"la suma es mayor que la division",10,13,"$"
iguaal db 10,13,"Son iguales",10,13,"$"

Ordena db 10,13,"Los numeros se han ordenado del mayor al menor",10,13,"$"
.code 


;texto de introduccion
mov ax,@data
mov ds,ax
mov dx,offset texto0
mov ah,09h
int 21h



;introduccion de digitos
mov ax,@data
mov ds,ax
mov dx,offset texto1
mov ah,09h
int 21h

mov ah,01
int 21h
aas
mov var1,al


mov ax,@data
mov ds,ax
mov dx,offset texto2
mov ah,09h
int 21h

mov ah,01
int 21h
aas
mov var2,al


mov ax,@data
mov ds,ax
mov dx,offset texto3
mov ah,09h
int 21h

mov ah,01
int 21h
aas
mov var3,al



mov ax,@data
mov ds,ax
mov dx,offset texto4
mov ah,09h
int 21h

mov ah,01
int 21h
aas
mov var4,al


mov ax,@data
mov ds,ax
mov dx,offset texto5
mov ah,09h
int 21h

mov ah,01
int 21h
aas
mov var5,al

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX


;realizacion de operacion aritmetica
mov al,var1
mov bl,var2
mov cl,var3
mov dl,var4

add al,bl
add cl,dl

mov dl,var5
add cl,dl

add al,cl
mov varsum,al

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov al,varsum
aam
mov bx,ax
add bx,3030h

;impresion de suma
mov ax,@data
mov ds,ax
mov dx,offset suma
mov ah,09h
int 21h

mov ah,02h
mov dl,bh
int 21h

mov ah,02h
mov dl,bl
int 21h

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX


;operaciones aritmeticas de la multiplicacion
mov al,var1
mov bl,var2
mov cl,var3
mov dl,var4

mul bl
mul cl
mul dx
xor bx,bx
mov bl,var5
mul bx
mov varmul,ax

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov ax,@data
mov ds,ax
mov dx,offset multiplicacion
mov ah,09h
int 21h


XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX


;operaciones aritmeticas de la division
mov ax,varmul
mov bl,varsum 
div bl
mov vardiv,al

mov ax,@data
mov ds,ax
mov dx,offset division
mov ah,09h
int 21h


XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX







mov al,varsum
mov bl,vardiv

cmp ax,bx

ja mayor  ;la suma es mayor que la DIVISION
jb menor  ;la suma es menor que la DIVISION
je igual  ;son iguales 

menor:

mov ax,@data
mov ds,ax
mov dx,offset mayoor
mov ah,09h
int 21h

mov mayo,cl 
mov men, bl

mov ax,@data
mov ds,ax
mov dx,offset ordena
mov ah,09h
int 21h

        XOR ax,ax
        mov al,bl
        aam
        mov bx,ax
        add cx,3030h

        XOR ax,ax
        mov cl,varsum
        mov al,cl
        aam
        mov cx,ax
        add cx,3030h


                mov ah,02h
                mov dl,ch
                int 21h

                mov ah,02h
                mov dl,cl
                int 21h
                
                mov ah,02h
                mov dl,'<' 
                int 21h
   
                mov ah,02h 
                mov dl,bh  
                int 21h    
                           
                mov ah,02h 
                mov dl,bl  
                int 21h    



.exit
mayor:

mov ax,@data
mov ds,ax
mov dx,offset menoor
mov ah,09h
int 21h

mov mayo,cl 
mov men, bl 

mov ax,@data
mov ds,ax
mov dx,offset ordena
mov ah,09h
int 21h

        XOR ax,ax
        mov al,bl
        aam
        mov bx,ax
        add cx,3030h

        XOR ax,ax
        mov cl,varsum
        mov al,cl
        aam
        mov cx,ax
        add cx,3030h


                mov ah,02h
                mov dl,ch
                int 21h

                mov ah,02h
                mov dl,cl
                int 21h
                
                mov ah,02h
                mov dl,'<' 
                int 21h
   
                mov ah,02h 
                mov dl,bh  
                int 21h    
                           
                mov ah,02h 
                mov dl,bl  
                int 21h    

.exit 


igual: 

mov ax,@data
mov ds,ax
mov dx,offset iguaal
mov ah,09h
int 21h

        XOR ax,ax
        mov al,bl
        aam
        mov bx,ax
        add cx,3030h

        XOR ax,ax
        mov cl,varsum
        mov al,cl
        aam
        mov cx,ax
        add cx,3030h

                mov ah,02h
                mov dl,ch
                int 21h

                mov ah,02h
                mov dl,cl
                int 21h
                
                mov ah,02h
                mov dl,'=' 
                int 21h
   
                mov ah,02h 
                mov dl,bh  
                int 21h    
                           
                mov ah,02h 
                mov dl,bl  
                int 21h 
 
.exit


.exit