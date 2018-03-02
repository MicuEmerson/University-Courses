ASSUME cs: code, ds:data

data SEGMENT  
    j DB 10
    g DB 3
data ENDS

code SEGMENT
start:
   mov AX, data    
   mov DS, AX

   ; 100/(j-g)
   mov AX, 100
   mov DH, j
   sub DH, g
   div DH
   
   mov ax, 4C00h
   int 21h
   
code ENDS
END start