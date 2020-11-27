			section	.text
			global	ft_write
			extern	__errno_location

ft_write:
			mov		rax, 1
			syscall
			cmp		rax, 0
			jl		error
			ret

error:
			neg		rax
			mov		rdi, rax		; save errno
			call		__errno_location wrt ..plt	; retrieve address to errno_location
			mov		[rax], rdi		; put errno in pointer to errno (return value of __errno_location)
			mov		rax, -1
			ret
