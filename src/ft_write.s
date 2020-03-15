			section	.text
			global	_ft_write

_ft_write:
	push r8
	push r9
	cmp rsi, 0
	jz _error
	mov r8, rsi
	mov r9, rdx
	mov rsi, 0x0
	mov rax, 0x20000BD
	syscall
	cmp rax, 9
	jz _error
	mov rsi, r8
	mov rdx, r9
	mov rax, 0x2000004
	syscall
	pop r8
	pop r9
	ret

_error:
	mov rax, -1 ; return -1 because error
	pop r8
	pop r9
	ret
