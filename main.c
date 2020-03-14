/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/03/14 04:14:38 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int		ft_strlen(char const *str);

int		main(void)
{
	printf("--strlen\n");
	printf("`%s` = %d (%d)\n", "", ft_strlen(""), (int)strlen(""));
	printf("`%s` = %d (%d)\n", "tototo", ft_strlen("tototo"),
											(int)strlen("tototo"));
	printf("`%s` = %d (%d)\n", "abcdefghijklmnopqrstuvwxyz", ft_strlen\
	("abcdefghijklmnopqrstuvwxyz"), (int)strlen("abcdefghijklmnopqrstuvwxyz"));
	printf("`%s` = %d (%d)\n", "0123456789abcdef",
			ft_strlen("0123456789abcdef"), (int)strlen("0123456789abcdef"));
	printf("`%s` = %d (%d)\n", "1", ft_strlen("1"), (int)strlen("1"));
	printf("-done\n");
	return (0);
}
