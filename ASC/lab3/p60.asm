ASSUME cs: code, ds:data

data SEGMENT  
    a DB 10
    b DW 7
    d DB 5
   
data ENDS

code SEGMENT
start:
   mov AX, data    
   mov DS, AX

   ; (b+256-a*d)/a
   mov DX, b
   add DX, 256
   mov AL, a
   mul d
   sub DX, AX
   mov AX, DX
   div a
   
   mov ax, 4C00h
   int 21h
   
code ENDS
END start