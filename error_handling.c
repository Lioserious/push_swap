/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:39:42 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/04 18:45:26 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Freigeben der Liste wenn malloc fehlschlaegt
void	free_list(struct s_Node **head)
{
	struct s_Node	*temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;
}

void	handle_error(struct s_Node **head)
{
	write(1, "Error\n", 6);
	free_list(head);
	exit(EXIT_FAILURE);
}
