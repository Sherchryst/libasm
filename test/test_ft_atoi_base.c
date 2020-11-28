/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/11/28 16:20:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define TO_STRING(x) (#x)

#define FT_ATOI_BASE_EXPECT(str, base) do {      \
	actual_ret = ft_atoi_base(str, base);        \
	expected_ret = ref_ft_atoi_base(str, base);  \
	if (actual_ret != expected_ret)              \
		printf("KO: [COMPARE]: %s: expected: %d got: %d \nwith: "#str", "#base"\n", \
				test_name, expected_ret, actual_ret); \
	else                                         \
		printf("OK: [COMPARE]: %s: expected: %d got: %d \nwith: "#str", "#base"\n", \
				test_name, expected_ret, actual_ret); \
} while (0);

void test_ft_atoi_base(void)
{
	static int 	expected_ret;
	static int 	actual_ret;
	char		*test_name = "ft_atoi_base.s";

	FT_ATOI_BASE_EXPECT("", "");
	FT_ATOI_BASE_EXPECT("10", "");
	FT_ATOI_BASE_EXPECT("", "01");
	FT_ATOI_BASE_EXPECT("123", "0123456789");
	FT_ATOI_BASE_EXPECT("101", "01");
	FT_ATOI_BASE_EXPECT("ffe0", "0123456789abcdef");
	FT_ATOI_BASE_EXPECT("\t\n\r\v\f\r 4", "01234");
	FT_ATOI_BASE_EXPECT("45", "");
	FT_ATOI_BASE_EXPECT("45", "0");
	FT_ATOI_BASE_EXPECT("45", "01");
	FT_ATOI_BASE_EXPECT("10", "011");
	FT_ATOI_BASE_EXPECT("10", "0+");
	FT_ATOI_BASE_EXPECT("10", "-0");
	FT_ATOI_BASE_EXPECT("10111", "\t541");
	FT_ATOI_BASE_EXPECT("10111", "98\n541");
	FT_ATOI_BASE_EXPECT("10111", "7\r541");
	FT_ATOI_BASE_EXPECT("10111", "0\v541");
	FT_ATOI_BASE_EXPECT("10111", "1\f541");
	FT_ATOI_BASE_EXPECT("10111", "54 1");
	FT_ATOI_BASE_EXPECT("111000", "01");
	FT_ATOI_BASE_EXPECT("ff", "0123456789abcdef");
	FT_ATOI_BASE_EXPECT("52", "01234567");
	FT_ATOI_BASE_EXPECT("2a", "0123456789abcdef");
	FT_ATOI_BASE_EXPECT("7fffffff", "0123456789abcdef");
	FT_ATOI_BASE_EXPECT("ff", "0123-456789abcdef");
	FT_ATOI_BASE_EXPECT("ff", "01\r23456789abcdef");
	FT_ATOI_BASE_EXPECT("ff", "abcc");
	FT_ATOI_BASE_EXPECT("ff", "");
	FT_ATOI_BASE_EXPECT("ff", "a");
	FT_ATOI_BASE_EXPECT("-ff", "0123456789abcdef");
	FT_ATOI_BASE_EXPECT("--ff", "0123456789abcdef");
	FT_ATOI_BASE_EXPECT("+--ff", "0123456789abcdef");
	FT_ATOI_BASE_EXPECT("-++++++-+--ff", "0123456789abcdef");
	FT_ATOI_BASE_EXPECT("-++++++-+--ff\xff", "0123456789abcdef");
	FT_ATOI_BASE_EXPECT("-+\r++-+--ff\xff", "0123456789abcdef");
	FT_ATOI_BASE_EXPECT("-01", "01");
	FT_ATOI_BASE_EXPECT("--11101", "01");
	FT_ATOI_BASE_EXPECT("+-123", "01");
	FT_ATOI_BASE_EXPECT("-++++01++-+--ff", "01");
	FT_ATOI_BASE_EXPECT("-++10101\xff", "01");
	FT_ATOI_BASE_EXPECT("-+\r++-+--01\x01", "01");
	FT_ATOI_BASE_EXPECT("a\0bb", "ab");
	FT_ATOI_BASE_EXPECT("-b\0bb", "ab");
	FT_ATOI_BASE_EXPECT(" \t\n\r-++++++-+--ff\xff", "0123456789abcdef");
	FT_ATOI_BASE_EXPECT("  -+\r++-+--ff\xff", "0123456789abcdef");
	FT_ATOI_BASE_EXPECT("\n-01", "01");
	FT_ATOI_BASE_EXPECT("\x0b--11101", "01");
	FT_ATOI_BASE_EXPECT(" 755x+", "01234567");
	FT_ATOI_BASE_EXPECT(" 700chmod", "01234567");
	FT_ATOI_BASE_EXPECT(" 644yo", "01234567");
	FT_ATOI_BASE_EXPECT(TO_STRING(INT_MAX), "0123456789");
	FT_ATOI_BASE_EXPECT(TO_STRING(INT_MIN), "0123456789");
}
