/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:34:42 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/03 16:50:12 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_bucket_to_b(struct s_Node **head_a, struct s_Node **head_b,
		int current_bucket_min, int bucket_size, int max)
{
	int	position;

	while (*head_a != NULL)
	{
		position = find_next_in_bucket(*head_a, current_bucket_min,
				current_bucket_min + bucket_size);
		if (position != -1)
		{
			move_to_position(head_a, position);
			pb_push_b(head_a, head_b);
			if (*head_b && (*head_b)->next
				&& (*head_b)->data < (*head_b)->next->data)
				sa_swap_a(head_b);
		}
		else
		{
			current_bucket_min += bucket_size;
			if (current_bucket_min > max)
				return ;
		}
	}
}

void	move_all_b_to_a(struct s_Node **head_a, struct s_Node **head_b)
{
	int	max_pos;

	while (*head_b != NULL)
	{
		max_pos = find_max_position(*head_b);
		if (max_pos <= get_list_length(*head_b) / 2)
		{
			while (max_pos-- > 0)
				rb_rotate_b(head_b);
		}
		else
		{
			while (max_pos++ < get_list_length(*head_b))
				rrb_reverse_b(head_b);
		}
		pa_push_a(head_a, head_b);
	}
}

void	k_sort(struct s_Node **head_a, struct s_Node **head_b)
{
	int	min;
	int	max;
	int	list_size;
	int	bucket_size;
	int	current_bucket_min;

	if (*head_a == NULL || is_sorted(*head_a))
		return ;
	list_size = get_list_length(*head_a);
	find_min_max(*head_a, &min, &max);
	bucket_size = calculate_bucket_size(min, max, list_size);
	current_bucket_min = min;
	move_bucket_to_b(head_a, head_b, current_bucket_min, bucket_size, max);
	move_all_b_to_a(head_a, head_b);
}
