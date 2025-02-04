/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_basic.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:36:44 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/04 19:30:18 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Erstellt Knoten
struct s_Node	*create_node(int value)
{
	struct s_Node	*new_node;

	new_node = (struct s_Node *)malloc(sizeof(struct s_Node));
	if (new_node == NULL)
		return (NULL);
	new_node->data = value;
	new_node->next = NULL;
	return (new_node);
}

// Fuegt Knoten am Ende ein bzw erstellt erstes Glied
// Es fehlt noch die korrigierte return message
void	insert_at_end(struct s_Node **head, long long int value)
{
	struct s_Node	*new_node;
	struct s_Node	*temp;

	if (exists_in_list(*head, value))
		handle_error(head);
	new_node = create_node(value);
	if (new_node == NULL)
	{
		free_list(head);
		return ;
	}
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}

int	get_list_length(struct s_Node *head)
{
	int				count;
	struct s_Node	*temp;

	count = 0;
	temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

// // Funktion: Liste anzeigen, PRINTF Ersetzen UND LOESCHEN
// void	print_list(struct s_Node *head)
// {
// 	struct s_Node	*temp;

// 	temp = head;
// 	while (temp != NULL)
// 	{
// 		printf("%d -> ", temp->data);
// 		temp = temp->next;
// 	}
// 	printf("NULL\n");
// }
