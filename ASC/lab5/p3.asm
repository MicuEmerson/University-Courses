ASSUME cs: code, ds:data

data SEGMENT  
    a DW 0111011101010111b
    b DW 1001101110111110b
data ENDS

code SEGMENT
start:
   mov AX, data    
   mov DS, AX

   ;3. The words A and B are given. Obtain the word C in the following way:
   ;	- the bits 0-2 of C are the same as the bits 12-14 of A
   ;	- the bits 3-8 of C are the same as the bits 0-5 of B 
   ;	- the bits 9-15 of C are the same as the bits 3-9 of A

   
   mov BX, 0   ;we compute the result in BX

   mov AX, a
   and AX, 0111000000000000b
   mov CL, 12
   ror AX, CL
   or  BX, AX
   ; the bits 0-2 of C are the same as the bits 12-14 of A
   
   mov AX, b
   and AX, 0000000000111111b
   mov CL, 3
   rol AX, CL
   or BX, AX
   ; the bits 3-8 of C are the same as the bits 0-5 of B

   mov AX, a
   and AX, 0000001111111000b
   mov CL, 6
   rol AX, CL
   or  BX, AX
   ; the bits 9-15 of C are the same as the bits 3-9 of A
           
   
   mov ax, 4C00h
   int 21h
   
code ENDS
END start