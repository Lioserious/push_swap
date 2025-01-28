/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:08:46 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/28 14:23:48 by lihrig           ###   ########.fr       */
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
// temp->next = *head_a; verknuepft temp mit der bereits bestehenden list von a
void pa_push_a(struct Node **head_a, struct Node **head_b)
{
	if(*head_b == NULL)
		return;
	struct Node *temp = *head_b;
	*head_b = (*head_b)->next;
	temp->next = *head_a;
	*head_a = temp;
}
void pb_push_b(struct Node **head_a, struct Node **head_b)
{
	if(*head_a == NULL)
		return;
	struct Node *temp = *head_a;
	*head_a = (*head_a)->next;
	temp->next = *head_b;
	*head_b = temp;
}
void ra_rotate_a(struct Node **head_a)
{
	if(*head_a == NULL || (*head_a)->next == NULL)
		return;
	struct Node *temp = *head_a;
	*head_a = (*head_a)->next;
	temp->next = NULL;
	struct Node *curloop = *head_a;
	while(curloop->next != NULL)
		curloop = curloop->next;
	curloop->next = temp;	
}
void rb_rotate_b(struct Node **head_b)
{
	if(*head_b == NULL || (*head_b)->next == NULL)
		return;
	struct Node *temp = *head_b;
	*head_b = (*head_b)->next;
	temp->next = NULL;
	struct Node *curloop = *head_b;
	while(curloop->next != NULL)
		curloop = curloop->next;
	curloop->next = temp;	
}
void rr(struct Node **head_a, struct Node **head_b)
{
	ra_rotate_a(head_a);
	rb_rotate_b(head_b);
}
void rra_reverse_a(struct Node **head_a)
{
	if(*head_a == NULL || (*head_a)->next == NULL)
		return;
	struct Node *prev = NULL;
	struct Node *curloop = *head_a;
	while(curloop->next != NULL)
	{	
		prev = curloop;
		curloop = curloop->next;
	}
	prev->next = NULL;
	curloop->next = *head_a;
	*head_a = curloop;
}
void rrb_reverse_b(struct Node **head_b)
{
	if(*head_b == NULL || (*head_b)->next == NULL)
		return;
	struct Node *prev = NULL;
	struct Node *curloop = *head_b;
	while(curloop->next != NULL)
	{	
		prev = curloop;
		curloop = curloop->next;
	}
	prev->next = NULL;
	curloop->next = *head_b;
	*head_b = curloop;
}
void rrr(struct Node **head_a, struct Node **head_b)
{
	rra_reverse_a(head_a);
	rrb_reverse_b(head_b);
}