/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/11/28 08:21:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

#define FT_WRITE_BUF_SIZE (1 << 12)

#define FT_WRITE_EXPECT(str) do {                                                                  \
	if (pipe(ft_write_pipe) < 0)                                                                   \
		exit(EXIT_FAILURE);                                                                        \
	fcntl(ft_write_pipe[0], F_SETFL, O_NONBLOCK);                                                  \
	ERRNO_WRAP(write_origin_ret = write(ft_write_pipe[1], str, strlen(str)), write_origin_errno);  \
	read(ft_write_pipe[0], buf, FT_WRITE_BUF_SIZE);                                                \
	ERRNO_WRAP(write_ret = ft_write(ft_write_pipe[1], str, strlen(str)), write_errno);             \
	ret = read(ft_write_pipe[0], buf, FT_WRITE_BUF_SIZE);                                          \
	buf[ret] = '\0';                                                                               \
	if (write_errno != write_origin_errno)                                                         \
		printf("KO: [COMPARE]: %s: expected: errno %d got: errno %d \nwith: "#str"\n",               \
				test_name, write_origin_errno, write_errno);                                       \
	else if (strcmp(buf, str) != 0 || write_ret != write_origin_ret)                               \
		printf("KO: [COMPARE]: %s: expected: %lu \"%s\" got: %lu \"%s\" \nwith: %d, \"%s\", %zu \n", \
				test_name, strlen(str), str, write_ret, buf, ft_write_pipe[0], buf, strlen(str));  \
	else                                                                                           \
		printf("OK: [COMPARE]: %s: expected: %lu \"%s\" got: %lu \"%s\" \nwith: %d, \"%s\", %zu \n", \
				test_name, strlen(str), str, write_ret, buf, ft_write_pipe[0], buf, strlen(str));  \
	close(ft_write_pipe[1]);                                                                       \
	close(ft_write_pipe[0]);                                                                       \
} while (0);

#define FT_WRITE_EXPECT_ERROR(fd, str, size) do {                                           \
	ERRNO_WRAP(write_ret = ft_write(fd, str, size), write_errno);                           \
	ERRNO_WRAP(write_origin_ret = write(fd, str, size), write_origin_errno);                \
	if ((long)write_ret != -1)                                                              \
		printf("KO: [COMPARE]: %s: expected: %ld got: %ld \nwith: %d "#str", %d\n",           \
				test_name, -1l, (long)write_ret, fd, size);                                 \
	else if (write_errno != write_origin_errno)                                             \
		printf("KO: [COMPARE]: %s: expected: errno %d got: errno %d \nwith: %d "#str", %d\n", \
				test_name, write_origin_errno, write_errno, fd, size);                      \
	else                                                                                    \
		printf("OK: [COMPARE]: %s: expected: %ld got: %ld \nwith: %d "#str", %d\n",           \
				test_name, -1l, (long)write_ret, fd, size);                                 \
} while (0);

void		test_ft_write(void)
{
	char	*test_name = "ft_write.s";
	static int ft_write_pipe[2];
	static char buf[FT_WRITE_BUF_SIZE] = {0};
	static ssize_t write_ret;
	static ssize_t write_origin_ret;
	static int write_errno;
	static int write_origin_errno;
	static ssize_t ret;

	FT_WRITE_EXPECT("");
	FT_WRITE_EXPECT("bon");
	FT_WRITE_EXPECT("bonjour");
	FT_WRITE_EXPECT("#c#s#p#x#X#e#f#g");
	FT_WRITE_EXPECT("the\0hidden");
	FT_WRITE_EXPECT("Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.");

	FT_WRITE_EXPECT_ERROR(STDOUT_FILENO, NULL, 3);
	FT_WRITE_EXPECT_ERROR(-1, "bonjour", 7);
	FT_WRITE_EXPECT_ERROR(42, "bonjour", 7);
	FT_WRITE_EXPECT_ERROR(9809, "bonjour", 7);
	FT_WRITE_EXPECT_ERROR(98123, "", 1);
	FT_WRITE_EXPECT_ERROR(42, NULL, 7);
}

