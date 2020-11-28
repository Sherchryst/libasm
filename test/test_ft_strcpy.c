/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/11/28 07:27:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define FT_STRCPY_BUF_SIZE (1 << 12)

#define FT_STRCPY_EXPECT(str) do {             \
        strcpy(expected_buf, str);                 \
        ft_strcpy(actual_buf, str);                \
        if (strcmp(expected_buf, actual_buf) != 0) \
                printf("KO: [COMPARE]: %s: expected: \"%s\" got: \"%s\" \nwith: \"%s\"\n",\
                                test_name, expected_buf, actual_buf, expected_buf); \
        else                                       \
                printf("OK: [COMPARE]: %s: expected: \"%s\" got: \"%s\" \nwith: \"%s\"\n",\
                                test_name, expected_buf, actual_buf, expected_buf); \
} while (0);

void		test_ft_strcpy()
{
	static char	expected_buf[FT_STRCPY_BUF_SIZE] = {0};
	static char	actual_buf[FT_STRCPY_BUF_SIZE] = {0};
	char		*test_name = "ft_strcpy.s";

	FT_STRCPY_EXPECT("");
        FT_STRCPY_EXPECT("abc");
        FT_STRCPY_EXPECT("asl;fjl;asdjfjkasdl;fjadjsf");
        FT_STRCPY_EXPECT("yope\0la");
        FT_STRCPY_EXPECT("Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.");
        FT_STRCPY_EXPECT("\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f");
        FT_STRCPY_EXPECT("\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f");
}
