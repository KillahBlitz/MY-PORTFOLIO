.model small
.data

cadena db 'PROGRAMMA QUE CALCULA EL AREA DE UN RECTANGULO',10,13,'$'
   
.code
mov ah,06
mov bh, 037H
mov cx,0000h
mov dx,092Dh
int 10h   
   
   
mov ax,@data
mov ds,ax
mov dx,offset cadena
mov ah,09
int 21h   
 




mov ah,02
mov bh,00
mov dx,042Eh
int 10h   

  
mov ah,01
int 21h  




mov ah,02
mov bh,00
mov dx,0A16h
int 10h   

  
mov ah,01
int 21h
  

.exit