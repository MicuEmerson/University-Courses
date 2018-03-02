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
   ; cu semn

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
   cwd
   ; DX:AX = 8
 
   sub AX, BX
   sbb DX, CX
   ; DX:AX -= CX:BX  <==> 8 - a*b*100+c
   
   mov BX, AX
   mov CX, DX
   ; CX:BX = DX:AX, am eliberat DX:AX pentru o conversie


   mov AL, d
   cbw
   mov DS, AX
   ; AX = d
   ; pe wordul d il punem provizoriu in DS
   
   mov AX, BX
   mov DX, CX
   mov BX, DS
   ; DX:AX = CX:BX, le-am interschimbat inapoi
   ; BX = DS, DS fiind variabile d din problema
   
   
   idiv BX
   ; DX:AX / BX
 

   mov ax, 4C00h
   int 21h
   
code ENDS
END start
