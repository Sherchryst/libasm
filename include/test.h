/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/11/28 22:01:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

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

int			ref_ft_atoi_base(char *str, char *base);

int			ft_strlen(char const *str);
char			*ft_strcpy(char *dst, char const *src);
int			ft_strcmp(char const *s1, char const *s2);
char			*ft_strdup(char const *s1);
ssize_t			ft_write(int fd, void const *buf, size_t nbyte);
ssize_t			ft_read(int fd, void *buf, size_t nbyte);

int			ft_atoi_base(const char *str, const char *base);
typedef struct		s_list
{
	void		*data;
	struct	s_list	*next;
}			t_list;

void			ref_ft_list_push_front(t_list **begin_list, void *data);
void			ft_list_push_front(t_list **begin_list, void *data);
int			ref_ft_list_size(t_list *begin_list);
int			ft_list_size(t_list *begin_list);

int			*create_data_elem(int data);
t_list			*create_elem(int data);
t_list			*list_from_format(char *fmt);
t_list			*list_dup(t_list *list);
int	 		list_cmp(t_list *l1, t_list *l2);
void			list_print(t_list *list);
void			list_destroy(t_list *list);


void            	test_ft_strlen();
void			test_ft_list_size();
void            	test_ft_strcpy();
void			test_ft_strcmp();
void			test_ft_strdup();
void			test_ft_write();
void			test_ft_read();
void			test_ft_atoi_base();
void			test_ft_list_push_front();

#endif
