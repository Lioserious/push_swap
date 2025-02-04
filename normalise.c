/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:46:00 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/04 18:58:53 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_Node	*copy_list(struct s_Node *head)
{
	struct s_Node	*new_head;
	struct s_Node	*current;
	struct s_Node	*new_current;
	struct s_Node	*new_node;

	if (head == NULL)
		return (NULL);
	new_head = create_node(head->data);
	if (new_head == NULL)
		handle_error(&head);
	current = head->next;
	new_current = new_head;
	while (current != NULL)
	{
		new_node = create_node(current->data);
		if (new_node == NULL)
		{
			free_list(&new_head);
			handle_error(&head);
		}
		new_current->next = new_node;
		current = current->next;
		new_current = new_current->next;
	}
	return (new_head);
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

void	normalise(struct s_Node *head)
{
	struct s_Node	*copy;
	struct s_Node	*current;
	struct s_Node	*sorted_search;
	int				index;

	if (head == NULL)
		return ;
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
