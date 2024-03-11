;PROGRAMA QUE CALCULA UN CIRCUITO EN SERIE CON LENGUAJE ENSAMBLADOR
.model small
.data                                         


titulo db "PROGRAMA QUE IMPRIME Y CALCULA UN CIRCUITO EN SERIE DE RESISTENCIAS",10,13,"$"
resultado db "EL RESULTADO DE LA OPERACION ES",10,13,"$"

vars1 db 0
vars2 db 0
vars3 db 0
vars4 db 0
vars5 db 0
resul dw 0

.code
mov ax,@data
mov ds,ax
mov dx,offset titulo
mov ah, 09
int 21h


mov ah,06
mov bh,060H
mov cx,0100h
mov dx,0209h
int 10h 


    mov ah,06
    mov bh,030H
    mov cx,0102h
    mov dx,0203h
    int 10h
    
    mov ah,06
    mov bh,040H
    mov cx,0105h
    mov dx,0206h
    int 10h
            
             mov ah,06
             mov bh,070H
             mov cx,020Ah
             mov dx,020Fh
             int 10h
            
    
         
    
        
mov ah,06
mov bh,060H
mov cx,0110h
mov dx,0219h
int 10h 


    mov ah,06
    mov bh,020H
    mov cx,0112h
    mov dx,0213h
    int 10h
    
    mov ah,06
    mov bh,035H
    mov cx,0115h
    mov dx,0216h
    int 10h                                                           
    
             mov ah,06
             mov bh,070H
             mov cx,021Ah
             mov dx,021Fh
             int 10h
             
             
             
    
mov ah,06
mov bh,060H
mov cx,0120h
mov dx,0229h
int 10h
       
       
    mov ah,06
    mov bh,050H
    mov cx,0122h
    mov dx,0223h
    int 10h
    
    mov ah,06
    mov bh,042H
    mov cx,0125h
    mov dx,0226h
    int 10h
    
             mov ah,06
             mov bh,070H
             mov cx,022Ah
             mov dx,022Fh
             int 10h
             
             
             
    

mov ah,06
mov bh,060H
mov cx,0130h
mov dx,0239h
int 10h
       
       
    mov ah,06
    mov bh,017H
    mov cx,0132h
    mov dx,0233h
    int 10h
    
    mov ah,06
    mov bh,025H
    mov cx,0135h
    mov dx,0236h
    int 10h   
    
             mov ah,06
             mov bh,070H
             mov cx,023Ah
             mov dx,023Fh
             int 10h
             
             
             
    

mov ah,06
mov bh,060H
mov cx,0140h
mov dx,0249h
int 10h    
    
    
    mov ah,06
    mov bh,050H
    mov cx,0142h
    mov dx,0243h
    int 10h
    
    mov ah,06
    mov bh,055H
    mov cx,0145h
    mov dx,0246h
    int 10h    
    

             mov ah,06
             mov bh,070H
             mov cx,024Ah
             mov dx,024Fh
             int 10h
                          
           
             mov ah,06
             mov bh,070H
             mov cx,024Fh
             mov dx,0F4Fh
             int 10h
             
             mov ah,06
             mov bh,070H
             mov cx,0F00h
             mov dx,0F4Fh
             int 10h             
        
    
;INGRESO DE VALORES

mov ah,02
mov bh,00
mov dx,0304h
int 10h   
  
mov ah,01
int 21h
sub ax,3030h
mov vars1,al 



mov ah,02
mov bh,00
mov dx,0314h
int 10h   
  
mov ah,01
int 21h
sub ax,3030h
mov vars2,al 



mov ah,02
mov bh,00
mov dx,0324h
int 10h   
  
mov ah,01
int 21h
sub ax,3030h
mov vars3,al 




mov ah,02
mov bh,00
mov dx,0334h
int 10h   
  
mov ah,01
int 21h
sub ax,3030h
mov vars4,al 




mov ah,02
mov bh,00
mov dx,0344h
int 10h   
  
mov ah,01
int 21h
sub ax,3030h
mov vars5,al

;IMPRESION DE LA SUMA



;LA SUMA DE LAS RESISTENCIAS EN SERIE

XOR AX,AX
XOR BX,BX
XOR CX,CX
XOR DX,DX

mov al,vars1
mov bl,vars2
mov cl,vars3
mov dl,vars4

add al,bl
add cl,dl

mov bl,vars5

add al,cl
add al,bl
aam

add ax,3030h

mov resul,ax

add vars1,30h
add vars2,30h
add vars3,30h
add vars4,30h
add vars5,30h



mov ah,02
mov bh,00
mov dx,0415h
int 10h 
mov ax,@data
mov ds,ax
mov dx,offset resultado
mov ah, 09
int 21h


 


mov ah,02
mov bh,00
mov dx,0515h
int 10h

mov ah,02
mov dl,vars1
int 21h

        mov ah,02
        mov bh,00
        mov dx,0516h
        int 10h

        mov ah,02
        mov dl,'+'
        int 21h

mov ah,02
mov bh,00
mov dx,0517h
int 10h

mov ah,02
mov dl,vars2
int 21h

        mov ah,02
        mov bh,00
        mov dx,0518h
        int 10h

        mov ah,02
        mov dl,'+'
        int 21h

mov ah,02
mov bh,00
mov dx,0519h
int 10h

mov ah,02
mov dl,vars3
int 21h

        mov ah,02
        mov bh,00
        mov dx,051Ah
        int 10h

        mov ah,02
        mov dl,'+'
        int 21h
        
mov ah,02
mov bh,00
mov dx,051Bh
int 10h

mov ah,02
mov dl,vars4
int 21h

        mov ah,02
        mov bh,00
        mov dx,051Ch
        int 10h

        mov ah,02
        mov dl,'+'
        int 21h
        
mov ah,02
mov bh,00
mov dx,051Dh
int 10h

mov ah,02
mov dl,vars5
int 21h

        mov ah,02
        mov bh,00
        mov dx,051Eh
        int 10h

        mov ah,02
        mov dl,'='
        int 21h 

 
mov ah,02
mov bh,00
mov dx,051Fh
int 10h


XOR BX,BX
mov bx, resul

mov ah,02
mov dl,bh
int 21h

mov ah,02
mov bh,00
mov dx,0520h
int 10h

mov ah,02
mov dl,bl
int 21h
    