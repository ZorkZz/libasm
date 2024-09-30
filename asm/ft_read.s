extern	__errno_location
global	ft_read
section	.text

ft_read:
	mov		rax, 0	;	syscall write
	syscall			;
	cmp		rax, 0	;
	jl		error	;
	ret				;

error:
	call	__errno_location wrt ..plt	;	errno
	mov		rax, -1						;
	ret									;