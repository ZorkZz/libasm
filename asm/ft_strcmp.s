	section .text
	global ft_strcmp

ft_strcmp:
	xor		rcx, rcx		;	init i = 0
	xor		rax, rax		;	init ret
	xor		r8b, r8b		
	xor		r9b, r9b		
	cmp		rsi, 0			;	comp param0
	jz		isNull			;	return if param0 = 0
	cmp		rdi, 0			;	comp param0
	jz		isNull			;	return if param0 = 0
	jmp		comp			;	copy

isNull:
	cmp		rsi, rdi;
	jz		zero; null
	jg		sup; s1>
	jmp		inf; s1<

increment:
	inc		rcx;

comp:
	jmp		isCharNull

isEnd:
	mov		r8b, BYTE [rsi + rcx]
	mov		r9b, BYTE [rdi + rcx]
	cmp		r8b, 0;
	jz		end1;
	cmp		r9b, 0;
	jz		end2;
	jmp		increment;
	jmp		comp;

end1:
	mov		r9b, BYTE [rdi + rcx]
	cmp		r9b, 0
	jz		zero
	jmp		sup

end2:
	mov		r8b, BYTE [rsi + rcx]
	cmp		r8b, 0
	jz		zero
	jmp		inf

isCharNull:
	mov		r8b, BYTE [rsi + rcx]
	mov		r9b, BYTE [rdi + rcx]
	cmp		r8b, r9b;
	jz		isEnd; null
	jl		inf; s1<
	jg		sup; s1>

zero:
	mov		rax, 0;
	jmp		return;

sup:
	mov		rax, 1;
	jmp		return;

inf:
	mov		rax, -1;
	jmp		return;
return:
	ret	;
