
;INICIO DEL PROGRAMA, CADENAS AL PRINCIPIO Y LA PRIMERA CADENA
.model small
.data
cadena0 db 'Este programa explica como podemos sacar una Determinante de una Matriz', 10,13,'$'
cadena1 db 'Nuestra Matriz generica es:', 10,13,'$'
cadena2 db 'Para calcular la determinante debemos seguir este procedimiento', 10,13,'$'
cadena3 db 'la primera parte de la operacion es la suma de los productos de la diagonal principal', 10,13,'$'
cadena4 db 'y las diagonales bajas junto con el termino individual, por lo que, la operacion queda de esta forma:', 10,13,'$'
cadena5 db 'aei+dhc+bfg', 10,13,'$'
cadena6 db 'ahora se debe hacer del lado contrario a la que se hizo y hacer la diferencia de las operaciones (resta)', 10,13,'$'
cadena7 db 'por lo que queda como:', 10,13,'$'
cadena8 db 'ceg+dbi+afh', 10,13,'$'
cadena9 db 'por ultimo, solo se aplica la diferencia y asi sacaremos la determinante', 10,13,'$'
cadenaA db '(aei+dhc+bfg)-(ceg+dbi+afh)= detA', 10,13,'$'
CadenaB db 'Llamado metodo de SARRUS, es el metodo usado para la determinante de una matriz', 10,13,'$'
CadenaC db 'Para nuestro caso, nuestros valores seran: {7, 4, 7, 4, 7, 4, 6, 7, 4} ', 10,13,'$'
CadenaD db 'Nuestra Determinante Matriz A quedara como:', 10,13,'$'
CadenaE db 'Aplicando sarrus:', 10,13,'$'
CadenaF db '(7)(7)(4)+(4)(7)(7)+(6)(4)(4)', 10,13,'$'
CadenaA1 db '(7)(7)(6)+(4)(7)(7)+(4)(7)(4)', 10,13,'$'
CadenaA2 db 'Por lo tanto, la determinante queda como:', 10,13,'$'
CadenaA3 db '((7)(7)(4)+(4)(7)(7)+(6)(4)(4))-((7)(7)(6)+(4)(7)(7)+(4)(7)(4))=DetA', 10,13,'$'
CadenaA4 db 'Hasta ahora todo este programa ha sido impresion, pero ahora pueden darse los valores de forma aritmetica', 10,13,'$'
CadenaA5 db 'Por lo cual, es importante recalcar que el programa funciona con valores especificos', 10,13,'$'
CadenaA6 db 'No obstante, desde la consola se pueden ingresar nuevos valores, pero la impresion no cambiara', 10,13,'$'
CadenaA7 db 'Desde, este momento, se imprimiran las multiplicaciones, sumas y resultado de la determinante', 10,13,'$'


.code
mov ax, @data
mov ds,ax
mov dx, offset cadena0
mov ah,09h
int 21h

mov ax, @data
mov ds,ax
mov dx, offset cadena1
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h










;EXPLICACION DE LA FORMA DE UNA MATRIZ JUNTO A SU SIMBOLOGIA DE DETERMIANTES (LAS BARRAS)
mov ah,02
mov dl,'|'
int 21h

 
 
mov ah,02
mov dl,'a'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'b'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'c'
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
mov dl,'d'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'e'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'f'
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
mov dl,'g'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'h'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'i'
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
 








;AQUI MUESTRO EL PRIMER PASO PARA PODER SACAR LA DETERMINANTE DE UNA MATRIZ

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        

mov ax, @data
mov ds,ax
mov dx, offset cadena2
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
mov dl,'a'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'b'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'c'
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
mov dl,'d'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'e'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'f'
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
mov dl,'g'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'h'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'i'
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
mov dl,'a'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'b'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'c'
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
mov dl,'d'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'e'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'f'
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
  
mov ax, @data
mov ds,ax
mov dx, offset cadena3
mov ah,09h
int 21h


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
        
mov ax, @data
mov ds,ax
mov dx, offset cadena4
mov ah,09h
int 21h


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
 
 
mov ax, @data
mov ds,ax
mov dx, offset cadena5
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
 








;AQUI MUESTRO EL SEGUNDO PASO PARA PODER SACAR LA DETERMINANTE DE UNA MATRIZ

mov ax, @data
mov ds,ax
mov dx, offset cadena6
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
mov dl,'a'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'b'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'c'
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
mov dl,'d'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'e'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'f'
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
mov dl,'g'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'h'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'i'
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
mov dl,'a'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'b'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'c'
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
mov dl,'d'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'e'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'f'
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
 
 
mov ax, @data
mov ds,ax
mov dx, offset cadena7
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
        
mov ax, @data
mov ds,ax
mov dx, offset cadena8
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        








;AQUI EXPLICO EL METODO QUE APLICAMOS PARA SACAR LA DETERMINANTE

mov ax, @data
mov ds,ax
mov dx, offset cadena9
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
mov ax, @data
mov ds,ax
mov dx, offset cadenaA
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
mov ax, @data
mov ds,ax
mov dx, offset cadenaB
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        






;AQUI EMPEZAMOS A APLICAR NUESTRO CASO ESPECIFICO
 
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

mov ax, @data
mov ds,ax
mov dx, offset cadenaC
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
        
        
        
;AQUI ARMO MI MATRIZ ESPECIFICA
mov ax, @data
mov ds,ax
mov dx, offset cadenaD
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
mov dl,'7'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'4'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'7'
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
mov dl,'4'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'7'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'4'
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
mov dl,'6'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'7'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'4'
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
        













;AQUI EMPIEZO A APLICAR EL PRIMER PASO
        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
                
mov ax, @data
mov ds,ax
mov dx, offset cadenaE
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
mov dl,'7'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'4'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'7'
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
mov dl,'4'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'7'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'4'
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
mov dl,'6'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'7'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'4'
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
mov dl,'7'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'4'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'7'
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
mov dl,'4'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'7'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'4'
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

mov ax, @data
mov ds,ax
mov dx, offset cadenaF
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
        
        
        






;APLICANDO LA OPERACION INVERSA QUE ES EL SEGUNDO PASO

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
mov dl,'7'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'4'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'7'
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
mov dl,'4'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'7'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'4'
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
mov dl,'6'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'7'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'4'
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
mov dl,'7'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'4'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'7'
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
mov dl,'4'
int 21h


mov ah,02
mov dl,' '
int 21h
 
 
mov ah,02
mov dl,'7'
int 21h


mov ah,02
mov dl,' '
int 21h


mov ah,02
mov dl,'4'
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
        
mov ax, @data
mov ds,ax
mov dx, offset cadenaF
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
        
        
        
        
        
        
        
        
        
;AQUI ARMO LA FORMA EN LA CUAL QUEDA FORMADA LA DETERMINANTE


        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 
        

mov ax, @data
mov ds,ax
mov dx, offset cadenaA2
mov ah,09h
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
        

mov ax, @data
mov ds,ax
mov dx, offset cadenaA3
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 








;AQUI DAMOS INSTRUCCIONES DEL USO CORRECTO DEL PROGRAMA

mov ax, @data
mov ds,ax
mov dx, offset cadenaA4
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h 

mov ax, @data
mov ds,ax
mov dx, offset cadenaA5
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
mov ax, @data
mov ds,ax
mov dx, offset cadenaA6
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h        
         
mov ax, @data
mov ds,ax
mov dx, offset cadenaA7
mov ah,09h
int 21h

        mov ah,02
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
        
        
        



;DESDE AQUI EMPIEZAN LAS OPERACIONES ARITMETICAS

XOR ax,ax
XOR bx,bx
XOR cx,cx
XOR dx,dx


mov al,7
mov bl,7
mul bl
mov cl,al

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
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h

mov al,cl

    XOR cx,cx

mov bl,4
mul bl
mov cl,al

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
        mov dl,0Ah
        int 21h
        
        mov ah,02
        mov dl,0Dh
        int 21h
         