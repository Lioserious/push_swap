/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:46:00 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/04 16:14:36 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_Node* copyList(struct s_Node* head)
{
    if (head == NULL)
        return NULL;
    
    struct s_Node* newHead = create_node(head->data);
    if (newHead == NULL)
        handle_error(&head);
    
    struct s_Node* current = head->next;
    struct s_Node* newCurrent = newHead;
    
    while (current != NULL)
    {
        struct s_Node* newNode = create_node(current->data);
        if (newNode == NULL)
        {
            free_list(&newHead);
            handle_error(&head);
        }
        newCurrent->next = newNode;
        current = current->next;
        newCurrent = newCurrent->next;
    }
    return (newHead);
}
