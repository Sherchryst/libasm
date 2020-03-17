/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:48:09 by sgah              #+#    #+#             */
/*   Updated: 2020/03/17 17:16:29 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

# define ATOI_BASE(s, b)	i = ft_atoi_base(s, b); printf("		\x1b[33mft_ atoi_base\x1b[0m  '%s', [%s] = %d\n", s, b, i);

int		ft_atoi_base(char const *str, char const *base);

void	test_ft_atoi_base(void)
{
	int	i = 0;
	printf("\x1b[32mft_atoi_base:\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36mtest base decimal\x1b[0m\n");
	ATOI_BASE("42", "0123456789")
	ATOI_BASE("0", "0123456789")
	ATOI_BASE("1", "0123456789")
	ATOI_BASE("1215415478", "0123456789")
	ATOI_BASE("-0", "0123456789")
	ATOI_BASE("-1", "0123456789")
	ATOI_BASE("-42", "0123456789")
	ATOI_BASE("--42", "0123456789")
	ATOI_BASE("-+-42", "0123456789")
	ATOI_BASE("-+-+-+42", "0123456789")
	ATOI_BASE("-+-+-+-42", "0123456789")
	ATOI_BASE("-1215415478", "0123456789")
	ATOI_BASE("2147483647", "0123456789")
	ATOI_BASE("2147483648", "0123456789")
	ATOI_BASE("-2147483648", "0123456789")
	ATOI_BASE("-2147483649", "0123456789")
	printf("	\x1b[34m[2]\x1b[0m \x1b[36mtest base hexadecimal\x1b[0m\n");
	ATOI_BASE("2a", "0123456789abcdef")
	ATOI_BASE("ff", "0123456789abcdef")
	printf("	\x1b[34m[3]\x1b[0m \x1b[36mtest random base\x1b[0m\n");
	ATOI_BASE("poney", "poney")
	ATOI_BASE("dommage", "invalid")
	ATOI_BASE("dommage", "aussi invalide")
	ATOI_BASE("dommage", "+toujours")
	ATOI_BASE("dommage", "-stop")
	ATOI_BASE("dommage", "  \t\nca suffit")
	printf("	\x1b[34m[4]\x1b[0m \x1b[36mtest parsing\x1b[0m\n");
	ATOI_BASE("    +42", "0123456789")
 	ATOI_BASE("    -42", "0123456789")
	ATOI_BASE("    42", "0123456789")
	ATOI_BASE("  \t\n\r\v\f  42", "0123456789")
	ATOI_BASE("  \t\n\r\v\f  -42", "0123456789")
	ATOI_BASE("42FINIS !", "0123456789")
	ATOI_BASE("-42FINIS !", "0123456789")
	ATOI_BASE("C'est dommage42", "0123456789")
}

int		main(void)
{
	test_ft_atoi_base();
	return (0);
}
