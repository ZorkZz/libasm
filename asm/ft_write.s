	section .text
    global ft_write

ft_write:
						;	call write
	mov eax, 4			;	syscall
	mov ebx, rdi		;	fd
	mov ecx, rsi		;	message address
	mov edx, rcx		;	length
	int 0x80			;	call
