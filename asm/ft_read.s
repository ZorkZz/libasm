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
	neg		rax							;
	mov		rdi, rax					;
	call	__errno_location wrt ..plt	;	errno
	mov		[rax], rdi					;
	mov		rax, -1						;
	ret									;