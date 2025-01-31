/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:08:46 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/31 17:07:10 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_rotate_b(struct Node **head_b)
{
	struct Node	*temp;
	struct Node	*curloop;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	temp = *head_b;
	*head_b = (*head_b)->next;
	temp->next = NULL;
	curloop = *head_b;
	while (curloop->next != NULL)
		curloop = curloop->next;
	curloop->next = temp;
}
void	rr(struct Node **head_a, struct Node **head_b)
{
	ra_rotate_a(head_a);
	rb_rotate_b(head_b);
}
void	rra_reverse_a(struct Node **head_a)
{
	struct Node	*prev;
	struct Node	*curloop;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	prev = NULL;
	curloop = *head_a;
	while (curloop->next != NULL)
	{
		prev = curloop;
		curloop = curloop->next;
	}
	prev->next = NULL;
	curloop->next = *head_a;
	*head_a = curloop;
}
void	rrb_reverse_b(struct Node **head_b)
{
	struct Node	*prev;
	struct Node	*curloop;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	prev = NULL;
	curloop = *head_b;
	while (curloop->next != NULL)
	{
		prev = curloop;
		curloop = curloop->next;
	}
	prev->next = NULL;
	curloop->next = *head_b;
	*head_b = curloop;
}
void	rrr(struct Node **head_a, struct Node **head_b)
{
	rra_reverse_a(head_a);
	rrb_reverse_b(head_b);
}
