/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref_atoi_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/11/28 16:49:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <ctype.h>

static
bool valid_base(char *base)
{
	if (strlen(base) < 2)
		return false;
	while (*base)
	{
		if (isspace(*base) || *base == '+' || *base == '-')
			return false;
		for (int i = 1; base[i]; i++)
			if (base[i] == *base)
				return false;
		base++;
	}
	return true;
}

int ref_ft_atoi_base(char *str, char *base)
{
	long int nb;
	int radix;
	bool is_negative;

	if (!valid_base(base))
		return 0;
	while (isspace(*str))
		str++;
	is_negative = false;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			is_negative = !is_negative;
	radix = strlen(base);
	nb = 0;
	while (*str && strchr(base, *str) != NULL)
	{
		nb *= radix;
		nb += strchr(base, *str) - base;
		str++;
	}
	return is_negative ? -nb : nb;
}

