/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:44:16 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/02 16:18:43 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	struct s_Node	*list_a;

	list_a = NULL;
	if (argc < 2)
		return (0);
	if (process_input(argc, argv, &list_a) != 0)
		return (1);
	print_list(list_a);
	write(1, "\n", 1);
	free_list(&list_a);
	return (0);
}
