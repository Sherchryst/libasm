			section	.text
			global	_ft_list_size
_ft_list_size:
			mov		rsi, rdi
			xor		rax, rax
			jmp		counter
increment:
			inc		rax
counter:
			cmp		rdi, 0
			jz		return
			mov		rdi, [rdi + 8]
			jmp		increment
return:
			mov		rdi, rsi
			ret
