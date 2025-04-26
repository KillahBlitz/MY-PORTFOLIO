.model small
.data 
cadena db "ESTE PROGRAMA HACE LA COMPARACION DE VALORES DE UNA SUMA Y UNA MULTIPLICACION INGRESADO DESDE EL TECLADO",10,13,"$"
cadena1 db ,10,13,"INGRESA EL VALOR A: ",10,13,"$"
cadena2 db ,10,13,"INGRESA EL VALOR B: ",10,13,"$"
cadena3 db ,10,13,"INGRESA EL VALOR B: ",10,13,"$"
cadena4 db ,10,13,"INGRESA EL VALOR B: ",10,13,"$"


ci db ,10,13,"LA COMPARACION DE LA SUMA Y MULTIPLICACION ES IGUAL EN SU RESULTADO",10,13,"$"
no db ,10,13,"LA COMPARACION DE LA SUMA Y MULTIPLICACION NO ES IGUAL EN SU RESULTADO",10,13,"$"


v1 db 0
v2 db 0
v3 db 0
v4 db 0

s1 db 0
m1 db 0

.code




mov ax,@data
mov ds,ax
mov dx,offset cadena
mov ah, 09
int 21h



mov ax,@data
mov ds,ax
mov dx,offset cadena1
mov ah, 09
int 21h
 
mov ah,01
int 21h

sub ax,3030h
mov v1,al  



 
mov ax,@data
mov ds,ax
mov dx,offset cadena2
mov ah, 09
int 21h

mov ah,01
int 21h

sub ax,3030h
mov v2,al




mov ax,@data
mov ds,ax
mov dx,offset cadena3
mov ah, 09
int 21h

mov ah,01
int 21h

sub ax,3030h
mov v3,al




mov ax,@data
mov ds,ax
mov dx,offset cadena4
mov ah, 09
int 21h

mov ah,01
int 21h

sub ax,3030h
mov v4,al 

        XOR ax,ax
        XOR bx,bx
        XOR cx,cx
        XOR dx,dx

mov al,v1
mov bl,v2
add al,bl
mov s1,al
        
       XOR ax,ax
       XOR bx,bx
       XOR cx,cx
       XOR dx,dx 
                
mov al,v3
mov bl,v4
mul bl
mov m1,al


       XOR ax,ax
       XOR bx,bx
       XOR cx,cx
       XOR dx,dx
       
mov al,s1
mov bl,m1


cmp al,bl



je igual
jne noigual



igual:
mov ax,@data
mov ds,ax
mov dx,offset ci
mov ah, 09
int 21h
.exit

noigual:
mov ax,@data
mov ds,ax
mov dx,offset no
mov ah, 09
int 21h

.exit



.exit