[BITS 64]

	global strlen:function

section .text

strlen:
	push rsi
	push rdi
	mov rax, 0		;set counter a 0
	mov rdi, rdi		;get the str
	
boucle:	
	cmp byte [rdi], 0	;cherche le caractere de fin
	jz  end
	inc rax
	inc rdi
	jmp boucle

end:
	pop rdi
	pop rsi
	ret
