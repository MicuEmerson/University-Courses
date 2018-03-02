ASSUME cs: code, ds:data

data SEGMENT  

    a DB 1
    b DB 1
    c DD 4
    d DB 10

data ENDS

code SEGMENT
start:
   mov AX, data    
   mov DS, AX
   
   ; (8-a*b*100+c)/d
   ; a,b,d-byte; c-doubleword
   ; fara semn

   mov AL, a
   mul b
   ; AX = a*b
   
   mov BX, 100
   mul BX
   ; DX:AX = a*b*100

   mov BX, word ptr c
   mov CX, word ptr c+2
   ; CX:BX = c

   add BX, AX
   adc CX, DX
   ; CX:BX += DX:AX  <==> a*b*100 + c

   mov AX, 8
   mov DX, 0
   ; DX:AX = 8
 
   sub AX, BX
   sub DX, CX
   ; DX:AX -= CX:BX  <==> 8 - a*b*100+c

   mov BL, d
   mov BH, 0
   ; BX = d
   
   div BX
   ; DX:AX / BX
 
   
   

   mov ax, 4C00h
   int 21h
   
code ENDS
END start
