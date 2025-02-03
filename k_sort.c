/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:34:42 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/03 14:44:34 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. Hilfsfunktion: Findet Minimum und Maximum
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

// 2. Hilfsfunktion: Berechnet die optimale Bucket-Größe
int	calculate_bucket_size(int min, int max, int list_size)
{
	int	range;
	int	bucket_size;

	// Berechnet die durchschnittliche Größe pro Bucket
	range = max - min;
	bucket_size = (range / list_size) + 1;
	return (bucket_size);
}

// 3. Hilfsfunktion: Findet die Position der nächsten Zahl im aktuellen Bucket
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
	return (-1); // Keine Zahl im aktuellen Bucket gefunden
}

// 4. Hilfsfunktion: Optimiert die Bewegung zur Zielposition
void	move_to_position(struct s_Node **head, int position)
{
	int	list_length;

	list_length = get_list_length(*head);
	// Entscheide ob ra oder rra effizienter ist
	if (position <= list_length / 2)
	{
		// Benutze ra für erste Hälfte
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
	while (*head_b != NULL)
		pa_push_a(head_a, head_b);
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
