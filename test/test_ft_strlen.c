/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/11/28 07:27:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define FT_STRLEN_EXPECT(str) do {            \
        actual = ft_strlen(str);                  \
        expected = strlen(str);                   \
        if (actual != expected)                   \
                printf("KO: [COMPARE]: %s: expected: %d got: %d \nwith: "#str"\n", \
                                test_name, expected, actual); \
        else                                      \
                printf("OK: [COMPARE]: %s: expected: %d got: %d \nwith: "#str"\n", \
                                test_name, expected, actual); \
} while (0);


void		test_ft_strlen()
{
	char	*test_name = "ft_strlen.s";
	int	expected;
	int	actual;

        FT_STRLEN_EXPECT("");
        FT_STRLEN_EXPECT("bon");
        FT_STRLEN_EXPECT("bonjour");
        FT_STRLEN_EXPECT("asdfasdf''///##!!@");
        FT_STRLEN_EXPECT("the\0hidden");
        FT_STRLEN_EXPECT("Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.");
	
}
