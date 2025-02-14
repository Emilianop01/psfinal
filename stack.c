/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:35:05 by epiacent          #+#    #+#             */
/*   Updated: 2024/07/30 14:48:35 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	create_stack(t_duo *stack, char **argv, int argc)
{
	t_list	*a1;
	int		i;
	int		l;

	l = lenarr(argv);
	i = 2;
	a1 = lstnew(ftatoi(argv[1]));
	stack->a.head = a1;
	stack->b.head = NULL;
	while (i < l)
	{
		appendnode(argv, stack, i, argc);
		i++;
	}
}

void	appendnode(char **argv, t_duo *duo, int i, int argc)
{
	long	content;
	t_list	*newn;
	t_list	*head;

	content = ftatoi(argv[i]);
	newn = lstnew(content);
	if (!newn)
	{
		if (argc == 2)
			freematrix(argv);
		freequit(duo, 1);
	}
	head = duo->a.head;
	addnodeb(&head, newn);
}

t_list	*lstnew(int content)
{
	t_list	*newn;

	newn = (t_list *)malloc(sizeof(t_list));
	if (!newn)
		return (NULL);
	newn->content = content;
	newn->next = NULL;
	return (newn);
}

void	addnodeb(t_list **list, t_list *newn)
{
	t_list	*curr;

	if (!list)
		return ;
	if (*list)
	{
		curr = lastn(*list);
		curr->next = newn;
	}
	else
		*list = newn;
}

t_list	*lastn(t_list *list)
{
	t_list	*curr;

	if (!list)
		return (NULL);
	curr = list;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}
