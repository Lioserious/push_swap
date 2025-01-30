/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:19:13 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/30 18:18:09 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int exists_in_list(struct Node* head, long long int value)
{
    struct Node* current = head;
    
    while (current != NULL)
    {
        if (current->data == value) // Hier könnte das Problem liegen
            return (1);
        current = current->next;
    }
    return (0);
}

/** Hilfsfunktion zum Zählen der Wörter in einem String */
static int count_numbers(const char *str)
{
	int count;
	int in_number;
	int i;
	
	i = 0;
	count = 0;
	in_number = 0;
	
	while(str[i] != '\0')
	{
		if(str[i] == ' ' || str[i] == '\t')
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
