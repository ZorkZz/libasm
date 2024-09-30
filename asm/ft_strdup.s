extern	ft_strlen
extern	malloc
extern	ft_strcpy
global	ft_strdup
section	.text

ft_strdup:
	mov		rbp, rsp	;
	call	ft_strlen	;
	mov		rsi, rdi	;
	mov		rax, rdi	;
	call	malloc		;
	cmp		rax, 0		;
	jz		error		;
	mov		rdi, rax	;
	call	ft_strcpy	;
	
	ret ;

error:
	mov		rax, -1		;
	ret					;