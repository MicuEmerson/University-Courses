ASSUME cs: code, ds:data

data SEGMENT 
    a DB 5
    b DB 10
    c DB 7
    d DB 2
    x DB ?
data ENDS

code SEGMENT
start:
   mov AX, data    
   mov DS, AX

   mov AL, a
   add AL, b
   mov x, AL
   mov AL, c
   add AL, d
   sub x, AL
       
   mov ax,4C00h
   int 21h
   
code ENDS
END start