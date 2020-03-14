			section	.text
			global	_ft_strlen

_ft_strlen:
			mov		rax, 0
			jmp		counter
increment:
			inc		rax
counter:
			cmp		BYTE [rdi + rax], 0
			jne		increment
return:
			ret
