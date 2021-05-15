/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:06:46 by sgah              #+#    #+#             */
/*   Updated: 2020/11/28 23:16:21 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBASM_H
# define LIBASM_H

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

ssize_t			ft_write(int, char *, size_t);
ssize_t			ft_read(int, char *, size_t);
ssize_t			ft_strlen(char *);
char			*ft_strcpy(char *, char *);
int			ft_strcmp(char *, char *);
char			*ft_strdup(char *);

typedef struct		s_list
{
	void		*data;
	struct	s_list	*next;
}			t_list;

int			ft_atoi_base(const char *str, const char *base);
void			ft_list_push_front(t_list **begin_list, void *data);
int			ft_list_size(t_list *begin_list);

#endif
