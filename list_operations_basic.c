/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_basic.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:36:44 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/31 15:38:00 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Erstellt Knoten
struct Node	*createNode(int value)
{
	struct Node	*newNode;

	newNode = (struct Node *)malloc(sizeof(struct Node));
	if (newNode == NULL)
		return (NULL);
	newNode->data = value;
	newNode->next = NULL;
	return (newNode);
}
// Fuegt Knoten am Ende ein bzw erstellt erstes Glied
// Es fehlt noch die korrigierte return message
void	insertAtEnd(struct Node **head, long long int value)
{
	struct Node	*newNode;
	struct Node	*temp;

	if (exists_in_list(*head, value))
		handle_error(head);
	newNode = createNode(value);
	if (newNode == NULL)
	{
		freeList(head);
		return ;
	}
	if (*head == NULL)
	{
		*head = newNode;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
}
int	getListLength(struct Node *head)
{
	int			count;
	struct Node	*temp;

	count = 0;
	temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
// Funktion: Liste anzeigen, PRINTF Ersetzen UND LOESCHEN
void	printList(struct Node *head)
{
	struct Node	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}