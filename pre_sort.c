/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:56:49 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/02 17:57:40 by lihrig           ###   ########.fr       */
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
	int first = (*head)->data;
	int second = (*head)->next->data;
	int third = (*head)->next->next->data;

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
