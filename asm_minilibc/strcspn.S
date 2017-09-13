[BITS 64]

	global strcspn:function

section .text

strcspn:
   xor r8, r8

Start_L1:
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
	jz  end
   inc r8
	jmp Start_L1

; end_null:
;    mov rax, r8
; 	; xor rax, rax
; 	ret

end: mov rax, r8
	ret
