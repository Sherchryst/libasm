			section	.text
			global	_ft_write
			extern	___error

_ft_write:
			mov	rax, 0x2000004
			syscall
			jc	error
			ret
error:
			mov	r15, rax		; save errno 
			push	r15
			call	___error		; retrieve address to errno
			pop	r15
			mov	[rax], r15		; put errno in return value of __error (pointer to errno)
			mov	rax, -1
			ret
