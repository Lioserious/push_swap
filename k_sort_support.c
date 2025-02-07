/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort_support.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:58:52 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/07 16:40:31 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
{
	int		start;
	int		end;
	int		mid;
	long	square;

	if (n <= 0)
		return (0);
	if (n == 1)
		return (1);
	start = 1;
	end = n / 2;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		square = (long)mid * mid;
		if (square == n)
			return (mid);
		if (square < n)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (end);
}

int	find_max_position(struct s_Node *head)
{
	int				max;
	int				pos;
	int				min_pos;
	struct s_Node	*current;

	max = INT_MIN;
	pos = 0;
	min_pos = 0;
	current = head;
	while (current != NULL)
	{
		if (current->data > max)
		{
			max = current->data;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}
int	find_min_position(struct s_Node *head)
{
	int				min;
	int				pos;
	int				min_pos;
	struct s_Node	*current;

	min = INT_MAX;
	pos = 0;
	min_pos = 0;
	current = head;
	while (current != NULL)
	{
		if (current->data < min)
		{
			min = current->data;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}
