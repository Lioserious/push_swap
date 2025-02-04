/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:44:16 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/04 18:45:10 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

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
int	main(int argc, char **argv)
{
	struct s_Node	*list_a;
	struct s_Node	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc < 2)
		return (0);
	if (process_input(argc, argv, &list_a) != 0)
		return (1);
	normalise(list_a);
	easy_k_sort(&list_a, &list_b);
	free_list(&list_a);
	free_list(&list_b);
	return (0);
}
