[BITS 64]

	global strncmp:function

section .text

strncmp:
	push rbp		;prologue
	mov  rbp, rsp
	
	xor  rax, rax		;resultat a 0
	xor  rcx, rcx		;counter at 0
	mov  rcx, rdx		;counter at size_t arg3

L1:
	mov al, [rdi]		;store char
	mov bl, [rsi]		;store char
	sub eax, ebx		;comparaison
	jnz end
	inc rdi
	inc rsi
	dec ecx
	or  ecx, 0		;if ecx == 0
	jnz L1
	xor rax, rax

end:
	mov rsp, rbp		;epilogue
	pop rbp
	ret
