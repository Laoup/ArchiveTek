[BITS 64]

	global rindex:function

section .text

rindex:
	xor rax, rax
	xor rcx, rcx
	xor r8, r8
	cmp rsi, 0
	jz  L_0
	
L1:
	mov al, [rdi + rcx]
	sub al, sil
	jz  pt_save
	mov al, [rdi + rcx]
	or  al, 0
	jz  end
	inc rcx
	jmp L1

end:
	or r8, 0
	jz end_null
	add rdi, rdx
	mov rax, rdi;mov rax, [rdi - rcx + rdx]
	ret

end_null:
	ret

L_0:	
	mov al, [rdi]
	sub al, 0
	jz end_0
	inc rdi
	jmp L_0

end_0:
	mov rax, rdi
	ret
	
pt_save:
	mov rdx, rcx
	mov r8, 1
	inc rcx
	jmp L1
