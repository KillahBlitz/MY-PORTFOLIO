;ESTE PROGRAMA REALIZA LA SEPARACION DE NUMEROS PARES E IMPARES


.model small
.data
var1 db 0
var2 db 0
var3 db 0
var4 db 0
var5 db 0
var6 db 0
var7 db 0
var8 db 0
var9 db 0
var0 db 0 


varsum db 0
varmul dw 0
vardiv db 0



varpar1 db 0
varpar2 db 0
varpar3 db 0
varpar4 db 0
varpar5 db 0
varpar6 db 0
varpar7 db 0
varpar8 db 0
varpar9 db 0
varpar0 db 0


varim1 db 1
varim2 db 1
varim3 db 1
varim4 db 1
varim5 db 1
varim6 db 1
varim7 db 1
varim8 db 1
varim9 db 1
varim0 db 1



mayo dw 0
men dw 0

texto0 db 10,13,"Programa separa pares e impares, los impares se multiplican y los pares se suman",10,13,"$"
texto1 db 10,13,"ingresa primer numero:",10,13,"$"
texto2 db 10,13,"ingresa segundo numero:",10,13,"$"
texto3 db 10,13,"ingresa tercer numero:",10,13,"$"
texto4 db 10,13,"ingresa cuarto numero:",10,13,"$"
texto5 db 10,13,"ingresa quinto numero:",10,13,"$"
texto6 db 10,13,"ingresa sexto numero:",10,13,"$"
texto7 db 10,13,"ingresa septimo numero:",10,13,"$"
texto8 db 10,13,"ingresa octavo numero:",10,13,"$"
texto9 db 10,13,"ingresa noveno numero:",10,13,"$"
texto10 db 10,13,"ingresa decimo numero:",10,13,"$"

suma db 10,13,"la suma es:",10,13,"$"
multiplicacion db 10,13,"la multiplicacion fue realizada",10,13,"$"
division db 10,13,"la division fue realizada",10,13,"$"

mayoor db 10,13,"la suma es menor que la multiplicacion",10,13,"$"
menoor db 10,13,"la suma es mayor que la multiplicacion",10,13,"$"
iguaal db 10,13,"Son iguales",10,13,"$"

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


;introduccion de digitos
mov ax,@data
mov ds,ax
mov dx,offset texto6
mov ah,09h
int 21h

mov ah,01
int 21h
aas
mov var6,al


mov ax,@data
mov ds,ax
mov dx,offset texto7
mov ah,09h
int 21h

mov ah,01
int 21h
aas
mov var7,al


mov ax,@data
mov ds,ax
mov dx,offset texto8
mov ah,09h
int 21h

mov ah,01
int 21h
aas
mov var8,al



mov ax,@data
mov ds,ax
mov dx,offset texto9
mov ah,09h
int 21h

mov ah,01
int 21h
aas
mov var9,al


mov ax,@data
mov ds,ax
mov dx,offset texto10
mov ah,09h
int 21h

mov ah,01
int 21h
aas
mov var0,al


XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX




;COMPARACION DE NUMEROS         
XOR AX,AX 
XOR BX,BX        
mov al,var1
mov bl, 2
div bl
cmp ah,0

        jp espar1
        jnp impar1

espar1:
mov al,var1
mov varpar1,al
jmp ciclo 
         
impar1:
mov al,var1
mov varim1,al
jmp ciclo



    ciclo:
XOR AX,AX 
XOR BX,BX        
mov al,var2
mov bl, 2
div bl
cmp ah,0

        jp espar2
        jnp impar2

espar2:
mov al,var2
mov varpar2,al
jmp ciclo1
         
impar2:
mov al,var2
mov varim2,al
jmp ciclo1



    ciclo1:
XOR AX,AX 
XOR BX,BX        
mov al,var3
mov bl, 2
div bl
cmp ah,0

        jp espar3
        jnp impar3

espar3:
mov al,var3
mov varpar3,al
jmp ciclo2
         
impar3:
mov al,var3
mov varim3,al
jmp ciclo2



    ciclo2:
XOR AX,AX 
XOR BX,BX        
mov al,var4
mov bl, 2
div bl
cmp ah,0

        jp espar4
        jnp impar4

espar4:
mov al,var4
mov varpar4,al
jmp ciclo3
         
impar4:
mov al,var4
mov varim4,al
jmp ciclo3 



    ciclo3:
XOR AX,AX 
XOR BX,BX        
mov al,var5
mov bl, 2
div bl
cmp ah,0

        jp espar5
        jnp impar5

espar5:
mov al,var5
mov varpar5,al
jmp ciclo4
         
impar5:
mov al,var5
mov varim5,al
jmp ciclo4 



    ciclo4:
XOR AX,AX 
XOR BX,BX        
mov al,var6
mov bl, 2
div bl
cmp ah,0

        jp espar6
        jnp impar6

espar6:
mov al,var6
mov varpar6,al
jmp ciclo5
         
impar6:
mov al,var6
mov varim6,al
jmp ciclo5



    ciclo5:
XOR AX,AX 
XOR BX,BX        
mov al,var7
mov bl, 2
div bl
cmp ah,0

        jp espar7
        jnp impar7

espar7:
mov al,var7
mov varpar7,al
jmp ciclo6
         
impar7:
mov al,var7
mov varim7,al
jmp ciclo6 



    ciclo6:
XOR AX,AX 
XOR BX,BX        
mov al,var8
mov bl, 2
div bl
cmp ah,0

        jp espar8
        jnp impar8

espar8:
mov al,var8
mov varpar8,al
jmp ciclo7
         
impar8:
mov al,var8
mov varim8,al
jmp ciclo7



    ciclo7:
XOR AX,AX 
XOR BX,BX        
mov al,var9
mov bl, 2
div bl
cmp ah,0

        jp espar9
        jnp impar9

espar9:
mov al,var9
mov varpar9,al
jmp ciclo8
         
impar9:
mov al,var9
mov varim9,al
jmp ciclo8



    ciclo8:
XOR AX,AX 
XOR BX,BX        
mov al,var0
mov bl, 2
div bl
cmp ah,0

        jp espar0
        jnp impar0

espar0:
mov al,var0
mov varpar0,al
jmp ciclo9
         
impar0:
mov al,var0
mov varim0,al
jmp ciclo9














;suma de los numeros pares

ciclo9:

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov al,varpar1
mov bl,varpar2
mov cl,varpar3
mov dl,varpar4

add al,bl
add cl,dl
add al,cl

XOR BX,BX
XOR CX,CX
XOR DX,DX

mov bl,varpar5
mov cl,varpar6
mov dl,varpar7

add al,bl
add cl,dl
add al,cl

XOR BX,BX
XOR CX,CX
XOR DX,DX

mov bl,varpar8
mov cl,varpar9
mov dl,varpar0

add al,bl
add cl,dl
add al,cl

mov varsum,al

;IMPRESION DE LA SUMA

aam
mov bx,ax
add bx,3030h

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




;multiplicacion de numeros impares

mov al,varim1
mov bl,varim2
mul bl

XOR BX,BX
mov bl,varim3
mul bl
XOR BX,BX
mov bl,varim4
mul bl
XOR BX,BX
mov bl,varim5
mul bl
XOR BX,BX
mov bl,varim6
mul bl
XOR BX,BX
mov bl,varim7
mul bl
XOR BX,BX
mov bl,varim8
mul bl
XOR BX,BX
mov bl,varim9
mul bl
XOR BX,BX
mov bl,varim0
mul bl

mov varmul,ax

mov ax,@data
mov ds,ax
mov dx,offset multiplicacion
mov ah,09h
int 21h


XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov ax,varmul

cmp ax,0066h 

ja mayor99
jb menor99


menor99:
XOR AX,AX
mov ax,varmul
aam
mov bx,ax
add bx,3030h

mov ah,02h
mov dl,bh
int 21h

mov ah,02h
mov dl,bl
int 21h

jmp ciclofinal


mayor99:

jmp ciclofinal







ciclofinal:
mov cl,varsum
mov bx,varmul

cmp cx,bx

ja mayor  ;la suma es mayor que la multiplicacion
jb menor  ;la suma es menor que la multiplicacion
je igual  ;son iguales 

menor:

mov ax,@data
mov ds,ax
mov dx,offset mayoor
mov ah,09h
int 21h

mov mayo,cx 
mov men, bx

jmp operacionf


mayor:

mov ax,@data
mov ds,ax
mov dx,offset menoor
mov ah,09h
int 21h

mov mayo,cx 
mov men, bx 

jmp operacionf 


igual: 

mov ax,@data
mov ds,ax
mov dx,offset iguaal
mov ah,09h
int 21h
jmp operacionf


operacionf:

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov ax,mayo
mov bx,men

div bx


.exit





