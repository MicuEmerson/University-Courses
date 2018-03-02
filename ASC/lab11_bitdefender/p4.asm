%define NULL 0x0
[bits 32]

section .text
    
	
extern _printf
extern _exit
extern __time32
extern _getchar

global  _main 

   
_main:
       
	   push DWORD NULL
	   call __time32
	   add ESP, 4
	   mov EBX, EAX
	   
	   repeta:
	         
			push DWORD EBX 
			push DWORD format
			call _printf
			add ESP, 4*2
			
			call _getchar
			cmp EAX, '$'
			je ies_afara
			
			mov EAX, EBX  ; we will perform the operations in EAX, it's more easy because we will have to do multiplication..
			and EAX, 00000000111111111111111100000000b ; we take the bits from 8-23
			mov CL, 8   
			shr EAX, CL   ; we shift right with 8 position so the bits 8-23 will be now 0-15, in this way we can perform rand^2
			
			mul EAX       ; it is something like EAX = AX*AX because we have value only on 0-15 bits
			mov EBX, EAX  ; we copy back the result in EBX because in EAX we will use _getchar function
			add EBX, 12345    ;we add that 'K' constant
			
	
	   jmp repeta
	   
		
		ies_afara:
        call    _exit
        ret 
		

section .data

	format DB '%d', 0
	
	
   
