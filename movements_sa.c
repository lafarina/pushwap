/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_sa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:54:18 by laufarin          #+#    #+#             */
/*   Updated: 2024/02/29 16:10:12 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_stack *a)
{
	t_disco	*tmp;

	if (a == NULL || a->first == NULL || a->first->next == NULL)
		return (1);
	tmp = a->first->next;
	a->first->next = tmp->next;
	tmp->next = a->first;
	a->first = tmp;
	write (1, "sa\n", 3);
	return (0);
}

int	push_b(t_stack *from, t_stack *to)
{
	t_disco	*tmp;

	if (from == NULL || from->first == NULL)
		return (1);
	tmp = from->first->next;
	from->first->next = to->first;
	to->first = from->first;
	from->first = tmp;
	from->len--;
	to->len++;
	write (1, "pb\n", 3);
	return (0);
}

int	rotate_a(t_stack *a)
{
	t_disco	*tmp;
	t_disco	*n_first;

	if (a == NULL || a->first == NULL)
		return (1);
	tmp = a->first;
	n_first = a->first->next;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = a->first;
	a->first->next = NULL;
	a->first = n_first;
	write (1, "ra\n", 3);
	return (0);
}

int	rev_rotate_a(t_stack *a)
{
	t_disco	*temp;
	t_disco	*last;

	if (a == NULL || a->first == NULL)
		return (1);
	temp = a->first;
	last = a->first;
	while (temp->next != NULL)
	{
		last = temp;
		temp = temp->next;
	}
	last->next = NULL;
	temp->next = a->first;
	a->first = temp;
	write (1, "rra\n", 4);
	return (0);
}
