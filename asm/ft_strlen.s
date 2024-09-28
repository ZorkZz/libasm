	section .text
	global ft_strlen

ft_strlen:
	xor		rax, rax	; i = 0
	jmp		compare		; compare

increment:
	inc		rax			; i++

compare:
	cmp		BYTE[rdi + rax], 0; compare if last char
	jne		increment;

return:
	ret	;