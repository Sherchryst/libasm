			section	.text
			global	ft_list_push_front
			extern	malloc

ft_list_push_front:
			push	rsp
			push	rdi		;rdi = t_list **begin
			push	rsi		;rsi = void *data
			mov		rdi, 16
			xor		rax, rax
			call	malloc wrt ..plt
			pop		rsi
			pop		rdi
			cmp		rax, 0
			jz		return
			mov		[rax], rsi
			mov		rcx, [rdi]
			mov		[rax + 8], rcx
			mov		[rdi], rax
return:
			pop		rsp
			ret
