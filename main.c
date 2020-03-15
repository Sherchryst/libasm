/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/03/15 04:26:51 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int		ft_strlen(char const *str);

char	*ft_strcpy(char *dst, char const *src);

int		ft_strcmp(char const *s1, char const *s2);

void		test_ft_strcmp()
{
	printf("\x1b[32mft_strcmp :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'' ''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("", ""));
	printf("		\x1b[33mft_ libasm\x1b[0m  %d\n", ft_strcmp("", ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'qwertyuiop' 'qwertyuiop'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("qwertyuiop", "qwertyuiop"));
	printf("		\x1b[33mft_ libasm\x1b[0m  %d\n", ft_strcmp("qwertyuiop", "qwertyuiop"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'qwertyuiop' ''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("qwertyuiop", ""));
	printf("		\x1b[33mft_ libasm\x1b[0m  %d\n", ft_strcmp("qwertyuiop", ""));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'' 'qwertyuiop'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %d\n", strcmp("", "qwertyuiop"));
	printf("		\x1b[33mft_ libasm\x1b[0m %d\n", ft_strcmp("", "qwertyuiop"));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'qwertyuioptest' 'qwertyuiop'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("qwertyuioptest", "qwertyuiop"));
	printf("		\x1b[33mft_ libasm\x1b[0m  %d\n", ft_strcmp("qwertyuioptest", "qwertyuiop"));
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'bbbonjour' 'bbonjour'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %d\n", strcmp("bbbonjour", "bbonjour"));
	printf("		\x1b[33mft_ libasm\x1b[0m %d\n", ft_strcmp("bbbonjour", "bbonjour"));
	printf("	\x1b[34m[7]\x1b[0m \x1b[36m'NULL' 'bbonjour'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33mft_ libasm\x1b[0m %d\n", ft_strcmp(NULL, "bbonjour"));
	printf("	\x1b[34m[8]\x1b[0m \x1b[36m'NULL' 'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33mft_ libasm\x1b[0m %d\n", ft_strcmp(NULL, NULL));
	printf("	\x1b[34m[9]\x1b[0m \x1b[36m'' 'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33mft_ libasm\x1b[0m %d\n", ft_strcmp("", NULL));
}

void		test_ft_strcpy()
{
	char	dst[100];

	printf("\x1b[32mft_strcpy :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, ""));
	printf("		\x1b[33mft_ libasm\x1b[0m  %s\n", ft_strcpy(dst, ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'qwertyuiop'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "qwertyuiop"));
	printf("		\x1b[33mft_ libasm\x1b[0m  %s\n", ft_strcpy(dst, "qwertyuiop"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789abcdefg'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "0123456789abcdefg"));
	printf("		\x1b[33mft_ libasm\x1b[0m  %s\n", ft_strcpy(dst, "0123456789abcdefg"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33mft_ libasm\x1b[0m  %s\n", ft_strcpy(dst, NULL));
}

void		test_ft_strlen()
{
	printf("\x1b[32mft_strlen :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %zu\n", strlen(""));
	printf("		\x1b[33mft_ libasm\x1b[0m  %d\n", ft_strlen(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'    '\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %zu\n", strlen("    "));
	printf("		\x1b[33mft_ libasm\x1b[0m  %d\n", ft_strlen("    "));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789abcdefg'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %zu\n", strlen("0123456789abcdefg"));
	printf("		\x1b[33mft_ libasm\x1b[0m  %d\n", ft_strlen("0123456789abcdefg"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33mft_ libasm\x1b[0m  %s\n", "SEGMENTATION FAULT");
}

int			main(int argc, char *argv[])
{
	if (argc == 1 || !strcmp(argv[1], "ft_strlen"))
		test_ft_strlen();
	if (argc == 1 || !strcmp(argv[1], "ft_strcpy"))
		test_ft_strcpy();
	if (argc == 1 || !strcmp(argv[1], "ft_strcmp"))
		test_ft_strcmp();
}
