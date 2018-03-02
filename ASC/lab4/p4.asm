ASSUME cs: code, ds:data

data SEGMENT  
    a DW 5
    b DB 2
    c DB 12
    d DB 2
    e DD 100
    
data ENDS

code SEGMENT
start:
   mov AX, data    
   mov DS, AX

   ;4. (a*2+b/2+e)/(c-d)
   ;a-wordl; b,c,d-byte; e-doubleword
   ; fara semn

   mov AX, a    
   mov BX, 2    
   mul BX      
   ;DX:AX = a*2
   
   mov CX, DX    
   mov BX, AX    
   ; CX:BX = DX:AX, facem asta sa eliberam DX:AX
  
   mov AL, b    
   mov AH, 0 
   mov DL, 2
   div DL
   ; AX / DL = b / 2
   ; AL = b/2, AH = b%2
   
   mov AH, 0
   mov DX, 0
   add AX, BX
   adc DX, CX
   ; l-am transformat pe AL in AX si pe urma in DX:AX
   ; adunam DX:AX += CX:BX  <==>  DX:AX = a*2 + b/2
   
   mov BX, word ptr e
   mov CX, word ptr e+2
   ; CX:BX = e
   
   add AX, BX
   adc DX, CX
   ; adunam DX:AX += CX:BX  <==>  DX:AX = a*2+b/2+e

   mov BL, c
   sub BL, d
   mov BH, 0
   ; BL = c-d
   ; BX = c-d
   
   div BX
   ; DX:AX / BX

   mov ax, 4C00h
   int 21h
   
code ENDS
END start