# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 20:01:58 by sgah              #+#    #+#              #
#    Updated: 2020/03/13 20:36:39 by sgah             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			section	.text
			global	_ft_strlen

; delete RAX

_ft_strlen:
			xor		rax, rax			; i = 0
			jmp		compare
increment:
			inc		rax					; i++
compare:
			cmp		BYTE [rdi + rax], 0	; str[i] == 0
			jne		increment
done:
			ret							; return i
