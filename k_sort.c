/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:34:42 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/04 19:16:50 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(struct s_Node **head_a, struct s_Node **head_b,
		int decision_line)
{
	int	nums_in_b;

	nums_in_b = get_list_length(*head_b);
	if ((*head_a)->data <= nums_in_b)
	{
		pb_push_b(head_a, head_b);
		rb_rotate_b(head_b);
	}
	else if ((*head_a)->data <= (decision_line + nums_in_b))
		pb_push_b(head_a, head_b);
	else
		ra_rotate_a(head_a);
}

static void	push_max_to_a(struct s_Node **head_a, struct s_Node **head_b)
{
	int	max_pos;
	int	b_len;

	max_pos = find_max_position(*head_b);
	b_len = get_list_length(*head_b);
	if (max_pos <= b_len / 2)
		while (max_pos-- > 0)
			rb_rotate_b(head_b);
	else
		while (max_pos++ < b_len)
			rrb_reverse_b(head_b);
	pa_push_a(head_a, head_b);
}

void	sort_stacks(struct s_Node **head_a, struct s_Node **head_b)
{
	int	len;
	int	decision_line;

	if (*head_a == NULL || is_sorted(*head_a))
		return ;
	len = get_list_length(*head_a);
	decision_line = ft_sqrt(len);
	while (*head_a != NULL)
		push_to_b(head_a, head_b, decision_line);
	while (*head_b != NULL)
		push_max_to_a(head_a, head_b);
}

void	easy_k_sort(struct s_Node **head_a, struct s_Node **head_b)
{
	int	size;

	if (*head_a == NULL || is_sorted(*head_a))
		return ;
	size = get_list_length(*head_a);
	if (size == 2)
		sort_two(head_a);
	else if (size == 3)
		sort_three(head_a);
	else
		sort_stacks(head_a, head_b);
}
