[BITS 64]

	global strstr:function

section .text

strstr:
	cmp byte [rsi], 0
	jz  end_full
	xor rax, rax
	xor rcx, rcx
	xor rdx, rdx

L1:
	cmp byte [rdi + rcx], 0	;check actual char != \0
	jz  end
	mov al, [rsi + rdx]
	cmp [rdi + rcx], al	;check if str == sub_str
	jz  pre_equality
	inc rcx
	jmp L1

pre_equality:
	mov r8, rcx		;transfer rcx in r8
	
equality:
	cmp byte [rsi + rdx], 0	;end of substring ?
	jz  end_ok
	mov al, [rsi + rdx]
	;; mov r9, [rdi + r8]
	cmp [rdi + r8], al	;cmp actual char
	jnz end_equality
	inc r8
	inc rdx
	jmp equality
	
end:
	xor rax, rax 
	ret

end_ok:
	add rdi, rcx
	mov rax, rdi
	ret

end_equality:
	;; mov rcx, r8
	inc rcx
	xor rdx, rdx
	jmp L1

end_full:
	mov rax, rdi
	ret
