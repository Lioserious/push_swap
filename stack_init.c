/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:44:16 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/09 20:03:29 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct			Node
{
	int			data;
	struct Node	*next;
};
// Erstellt Knoten
struct Node	*createNode(int value)
{
	struct Node	*newNode;

	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	return (newNode);
}
// Fuegt Knoten am Ende ein bzw erstellt erstes Glied
void	insertAtEnd(struct Node **head, int value)
{
	struct Node *newNode = createNode(value);
	if (*head == NULL)
	{
		*head = newNode;
		return ;
	}
	struct Node *temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
}