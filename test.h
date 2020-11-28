/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/11/28 08:31:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <limits.h>
# include <stddef.h>
# include <errno.h>

# define ERRNO_WRAP(x, errno_save) do {  \
	errno = 0;                           \
	do { x; } while (0);                 \
	errno_save = errno;                  \
} while(0)


int		ft_strlen(char const *str);
char		*ft_strcpy(char *dst, char const *src);
int		ft_strcmp(char const *s1, char const *s2);
char		*ft_strdup(char const *s1);
ssize_t		ft_write(int fd, void const *buf, size_t nbyte);
ssize_t		ft_read(int fd, void *buf, size_t nbyte);

void            test_ft_strlen();
void            test_ft_strcpy();
void		test_ft_strcmp();
void		test_ft_strdup();
void		test_ft_write();
void		test_ft_read();
