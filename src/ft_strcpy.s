			section	.text
			global	_ft_strcpy

_ft_strcpy:
			mov		rdx, 0
			xor		rcx, rcx
			cmp		rsi, 0
			je		return
			jmp		copy
increment:
			inc		rcx
copy:
			mov		dl, BYTE [rsi + rcx]
			mov		BYTE [rdi + rcx], dl
			cmp		dl, 0
			jne		increment
return:
			mov		rax, rdi
			ret
