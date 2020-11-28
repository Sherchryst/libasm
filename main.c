/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/11/28 17:53:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	clrscr()
{
	system("@cls||clear");
}

int	main(void)
{
	clrscr();
	test_ft_strlen();
	getchar();
	clrscr();
	test_ft_strcpy();
	getchar();
	clrscr();
	test_ft_strcmp();
	getchar();
	clrscr();
	test_ft_strdup();
	getchar();
	clrscr();
	test_ft_write();
	getchar();
	clrscr();
	test_ft_read();
	getchar();
	clrscr();
	test_ft_atoi_base();
	getchar();
	clrscr();
	test_ft_list_push_front();
	return (0);
}
