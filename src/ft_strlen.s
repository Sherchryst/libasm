# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/13 20:01:58 by sgah              #+#    #+#              #
#    Updated: 2020/03/14 02:47:06 by sgah             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			section	.text
			global	_ft_strlen

_ft_strlen:
			mov		rax, 0
			jmp		compare
increment:
			inc		rax
compare:
			cmp		BYTE [rdi + rax], 0
			jne		increment
done:
			ret
