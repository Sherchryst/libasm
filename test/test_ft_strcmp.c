/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/11/28 07:31:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

# define FT_STRCMP_EXPECT(s1, s2) do { \
        strcmp_expected = strcmp(s1, s2); \
        strcmp_actual = ft_strcmp(s1, s2); \
        if ((strcmp_expected < 0 && strcmp_actual < 0) || \
            (strcmp_expected > 0 && strcmp_actual > 0) || \
            (strcmp_expected == 0 && strcmp_actual == 0)) \
                printf("OK: [COMPARE]: ft_strcmp.s: expected: %d got: %d with: "#s1", "#s2"\n", \
                           strcmp_expected, strcmp_actual); \
        else \
                printf("KO: [COMPARE]: ft_strcmp.s: expected: %d got: %d with: "#s1", "#s2"\n", \
                           strcmp_expected, strcmp_actual); \
} while (0);

void		test_ft_strcmp(void)
{
	int strcmp_expected;
	int strcmp_actual;
	char	*test_name = "ft_strcmp.s";

	        FT_STRCMP_EXPECT("", "");
        FT_STRCMP_EXPECT("bon", "");
        FT_STRCMP_EXPECT("bonjour", "");
        FT_STRCMP_EXPECT("asdklfjasdfj////asdf'''asdf3##", "");
        FT_STRCMP_EXPECT("the\0hidden", "");
        FT_STRCMP_EXPECT("Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.", "");
        FT_STRCMP_EXPECT("", "");
        FT_STRCMP_EXPECT("bon", "bon");
        FT_STRCMP_EXPECT("bonjour", "bonjour");
        FT_STRCMP_EXPECT("asdklfjasdfj////asdf'''asdf3##", "asdklfjasdfj////asdf'''asdf3##");
        FT_STRCMP_EXPECT("the\0hidden", "the\0hidden");
        FT_STRCMP_EXPECT("Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.",
"Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.");
	FT_STRCMP_EXPECT("", "asdf");
        FT_STRCMP_EXPECT("bon", "bo");
        FT_STRCMP_EXPECT("bonjour", "onjour");
        FT_STRCMP_EXPECT("asdklfjasdfj////asdf'''asdf3##", "asdklfjasdfj////asdf'''asdf3##");
        FT_STRCMP_EXPECT("the\0hidden", "thehidden");
        FT_STRCMP_EXPECT("Lorem ipsum dolor st amet, consectetur adipiscing", "Lodsfsdfasdf");

        FT_STRCMP_EXPECT("\x01", "\x01");
        FT_STRCMP_EXPECT("\x02", "\x01");
        FT_STRCMP_EXPECT("\x01", "\x02");
        FT_STRCMP_EXPECT("\xff", "\xff");
        FT_STRCMP_EXPECT("\xfe", "\xff");
        FT_STRCMP_EXPECT("\xff", "\xfe");

        FT_STRCMP_EXPECT("\x01\x01", "\x01");
        FT_STRCMP_EXPECT("\x01\x02", "\x01");
        FT_STRCMP_EXPECT("\x02\x01", "\x02");
        FT_STRCMP_EXPECT("\xff\xff", "\xff");
        FT_STRCMP_EXPECT("\xff\xfe", "\xff");
        FT_STRCMP_EXPECT("\xfe\xff", "\xfe");

        FT_STRCMP_EXPECT("\x01", "\x01\x01");
        FT_STRCMP_EXPECT("\x01", "\x01\x02");
        FT_STRCMP_EXPECT("\x02", "\x02\x01");
        FT_STRCMP_EXPECT("\xff", "\xff\xff");
        FT_STRCMP_EXPECT("\xff", "\xff\xfe");
        FT_STRCMP_EXPECT("\xfe", "\xfe\xff");
}
