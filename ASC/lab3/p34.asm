ASSUME cs: code, ds:data

data SEGMENT 
    a DB 5 
    b DB 2
    c DB 3
    
data ENDS

code SEGMENT
start:
   mov AX, data    
   mov DS, AX

   ; (a-c)*3+b*b
   mov AL, a
   sub AL, c
   mov BL, 3
   mul BL
   mov DX, AX
   mov AL, b
   mul b
   add DX, AX
   
   mov ax, 4C00h
   int 21h
   
code ENDS
END start