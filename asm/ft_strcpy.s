	section .text
	global ft_strcpy

ft_strcpy:
	xor		rcx, rcx		;	init i = 0
	cmp		rsi, 0			;	comp param0
	jz		return			;	return if param0 = 0
	jmp		copy			;	copy

increment:
	inc		rcx;

copy:
	mov		dl, BYTE [rsi + rcx]	; change dl to first character
	mov		BYTE [rdi + rcx], dl	; copy dl into param1
	cmp		dl, 0					; is end
	jnz		increment

return:
	mov	rax, rdi;
	ret	;
