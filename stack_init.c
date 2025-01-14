/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:44:16 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/14 16:14:23 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int i;
	int nbr;
	int vrz;

	i = 0;
	nbr = 0;
	vrz = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			vrz = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * vrz);
}
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

int	main(int argc, char **argv)
{
	int				i;
	int				list_length;
	long long int	value;

	struct Node *listA = NULL; // Erste Liste
	struct Node *listB = NULL; // Zweite Liste
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		insertAtEnd(&listA, value);
		i++;
	}
	list_length = getListLength(listA);
	i = 0;
	while (i < list_length)
	{
		insertAtEnd(&listB, 0);
		i++;
	}
	printList(listA);
	write(1, "/n", 1);
	printList(listB);
	return (0);
}
