/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:19:13 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/03 15:09:12 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	exists_in_list(struct s_Node *head, long long int value)
{
	struct s_Node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->data == value)
			return (1);
		current = current->next;
	}
	return (0);
}

/** Hilfsfunktion zum Zählen der Wörter in einem String */
int	count_numbers(const char *str)
{
	int	count;
	int	in_number;
	int	i;

	i = 0;
	count = 0;
	in_number = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			in_number = 0;
		else if (in_number == 0)
		{
			in_number = 1;
			count++;
		}
		i++;
	}
	return (count);
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
