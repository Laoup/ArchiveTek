[BITS 64]

	global strpbrk:function

section .text

strpbrk:
	
	xor rcx, rcx

L1:	
	mov al, [rdi]
	cmp byte [rsi + rcx], 0
	jz  end_loop
	cmp byte al, [rsi + rcx]
	jz  end
	inc rcx
	jmp L1
	
end_loop:
	inc rdi
	cmp byte [rdi], 0
	jz  end_null
	jmp strpbrk

end_null:
	xor rax, rax
	ret

end:	mov rax, rdi
	ret
