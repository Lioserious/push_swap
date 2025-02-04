/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:46:00 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/04 17:02:44 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_Node	*copy_list(struct s_Node *head)
{
	struct s_Node	*newHead;
	struct s_Node	*current;
	struct s_Node	*newCurrent;
	struct s_Node	*newNode;

	if (head == NULL)
		return (NULL);
	newHead = create_node(head->data);
	if (newHead == NULL)
		handle_error(&head);
	current = head->next;
	newCurrent = newHead;
	while (current != NULL)
	{
		newNode = create_node(current->data);
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

void	bubble_sort(struct s_Node *head)
{
	struct s_Node	*temp;
	int				i;
	int				len;
	long			s_temp;

	if (head == NULL)
		return ;
	len = get_list_length(head);
	i = 0;
	while (i < len - 1)
	{
		temp = head;
		while (temp->next != NULL)
		{
			if (temp->data > temp->next->data)
			{
				s_temp = temp->data;
				temp->data = temp->next->data;
				temp->next->data = s_temp;
			}
			temp = temp->next;
		}
		i++;
	}
}

void normalise(struct s_Node *head)
{
    struct s_Node *copy;
    struct s_Node *current;
    struct s_Node *sorted_search;
    int index;

    if (head == NULL)
        return;
    copy = copy_list(head);
    bubble_sort(copy);
    
    current = head;
    while (current)
    {
        sorted_search = copy;
        index = 0;
        while (sorted_search->data != current->data)
        {
            index++;
            sorted_search = sorted_search->next;
        }
        current->data = index;
        current = current->next;
    }
    free_list(&copy);
}
