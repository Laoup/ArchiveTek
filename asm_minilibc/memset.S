[BITS 64]

	global memset:function

section .text

memset:
	push rdi
	xor rcx, rcx
	mov rcx, rdx
	mov rdx, 0

L1:
	cmp rcx, 0
	jz  end
	mov [rdi + rdx], sil
	inc rdx
	loop L1

end:
	pop rdi
	mov rax, rdi
	ret
