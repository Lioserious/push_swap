/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:56:49 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/07 16:41:57 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(struct s_Node *head)
{
	struct s_Node	*current;

	current = head;
	while (current != NULL && current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_two(struct s_Node **head)
{
	if ((*head)->data > (*head)->next->data)
		sa_swap_a(head);
}

void	sort_three(struct s_Node **head)
{
	int	first;
	int	second;
	int	third;

	first = (*head)->data;
	second = (*head)->next->data;
	third = (*head)->next->next->data;
	if (first > second && second < third && first < third)
		sa_swap_a(head);
	else if (first > second && second > third)
	{
		sa_swap_a(head);
		rra_reverse_a(head);
	}
	else if (first > second && second < third && first > third)
		ra_rotate_a(head);
	else if (first < second && second > third && first < third)
	{
		sa_swap_a(head);
		ra_rotate_a(head);
	}
	else if (first < second && second > third && first > third)
		rra_reverse_a(head);
}

void	sort_less_than_ten(struct s_Node **a, struct s_Node **b)
{
	int	len;
	int	min_pos;

	len = get_list_length(*a);
	while (len > 3 && !is_sorted(*a))
	{
		min_pos = find_min_position(*a);
		if (min_pos <= len / 2)
			while (min_pos--)
				ra_rotate_a(a);
		else
			while (min_pos++ < len)
				rra_reverse_a(a);
		pb_push_b(a, b);
		len--;
	}
	sort_three(a);
	while (*b)
		pa_push_a(a, b);
}
