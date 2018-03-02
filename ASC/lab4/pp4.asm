ASSUME cs: code, ds:data

data SEGMENT  
    a DW 5
    b DB 2
    c DB 2
    d DB 12
    e DD 100
    
data ENDS

code SEGMENT
start:
   mov AX, data    
   mov DS, AX

   ;4. (a*2+b/2+e)/(c-d)
   ;a-word; b,c,d-byte; e-doubleword
   ; cu semn

   mov AX, a    
   mov BX, 2    
   imul BX      
   ;DX:AX = a*2
   
   mov CX, DX    
   mov BX, AX    
   ; CX:BX = DX:AX, facem asta sa eliberam DX:AX
  
   mov AL, b    
   cbw
   mov DL, 2
   idiv DL
   ; AX / DL = b / 2
   ; AL = b/2, AH = b%2
   
   cbw
   cwd
   add AX, BX
   adc DX, CX
   ; l-am transformat pe AL in AX si pe urma in DX:AX
   ; adunam DX:AX += CX:BX  <==>  DX:AX = a*2 + b/2
   
   mov BX, word ptr e
   mov CX, word ptr e+2
   ; CX:BX = e
  

   add BX, AX
   adc CX, DX
   ; adunam CX:BX += DX:AX  <==>  CX:BX = a*2+b/2+e

   mov AL, c
   sub AL, d
   cbw 
   ; AL = c-d
   ; AX = c-d

   mov DX, CX
   mov CX, AX
   mov AX, BX
   ; am readus rezultatul (a*2+b/2+e) in DX:AX si am bagat (c-d) in CX cu niste interschimbari 

   idiv CX
   ; DX:AX / CX

   mov ax, 4C00h
   int 21h
   
code ENDS
END start