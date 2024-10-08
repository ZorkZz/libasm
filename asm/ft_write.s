extern	__errno_location
global	ft_write
section	.text

ft_write:
	mov		rax, 1	;	syscall write
	syscall			;
	cmp		rax, 0	;
	jl		error	;
	ret				;

error:
	call	__errno_location wrt ..plt	;	errno
	mov		rax, -1						;
	ret									;