/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:48:09 by sgah              #+#    #+#             */
/*   Updated: 2020/10/16 15:33:58 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define ATOI_BASE(s, b)     \
	i = ft_atoi_base(s, b); \
	printf("		\x1b[33mft_ atoi_base\x1b[0m  '%s', [%s] = %d\n", s, b, i);

typedef struct s_list
{
	void *data;
	struct s_list *next;
} t_list;

void printf_list(t_list *list)
{
	while (list)
	{
		printf("	data:  %s\n", list->data);
		list = list->next;
	}
}

void ft_lstclear(t_list **list)
{
	t_list *tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

int ft_atoi_base(char const *str, char const *base);

void ft_list_push_front(t_list **begin_list, void *data);

int		ft_list_size(t_list *begin_list);

//void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
//			void (*free_fct)(void*));

//void	ft_list_sort(t_list **begin_list,int (*cmp)());

void test_ft_atoi_base(void)
{
	int i = 0;
	printf("\x1b[32mft_atoi_base:\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36mtest base decimal\x1b[0m\n");
	ATOI_BASE("42", "0123456789")
	ATOI_BASE("0", "0123456789")
	ATOI_BASE("1", "0123456789")
	ATOI_BASE("1215415478", "0123456789")
	ATOI_BASE("-0", "0123456789")
	ATOI_BASE("-1", "0123456789")
	ATOI_BASE("-42", "0123456789")
	ATOI_BASE("--42", "0123456789")
	ATOI_BASE("-+-42", "0123456789")
	ATOI_BASE("-+-+-+42", "0123456789")
	ATOI_BASE("-+-+-+-42", "0123456789")
	ATOI_BASE("-1215415478", "0123456789")
	ATOI_BASE("2147483647", "0123456789")
	ATOI_BASE("2147483648", "0123456789")
	ATOI_BASE("-2147483648", "0123456789")
	ATOI_BASE("-2147483649", "0123456789")
	printf("	\x1b[34m[2]\x1b[0m \x1b[36mtest base hexadecimal\x1b[0m\n");
	ATOI_BASE("2a", "0123456789abcdef")
	ATOI_BASE("ff", "0123456789abcdef")
	printf("	\x1b[34m[3]\x1b[0m \x1b[36mtest random base\x1b[0m\n");
	ATOI_BASE("poney", "poney")
	ATOI_BASE("dommage", "invalid")
	ATOI_BASE("dommage", "aussi invalide")
	ATOI_BASE("dommage", "+toujours")
	ATOI_BASE("dommage", "-stop")
	ATOI_BASE("dommage", "  \t\nca suffit")
	printf("	\x1b[34m[4]\x1b[0m \x1b[36mtest parsing\x1b[0m\n");
	ATOI_BASE("    +42", "0123456789")
	ATOI_BASE("    -42", "0123456789")
	ATOI_BASE("    42", "0123456789")
	ATOI_BASE("  \t\n\r\v\f  42", "0123456789")
	ATOI_BASE("  \t\n\r\v\f  -42", "0123456789")
	ATOI_BASE("42FINIS !", "0123456789")
	ATOI_BASE("-42FINIS !", "0123456789")
	ATOI_BASE("C'est dommage42", "0123456789")
}

void test_ft_list()
{
	t_list	list;
	t_list	list_next;
	t_list	list_last;
	list.data = strdup("foo");
	list.next = &list_next;
	list_next.data = strdup("bar");
	list_next.next = &list_last;
	list_last.data = strdup("baz");
	list_last.next = NULL;
	printf("\x1b[32mft_list_size:\x1b[0m\n");
	printf("	\x1b[34m\x1b[0m \x1b[36mlist content\x1b[0m\n");
	printf_list(&list);
	printf("		return:%d (from first %d)\n", ft_list_size(&list), 3);
	printf("		return:%d (from second %d)\n", ft_list_size(&list_next), 2);
	printf("		return:%d (NULL %d)\n", ft_list_size(NULL), 0);
	printf("		return:%d (from last %d)\n\n", ft_list_size(&list_last), 1);

	printf("\x1b[32mft_list_push_front:\x1b[0m\n");
	t_list	*push_test = &list;
	ft_list_push_front(&push_test, strdup("toto"));
	printf("		added: `%s` (next: %p)\n", push_test->data, push_test->next);
	printf_list(push_test);
	printf("new list size: %d (%d)\n", ft_list_size(push_test), 4);
	free(list.data);
	free(push_test->data);
	free(push_test);
	push_test = NULL;
	ft_list_push_front(&push_test, strdup("barbar"));
	printf("		added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	printf_list(push_test);
	ft_list_push_front(&push_test, NULL);
	printf("		added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	printf_list(push_test);
	free(push_test->next);
	push_test->next = NULL;
	ft_list_push_front(&push_test, strdup("toto_r"));
	printf("		added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	printf_list(push_test);
	ft_lstclear(&push_test);
	free(list_next.data);
	free(list_last.data);
}


int main(void)
{
	test_ft_atoi_base();
	printf("Appuyer sur [entree] pour continuer...\n");
	getchar();
	test_ft_list();
	return (0);
}
