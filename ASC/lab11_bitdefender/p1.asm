[bits 32]

section .text
    
	
extern  _printf
extern _exit

global  _main 

   
_main:
        mov EAX, [nr1]
		add [rezultat], EAX
		mov EBX, [nr2]
		add [rezultat], EAX
		
		push DWORD [rezultat]
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

	nr1 DD 100
	nr2 DD 123
	rezultat DD 0
	format DB 'Suma este %d', 0
    text   DB      'hello?',0 
