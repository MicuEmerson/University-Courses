[bits 32]

section .text
    
	
extern  _printf
extern _exit

global  _main 

   
_main:
        mov EAX, [nr1]
		mov EBX, [nr2]
		
		cmp EAX, EBX
		je afisam
		
		repeta:
		   
		   cmp EAX, EBX
		   je afisam
		   ja scade_EAX
		   jb scade_EBX
		   
		   scade_EBX:
		   sub EBX, EAX
		   jmp sf
		   
		   scade_EAX:
		   sub EAX, EBX
		   jmp sf
		     
		sf:
		jmp repeta
		
		afisam:
		push DWORD EAX
		push DWORD format
		call _printf
		add ESP, 4*2
		
        push    DWORD text 
        call    _printf
        add     esp, 8
        push    0
        call    _exit
        ret 
		

section .data

	nr1 DD 15
	nr2 DD 40
	rezultat DD 0
	format DB 'Cmmdc este %d', 0
    text   DB      ' ',0 
