/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:44:16 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/04 19:30:23 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
