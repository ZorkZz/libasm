extern	ft_strlen
extern	malloc
extern	ft_strcpy
global	ft_strdup
section	.text

ft_strdup:

	push	rdi					;
	call	ft_strlen			;
	mov		rsi, rdi			;
	inc		rax					;
	mov		rdi, rax			;
	call	malloc	WRT ..plt	;
	cmp		rax, 0				;
	jz		error				;
	pop		rsi					;
	mov		rdi, rax			;
	call	ft_strcpy			;
	ret 						;

error:
	mov		rax, 0				;
	pop		rdi					;
	ret							;