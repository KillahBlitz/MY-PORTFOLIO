; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov es, ax

    ; add your code here







;todo lo que se ha realizado hasta este momento
;.data .com y .exe se les llama directivas su sinonimo es seudoinstrucciones y seudodirectivas
;uso de cadenas

.model small
.data
mensaje db 'hola mundo',10,13,'$'
variable db ?

.code
mov ax,@data
mov ds,ax
mov dx, offset mensaje
mov, 09
int 21h
.exit





            
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.


