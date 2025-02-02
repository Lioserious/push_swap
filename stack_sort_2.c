/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:08:46 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/02 16:24:38 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_rotate_b(struct s_Node **head_b)
{
	struct s_Node	*temp;
	struct s_Node	*curloop;

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

void	rr(struct s_Node **head_a, struct s_Node **head_b)
{
	ra_rotate_a(head_a);
	rb_rotate_b(head_b);
}

void	rra_reverse_a(struct s_Node **head_a)
{
	struct s_Node	*prev;
	struct s_Node	*curloop;

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

void	rrb_reverse_b(struct s_Node **head_b)
{
	struct s_Node	*prev;
	struct s_Node	*curloop;

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

void	rrr(struct s_Node **head_a, struct s_Node **head_b)
{
	rra_reverse_a(head_a);
	rrb_reverse_b(head_b);
}
