/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:18:59 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/31 15:54:22 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	process_string_with_spaces(char *str, struct Node **listA)
{
	char			**numbers;
	int				j;
	long long int	value;

	numbers = ft_split(str, ' ');
	if (!numbers)
		handle_error(listA);
	j = 0;
	while (numbers[j] != NULL)
	{
		value = adjusted_ft_atoi(numbers[j], listA);
		if (value < INT_MIN || value > INT_MAX)
		{
			free_the_mellok(&numbers);
			handle_error(listA);
		}
		insertAtEnd(listA, value);
		j++;
	}
	free_the_mellok(&numbers);
	return (0);
}

// Verarbeitet ein einzelnes Argument
int	process_single_arg(char *str, struct Node **listA)
{
	long long int	value;

	value = adjusted_ft_atoi(str, listA);
	if (value < INT_MIN || value > INT_MAX)
		handle_error(listA);
	insertAtEnd(listA, value);
	return (0);
}

// Hauptfunktion für die Eingabeverarbeitung
int	process_input(int argc, char **argv, struct Node **listA)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' ') != NULL)
		{
			if (process_string_with_spaces(argv[i], listA) != 0)
				return (1);
		}
		else
		{
			if (process_single_arg(argv[i], listA) != 0)
				return (1);
		}
		i++;
	}
	return (0);
}
