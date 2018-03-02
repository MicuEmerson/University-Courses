;2. Read a character from the keyboard without echo. If the character is a digit, print it on the screen.
;   If the character is '$', end the current program.
;   In any other situation, the character is added to a buffer (i.e. a string) which will be printed on the screen when the program exits.


assume cs:code, ds:data

data segment

    buffer db 100 dup(?)
	
data ends

code segment
start:
	mov AX, data
	mov DS, AX

	mov SI, 0
	mov AH, 08h  ;keyboard input (no echo)
	int 21h      

	repeta: 
	
		cmp AL, '$' 
		je sfarsit_program   ;if we have '$' we finish and print
		
		cmp AL, '0'          
		jb add_to_buffer 
		
		cmp AL, '9'          
		ja add_to_buffer

		mov DL, AL            ; what is in DL will be printed
		mov AH, 02h           ; display output (write character)
		int 21h    
		
		jmp citire            ; we jump over addToBuffer because AL is digit 

		add_to_buffer:        ; if AL != digit
			mov buffer[SI], AL    
			inc SI                

		citire:
			mov AH, 08h     ;keyboard input (no echo)
			int 21h         
			
	jmp repeta      ;repeat until we get out with sfarsit_program
    
	
	sfarsit_program:
		mov buffer[SI], AL         ;add ($)
		;print the string "buffer" on the screen using interrupt 21h, function 09h
		mov AH, 09h            
		mov DX, OFFSET buffer
		int 21h                
    
	mov AH, 08h  ;keyboard input (no echo)
	int 21h      ;citesc caracter pe care il pune in al
	
	mov AX, 4C00h                                                      
	int 21h

code ends
end start
