ASSUME cs: code, ds:data

data SEGMENT  
      s DB 'a', 'v', 'x', 'a', 'c'
      l EQU $-s

      d DB l dup (?)

data ENDS

code SEGMENT
start:
  
      mov AX, data
      mov DS, AX
	  
      mov CX, l      
      mov SI, 0      
      jcxz Sfarsit   
      Repeta:
		  mov AL, byte ptr s[SI]    
		  sub AL, 'a'-'A'     

		  mov byte ptr d[SI], AL     
		  inc SI      
		  loop Repeta
	  
	  
      Sfarsit:      
      mov ax, 4C00h
      int 21h
  
  
  
  
   
   
code ENDS
END start