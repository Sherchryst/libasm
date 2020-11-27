			section	.text
			global	ft_strlen

ft_strlen:
			mov		rax, 0
			jmp		count
increment:
			inc		rax
count:
			cmp		BYTE [rdi + rax], 0
			jne		increment
return:
			ret
