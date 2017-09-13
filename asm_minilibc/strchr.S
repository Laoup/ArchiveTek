[BITS 64]

	global strchr:function

section .text

strchr:
	cmp byte [rdi], sil
	jz  end
	cmp byte [rdi], 0
	jz end_null
	inc rdi
	jmp strchr

end:
	mov rax, rdi
	ret

end_null:
	xor rax, rax
	ret
