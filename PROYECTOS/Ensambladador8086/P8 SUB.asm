;Instruccion Sub

;sub (resta)


;ejemplos de sintaxis


;sub ax,bx

;sub bh,al

;sub ax,5

;sub ah,3

;sub al, variable  ;el tema de variable es un pendiente




;programa

mov ah,01
int 21h

sub al,30h

mov bl,al

mov ah,02
mov dl,'-'
int 21h


mov ah,01
int 21h
sub al,30h

sub bl,al
  
  
;instruccion logica
 
;siendo el valor negativo arrojado (teniendo x-a donde a>x y el resultado siendo r, queda -r)
;la bandera que nos arroja que el valor es negativo en el registro de banderas, y la impresion no la podemos hacer
;es por eso que utilizamos la instruccion NEG, que nos sirve para negar el valor negativo que tiene el numero y poderlo imprimir
;pero bien, para la aritmetica este no sirve, porque no pertenece al conjunto de numeros enteros, si no naturales

;ejemplo de sintaxis

NEG ax
neg al
neg bh

  