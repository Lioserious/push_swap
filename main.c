/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:44:16 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/31 15:50:51 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	struct Node	*listA;

	listA = NULL;
	if (argc < 2)
		return (0);
	if (process_input(argc, argv, &listA) != 0)
		return (1);
	printList(listA);
	write(1, "\n", 1);
	freeList(&listA);
	return (0);
}
