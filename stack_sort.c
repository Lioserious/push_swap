/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:08:46 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/03 17:33:41 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// muss checken wie ich im falle des Edge case fortfahre.
void	sa_swap_a(struct s_Node **head)
{
	int	temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head)->data;
	(*head)->data = (*head)->next->data;
	(*head)->next->data = temp;
	write(1,"sa\n",3);
}

// swap a and b at the same time: DER EDGE CASE Koennte probleme machen
void	ss_swap_swap(struct s_Node **head_a, struct s_Node **head_b)
{
	sa_swap_a(head_a);
	sa_swap_a(head_b);
	write(1,"ss\n",3);
}

// temp->next = *head_a; verknuepft temp mit der bereits bestehenden list von a
void	pa_push_a(struct s_Node **head_a, struct s_Node **head_b)
{
	struct s_Node	*temp;

	if (*head_b == NULL)
		return ;
	temp = *head_b;
	*head_b = (*head_b)->next;
	temp->next = *head_a;
	*head_a = temp;
	write(1,"pa\n",3);
}

void	pb_push_b(struct s_Node **head_a, struct s_Node **head_b)
{
	struct s_Node	*temp;

	if (*head_a == NULL)
		return ;
	temp = *head_a;
	*head_a = (*head_a)->next;
	temp->next = *head_b;
	*head_b = temp;
	write(1, "pb\n", 3);
}

void	ra_rotate_a(struct s_Node **head_a)
{
	struct s_Node	*temp;
	struct s_Node	*curloop;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	temp = *head_a;
	*head_a = (*head_a)->next;
	temp->next = NULL;
	curloop = *head_a;
	while (curloop->next != NULL)
		curloop = curloop->next;
	curloop->next = temp;
	write(1,"ra\n",3);
}
