global _ft_strcmp

; int ft_strcmp(const char *s1, const char *s2);
_ft_strcmp:
			push	r12
			push	r13
			push	rcx
			mov		r12, rdi  ; s1
			mov		r13, rsi  ; s2
			mov		rcx, -1   ; index
compare:
			inc		rcx
			cmp		byte [r12 + rcx], 0   ; check and of s1
			je		compare_end
			mov		dl, byte [r12 + rcx]
			cmp		dl, byte [r13 + rcx]  ; s1[rcx] == s2[rcx]
			je		compare
compare_end:
			xor		rax, rax
			mov		al, byte [r12 + rcx]
			sub		al, byte [r13 + rcx]
			jnc		fonction_end  ; jump end if no substraction overflow
			neg		al   ; negate al to cancel overflow
			neg		eax  ; negate the whole int since the function returns that type
fonction_end:
			pop		rcx
			pop		r13
			pop		r12
			ret
