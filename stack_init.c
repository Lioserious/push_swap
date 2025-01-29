/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:44:16 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/29 14:46:56 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

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
	*head = NULL;
}
void	handle_error(struct Node **head)
{
	write(1, "Error\n", 6);
	freeList(head);
	exit(EXIT_FAILURE);
}
// atoi muss angepasst werden um den Input richtig zu catchen
int	adjusted_ft_atoi(const char *str, struct Node **head)
{
	long	nbr;
	int		vrz;

	nbr = 0;
	vrz = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			vrz = -1;
		str++;
	}
	while (!(*str >= '0' && *str <= '9'))
		handle_error(head);
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		if ((nbr * vrz) > INT_MAX || (nbr * vrz) < INT_MIN)
			handle_error(head);
		str++;
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
// Fuegt Knoten am Ende ein bzw erstellt erstes Glied
// Es fehlt noch die korrigierte return message
void	insertAtEnd(struct Node **head, int value)
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

// Funktion: Liste anzeigen, PRINTF Ersetzen
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
int	check_if_numeric(char *str)
{
	int	i = 0;

	if (!str || *str == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
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
		if(!check_if_numeric(argv[i]))
			handle_error(&listA);
		value = adjusted_ft_atoi(argv[i],&listA);
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
	freeList(&listA);
	freeList(&listB);
	return (0);
}
