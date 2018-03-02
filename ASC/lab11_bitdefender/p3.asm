[bits 32]

section .text
    
	
extern  _printf
extern _exit

global  _main 

   
_main:
        mov ESI, 0
		mov ECX, len
		mov EBX, 0
		repeta:
		    
			mov EAX, array[ESI]
			
			cmp EAX, 0
			jge pozitiv
			neg EAX
			
			pozitiv:
			  add EBX, EAX
			  

		add ESI, 4
		loop repeta
		
		
		
		afisam:
		push DWORD EBX
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

	array DD 1, -10, 5, 2, 5, 0, -9, 17
	len EQU ($-array) / 4
	rezultat DD 0
	format DB 'Suma modulelor este %d', 0
    text   DB      ' ',0 
