/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:34:42 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/02 17:10:32 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(struct s_Node *head)
{
	struct s_Node *current;
	current = head;
	
	while(current != NULL && current->next != NULL)
	{
		if(current->data > current->next->data)
			return (0);
		current = current ->next;
	}
	return (1);
}