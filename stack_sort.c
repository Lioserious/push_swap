/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:08:46 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/14 17:56:52 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// muss checken wie ich im falle des Edge case fortfahre.
void sa_swap_a(struct Node **head)
{
	int temp;
	if(*head == NULL || (*head)->next == NULL)
		return;
	temp = (*head)->data;
	(*head)->data = (*head)->next->data;
    (*head)->next->data = temp;
}
//swap a and b at the same time: DER EDGE CASE Koennte probleme machen
void ss_swap_swap(struct Node **head_a, struct Node **head_b)
{
	sa_swap_a(head_a);
	sa_swap_a(head_b);
}

void pa(struct Node **head_a, struct Node **head_b)
{
	if(*head_b == NULL)
		return;
	struct Node *temp = *head_b;
	*head_b = (*head_b)->next;
	temp->next = *head_a;
	*head_a = temp;
}