[BITS 64]

	global strcasecmp:function

section .text

strcasecmp:
	xor rax, rax
	xor rcx, rcx
	xor r9, r9

L1:
	mov al, [rdi + rcx]
	cmp byte [rdi + rcx], 0
	jz  start_strcmp
	sub al, 90
	jnge up
EL1:
	inc ecx			;inc rdi
	jmp L1

up:				;upper_case
	mov al, [rdi + rcx]
	sub al, 65
	jnge EL1
	xor byte [rdi + rcx], 32		;add [rdi], 32
	jmp L1

swap:				;r8 = 1er arg / rdi = 2eme arg
	mov r8, rdi
	mov rdi, rsi
	inc r9
	jmp L1
	
start_strcmp:			;call swap one time and strcmp one time
	xor rcx, rcx
	or  r9, 0
	jz  swap
	mov rsi, rdi		;1er arg = rdi / 2eme arg = rsi
	mov rdi, r8
	jmp my_strcmp 
	

my_strcmp:
	xor rax, rax
	xor rbx, rbx
.L1:
	mov al, [rdi]
	mov bl, [rsi]
	sub eax, ebx
	jnz .end
	inc rdi
	inc rsi
	or  bl, 0
	jnz .L1

.end:
	ret
