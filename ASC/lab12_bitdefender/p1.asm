[bits 32]
%include "msdn_defs.inc"
section .text 

extern  _printf
extern _exit
extern CreateFileA, ReadFile, WriteFile, SetFilePointer, CloseHandle, GetLastError


global  _main 


_main: 

        push  DWORD NULL
		push  DWORD FILE_ATTRIBUTE_NORMAL
		push  DWORD OPEN_EXISTING
		push  DWORD NULL
		push  DWORD 0
		push  DWORD GENERIC_READ|GENERIC_WRITE
		push  DWORD fileName
        call CreateFile
		
		cmp EAX, INVALID_HANDLE_VALUE
		je errorr
		mov [handle], EAX
		
		push  DWORD NULL
		push  DWORD reminder
		push  DWORD 100
		push  DWORD buffer
		push  DWORD [handle]
		call ReadFile
		
		cmp EAX, 0
		je errorr
		
		push DWORD NULL
		push DWORD noOfBytesWriten
		push DWORD bufferSizeForWrite
		push DWORD bufferForWrite
		push DWORD [handle]
		call WriteFile
		
		cmp EAX, 0
		je errorr
		
		push DWORD[handle]
		call CloseHandle
		cmp EAX, 0
		je errorr
		
		
		jmp sfarsit
		errorr:
	       call GetLastError
		   push eax
		   push    DWORD format 
		   call    _printf
           add     esp, 8
		   
		sfarsit:
        call    _exit
        ret 

		
		
section .data
	
	fileName db 'fisierulmeu.txt', 0
	format:    db      '%d', 0
	handle DD 0
	buffer TIMES 100 DD 0, 0
	reminder DD 0, 0
	bufferForWrite DD 'Ana are mere', 0
	bufferSizeForWrite EQU $-bufferForWrite
	noOfBytesWriten DD 0,
	
	