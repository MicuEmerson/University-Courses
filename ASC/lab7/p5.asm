;5. Being given a string of bytes representing a text (succession of words separated by spaces), 
;determine which words are palindromes(meaning may be interpreted the same way in either forward or reverse direction)
; ex.: "cojoc", "capac" etc.

assume cs:code, ds:data
data segment

	sir DB 'ana are unu sau doua mere in cojoc'
	len EQU $-sir
	rezultat DB len dup(?)
	cuvant DB len dup(?)
	aux DW (?)
	
data ends
code segment
start:
	
	mov AX, data
	mov DS, AX
	mov ES, AX
	
	mov SI, OFFSET sir
	mov DI, OFFSET cuvant
	mov BX, -1 ;indice pentru sirul 'rezultat'
	
	mov AL, sir[len]
	repeta:
	
		cmp sir[SI], 32  ; 32 este spatiu
        je verifica_palindrom  ; daca e spatiu verificam daca 'cuvant' e palindrom
		cmp SI, len
		je verifica_palindrom  ; daca am ajuns la finalul sirului verificam ultimul palindrom si iesim afara
        movsb  ; La adresa <ES:DI> se incarca octetul de la adresa <DS:SI> , DS:SI este de la 'sir' iar ES:DI este de la 'cuvant'
		inc CX ; crestem dimensiunea cuvantului
		jmp repeta ; daca nu a intrat pe jumpurile de palindrom nu verificam nimic


        verifica_palindrom:
			mov aux, SI ; salvam indicele sirului 'sir' pentru ca el vine decrementat
			inc BX ; crestem indicele sirulul 'rezultat'
		    mov rezultat[BX], '1' ; il consideram ca si palindrom prima data, pe urma il punem pe 0 in caz ca nu sunt egale
			mov BP, 0 ; indicele sirului 'cuvant'
			mov DI, OFFSET cuvant ; punem DI (indicele sirului 'cuvant') pe prima pozitie
			dec SI   ; ca sa fie compararea literelor corecta
			
			repeta2:
				mov AL, sir[SI]
				mov AH, cuvant[BP]
				cmp AL, AH
			    je e_bun ; daca 'e_bun' atunci sarim peste rezultat[BX] = 0 care semnifica ca, cuvantul nu e palindrom
				mov rezultat[BX], '0'
				e_bun:
				dec SI
				inc BP 
			loop repeta2
			
			mov SI, aux ; SI-ul l-am decrementat si il punem pe pozitia de unde am inceput sa il decrementam
			cmp SI, len ; comparam sa vedem daca nu cumva am ajuns la final si
			je am_terminat  ; daca am ajuns la final putem sa incheiem programul
			inc SI ; daca nu am ajuns la final, crestem SI-ul cu 1 ca sa sarim peste spatiu
				
	jmp repeta ; o bucla infinita din care o sa iesim doar cu un jump
	
	
	
	
	am_terminat:
	mov ax, 4c00h
	int 21h
	
		
code ends
end start