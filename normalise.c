/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:46:00 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/04 16:08:28 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct Node* copyList(struct Node* head)
{
    if (head == NULL)
        return NULL;
    struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
    if (newHead == NULL)
        return NULL;
    newHead->data = head->data;
    struct Node* current = head->next;
    struct Node* newCurrent = newHead;
    while (current != NULL)
	{
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL)
			return NULL;
        newNode->data = current->data;
        newNode->next = NULL;
        newCurrent->next = newNode;
        current = current->next;
        newCurrent = newCurrent->next;
    }
    return (newHead);
}
