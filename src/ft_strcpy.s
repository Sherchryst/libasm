			section	.text
			global	_ft_strcpy

_ft_strcpy:
			mov		r8, 0
			cmp		rsi, 0
			je		return
			jmp		copy
increment:
			inc		r8
copy:
			mov		al, BYTE [rsi + r8]
			mov		BYTE [rdi + r8], al
			cmp		al, 0
			jne		increment
return:
			mov		rax, rdi
			ret
