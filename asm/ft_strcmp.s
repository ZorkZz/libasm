	section .text
	global ft_strcmp

ft_strcmp:
	xor		rcx, rcx			;	init i = 0
	xor		rax, rax			;	init ret
	cmp		rsi, 0				;	comp param0
	jz		isNull				;	return if param0 = 0
	cmp		rdi, 0				;	comp param0
	jz		isNull				;	return if param0 = 0
	jmp		compare				;	copy

isNull:
	cmp		rsi, rdi			;
	jz		zero				; null
	jg		sup					; s1>
	jmp		inf					; s1<

increment:
	inc		rcx					;
	jmp		compare				;

checkFirst:
	mov		dl, BYTE[rsi + rcx]	;
	cmp		dl, 0				;
	jz		zero				;
	jmp		inf					;

checkSecond:
	mov		dl, BYTE[rdi + rcx]	;
	cmp		dl, 0				;
	jz		zero				;
	jmp		sup					;

compare:
	mov		dl, BYTE[rsi + rcx]	; 
	cmp		dl, 0				;
	jz		checkSecond			;
	mov		dl, BYTE[rdi + rcx]	;
	cmp		dl, 0				;
	jz		checkFirst			;	check if end of str
	mov		dl, BYTE[rsi + rcx]	;
	cmp		dl, BYTE[rdi + rcx]	;
	jb		sup					;
	ja		inf					;	check if sup or inf
	jmp		increment			;

zero:
	mov		rax, 0				;
	jmp		return				;

sup:
	mov		rax, 1				;
	jmp		return				;

inf:
	mov		rax, -1				;
	jmp		return				;

return:
	ret							;