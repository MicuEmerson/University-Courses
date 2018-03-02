;2. Se dau doua siruri de octeti S1 si S2 de aceeasi lungime.
;Sa se construiasca sirul D astfel: fiecare element de pe pozitiile pare din D este suma elementelor de pe pozitiile corespunzatoare din S1 si S2,
; iar fiecare element de pe pozitiile impare are ca si valoare diferenta elementelor de pe pozitiile corespunzatoare din S1 si S2.
;Exemplu:
;S1: 1, 2, 3, 4
;S2: 5, 6, 7, 8
;D: 6, -4, 10, -4

ASSUME cs: code, ds:data

data SEGMENT  
    S1 db 1,2,3,4
	S2 db 5,6,7,8
	len EQU $-S2
	D db len dup(?)
	doi db 2
	
data ENDS

code SEGMENT
start:
   mov AX, data    
   mov DS, AX
   
   mov CX, len
   mov SI, 0
   jcxz Sfarsit
   
   Repeta:
		mov BL, S1[SI]
		mov BH, S2[SI]
		
		mov AX, SI
		div doi
		cmp AH, 0
		jz este_par
		jnz este_impar
		
		este_par:
			add BL, BH
			mov D[SI], BL
			inc SI
			loop Repeta  
			
		este_impar:
		    sub BL, BH
			mov D[SI], BL
			inc SI
			loop Repeta  
		
	
   Sfarsit:
   mov AX, 4C00h
   int 21h
   
code ENDS
END start