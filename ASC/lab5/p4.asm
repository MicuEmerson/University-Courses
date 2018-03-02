ASSUME cs: code, ds:data

data SEGMENT  
    a DB  00010100b
    n DB 1
data ENDS

code SEGMENT
start:
   mov AX, data    
   mov DS, AX
   
   ;4. The byte A is given. Obtain the integer number n represented on the bits 2-4 of A.
   ; Then obtain the byte B by rotating A n positions to the right.

   mov BL, 0   ; we compute the result of first interger in BL
   
   mov AL, a
   and AL, 00011100b
   mov CL, 2
   ror AL, CL
   or BL, AL
  
   mov DL, 0  ; This is B

   mov AL, a
   mov CL, BL
   ror AL, CL
   or DL, AL
   
          
   mov ax, 4C00h
   int 21h
   
code ENDS
END start