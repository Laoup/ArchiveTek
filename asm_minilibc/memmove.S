[BITS 64]

	global memmove:function

  section .text

memmove:
	push rbp
	mov rbp, rsp
	mov rcx, rdx		;size_t n loop count

L1:
	dec rcx
	mov sil, [rsi + rcx]
	mov [rdi + rcx], sil
	or rcx, 0
	jz L1

end:
	mov rax, rdi
	mov rsp, rbp
	pop rbp
	ret
