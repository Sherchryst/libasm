			section	.text
			global	_ft_strlen

_ft_strlen:
			mov		rax, 0
			jmp		count
increment:
			inc		rax
count:
			cmp		BYTE [rdi + rax], 0
			jne		increment
return:
			ret
