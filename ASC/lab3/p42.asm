ASSUME cs: code, ds:data

data SEGMENT  
     a DW 2
     b DW 7
     c DW 5
     d DW 3
data ENDS

code SEGMENT
start:
   mov AX, data    
   mov DS, AX

   ;(c+b)-a+(d+d)
   mov AX, b
   add AX, c
   sub AX, a
   add AX, d
   add AX, d
   
   mov ax, 4C00h
   int 21h
   
code ENDS
END start