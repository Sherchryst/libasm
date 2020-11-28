/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/11/28 21:39:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define FT_LIST_SIZE_EXPECT(fmt) do {              \
	tmp = list_from_format(fmt);                   \
	expected = ref_ft_list_size(tmp);              \
	actual = ft_list_size(tmp);                    \
	if (expected != actual) {                      \
		printf("KO: [COMPARE]: %s: expected: %d ", \
				test_name, expected);              \
		printf("got: %d \nwith:", actual);           \
		list_print(tmp);                           \
		putchar('\n');                             \
	} else                                         \
		printf("OK: [COMPARE]: %s: expected: %d ", \
				test_name, expected);              \
		printf("got: %d \nwith:", actual);           \
		list_print(tmp);                           \
		putchar('\n');                             \
	list_destroy(tmp);                             \
} while (0);

void		test_ft_list_size(void)
{
	char		*test_name = "ft_list_size.s";
	static t_list	*tmp;
	static int 	expected;
	static int 	actual;

	FT_LIST_SIZE_EXPECT("1 2 3");
	FT_LIST_SIZE_EXPECT("");
	FT_LIST_SIZE_EXPECT("1 2 3 4 10");
	FT_LIST_SIZE_EXPECT("19879 123 12344");
	FT_LIST_SIZE_EXPECT("1");
	FT_LIST_SIZE_EXPECT("1 2");
	FT_LIST_SIZE_EXPECT("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20");
}

