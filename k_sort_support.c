/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:58:52 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/03 15:00:41 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_max(struct s_Node *head, int *min, int *max)
{
	struct s_Node	*current;

	current = head;
	*min = head->data;
	*max = head->data;
	while (current != NULL)
	{
		if (current->data < *min)
			*min = current->data;
		if (current->data > *max)
			*max = current->data;
		current = current->next;
	}
}

int	calculate_bucket_size(int min, int max, int list_size)
{
	int	range;
	int	bucket_size;

	range = max - min;
	bucket_size = (range / list_size) + 1;
	return (bucket_size);
}

int	find_next_in_bucket(struct s_Node *head, int bucket_min, int bucket_max)
{
	struct s_Node	*current;
	int				position;

	current = head;
	position = 0;
	while (current != NULL)
	{
		if (current->data >= bucket_min && current->data <= bucket_max)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}

void	move_to_position(struct s_Node **head, int position)
{
	int	list_length;

	list_length = get_list_length(*head);
	if (position <= list_length / 2)
	{
		while (position > 0)
		{
			ra_rotate_a(head);
			position--;
		}
	}
	else
	{
		while (position < list_length)
		{
			rra_reverse_a(head);
			position++;
		}
	}
}
