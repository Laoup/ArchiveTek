[BITS 64]

	global strcmp:function

section .text

strcmp:
	xor rax, rax
.loop:
	mov al, [rdi]
	mov bl, [rsi]
	sub eax, ebx
	jnz .end
	inc rdi
	inc rsi
	or bl, 0
	jnz .loop
.end:
	ret
