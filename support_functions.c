/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:19:13 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/04 19:30:52 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
