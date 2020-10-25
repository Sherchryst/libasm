			section	.text
			global	_ft_read
			extern	___error

_ft_read:
			mov		rax, 0x2000003
			syscall
			jc		error
			ret

error:
			mov	r15, rax		; save errno
			push	r15
			call	___error		; retrieve address to errno
			pop	r15
			mov	[rax], r15		; put errno in pointer to errno (return value of __error)
			mov	rax, -1
			ret
