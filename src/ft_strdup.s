			section	.text
			global	_ft_strdup
			extern	_malloc

_ft_strdup:
			cmp		rdi, 0
			jz		error
init_count:
			xor		rcx, rcx
			jmp		count
increment_len:
			inc		rcx
count:
			cmp		BYTE [rdi + rcx], 0
			jne		increment_len
allocation:
			inc		rcx
			push	rdi
			mov		rdi, rcx
			call	_malloc
			pop		rdi
			cmp		rax, 0
			jz		error
init_copy:
			xor		rcx, rcx
			xor		rdx, rdx
			jmp		copy
increment_copy:
			inc		rcx
copy:
			mov		dl, BYTE [rdi + rcx]
			mov		BYTE [rax + rcx], dl
			cmp		dl, 0
			jz		return
			jmp		increment_copy
error:
			xor		rax, rax
return:
			ret
