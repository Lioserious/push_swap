/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:44:16 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/13 15:55:20 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
// Freigeben der Liste wenn malloc fehlschlaegt
void	freeList(struct Node **head)
{
	struct Node	*temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
// Fuegt Knoten am Ende ein bzw erstellt erstes Glied
void	insertAtEnd(struct Node **head, int value)
{
	struct Node	*newNode;
	struct Node	*temp;

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

// Funktion: Liste anzeigen
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
int getListLength(struct Node *head) {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int	main(int argc, char **argv)
{
	struct Node *listA = NULL; // Erste Liste
	struct Node *listB = NULL; // Zweite Liste

	// Liste A füllen
	insertAtEnd(&listA, 10);
	insertAtEnd(&listA, 20);
	insertAtEnd(&listA, 30);

	// Liste B füllen
	insertAtEnd(&listB, 100);
	insertAtEnd(&listB, 200);
	insertAtEnd(&listB, 300);

	// Beide Listen anzeigen
	printf("List A:\n");
	printList(listA);

	printf("List B:\n");
	printList(listB);

	return (0);
}

