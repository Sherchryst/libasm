			section	.text
			global	_ft_strcmp
_ft_strcmp:
			mov		rdx, 0
			xor		rcx, rcx
			cmp		rdi, 0
			jz		null_case
			cmp		rsi, 0
			jz		null_case
			compare:
					cmp		BYTE [rdi + rcx], 0
					jz		null_term
					cmp		BYTE [rsi + rcx], 0
					jz		null_term
					mov		dl, BYTE [rdi + rcx]
					cmp		dl, BYTE [rsi + rcx]
					jl		inf_case
					jg		sup_case
					inc		rcx
					jmp		compare
null_term:
			mov		dl, BYTE [rdi + rcx]
			sub		dl, BYTE [rsi + rcx]
			cmp		dl, 0
			jz		equal_case
			jl		inf_case
null_case:
			cmp		rdi, rsi
			jl		inf_case
			jg		sup_case
			je		equal_case
inf_case:
			mov		rax, -1
			ret
sup_case:
			mov		rax, 1
			ret
equal_case:
			mov		rax, 0
			ret
