/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_push_front.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/11/28 17:45:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define FT_LIST_PUSH_FRONT_EXPECT(fmt, push) do {              \
	from = list_from_format(fmt);                              \
	expected = list_from_format(fmt);                          \
	actual = list_from_format(fmt);                            \
	ref_ft_list_push_front(&expected, create_data_elem(push)); \
	ft_list_push_front(&actual, create_data_elem(push));       \
	if (list_cmp(expected, actual) != 0) {                     \
		printf("KO: [COMPARE]: %s: expected: ", test_name);    \
		list_print(expected);                                  \
		printf(" got: ");                                      \
		list_print(actual);                                    \
		printf(" \nwith: ");                                     \
		list_print(from);                                      \
		putchar('\n');                                         \
	} else                                                     \
		printf("OK: [COMPARE]: %s: expected: ", test_name);    \
		list_print(expected);                                  \
		printf(" got: ");                                      \
		list_print(actual);                                    \
		printf(" \nwith: ");                                     \
		list_print(from);                                      \
		putchar('\n');                                         \
	list_destroy(from);                                        \
	list_destroy(expected);                                    \
	list_destroy(actual);                                      \
} while (0);

void			test_ft_list_push_front(void)
{
	char		*test_name = "ft_list_push_front.s";
	static		t_list *tmp;
	static 		t_list *expected;
	static		t_list *actual;
	static		t_list *from;


	FT_LIST_PUSH_FRONT_EXPECT("", 0);
	FT_LIST_PUSH_FRONT_EXPECT("", 1);
	FT_LIST_PUSH_FRONT_EXPECT("0", 1);
	FT_LIST_PUSH_FRONT_EXPECT("1 2 3", 4);
	FT_LIST_PUSH_FRONT_EXPECT("1 2 3", -1);
	FT_LIST_PUSH_FRONT_EXPECT("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20", 7);
}

