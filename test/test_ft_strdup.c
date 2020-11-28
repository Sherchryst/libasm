/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/11/28 07:54:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define FT_STRDUP_EXPECT(str) do {            \
        tmp = ft_strdup(str);                     \
        if (tmp == NULL || strcmp(str, tmp) != 0) \
                printf("KO: [COMPARE]: %s: expected: \"%s\" got: \"%s\"\n", test_name, str, tmp); \
        else                                      \
                printf("OK: [COMPARE]: %s: expected: \"%s\" got: \"%s\"\n", test_name, str, tmp); \
        free(tmp);                                \
} while (0);


void	test_ft_strdup(void)
{
	static char	*tmp;
	char		*test_name = "ft_strdup.s";

        FT_STRDUP_EXPECT("");
        FT_STRDUP_EXPECT("abc");
        FT_STRDUP_EXPECT("asl;fjl;asdjfjkasdl;fjadjsf");
        FT_STRDUP_EXPECT("yope\0la");
        FT_STRDUP_EXPECT("Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.");
        FT_STRDUP_EXPECT("\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f");
        FT_STRDUP_EXPECT("\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f");
}

