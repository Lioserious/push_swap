/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:44:16 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/30 18:46:23 by lihrig           ###   ########.fr       */
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
int	check_if_numeric(const char *str)
{
	int	i;
	int	digits_exist;

	digits_exist = 0;
	i = 0;
	if (!str || *str == '\0')
		return (0);
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		digits_exist = 1;
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}
long long int	convert_to_int(const char *str, struct Node **head)
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
	while (*str >= '0' && *str <= '9')
	{
		if (nbr > (INT_MAX / 10) || (nbr == (INT_MAX / 10) && (*str
					- '0') > (INT_MAX % 10)))
			handle_error(head);
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * vrz);
}
// atoi muss angepasst werden um den Input richtig zu catchen
long long int	adjusted_ft_atoi(const char *str, struct Node **head)
{
	if (!check_if_numeric(str))
		handle_error(head);
	return (convert_to_int(str, head));
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
static int	process_string_with_spaces(char *str, struct Node **listA)
{
	char			**numbers;
	int				j;
	long long int	value;

	numbers = ft_split(str, ' ');
	if (!numbers)
		handle_error(listA);
	j = 0;
	while (numbers[j] != NULL)
	{
		value = adjusted_ft_atoi(numbers[j], listA);
		if (value < INT_MIN || value > INT_MAX)
		{
			free_the_mellok(&numbers);
			handle_error(listA);
		}
		insertAtEnd(listA, value);
		j++;
	}
	free_the_mellok(&numbers);
	return (0);
}

// Verarbeitet ein einzelnes Argument
static int	process_single_arg(char *str, struct Node **listA)
{
	long long int	value;

	value = adjusted_ft_atoi(str, listA);
	if (value < INT_MIN || value > INT_MAX)
		handle_error(listA);
	insertAtEnd(listA, value);
	return (0);
}

// Hauptfunktion für die Eingabeverarbeitung
int	process_input(int argc, char **argv, struct Node **listA)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' ') != NULL)
		{
			if (process_string_with_spaces(argv[i], listA) != 0)
				return (1);
		}
		else
		{
			if (process_single_arg(argv[i], listA) != 0)
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	long long int	value;
	int				i;

	struct Node *listA = NULL; // Erste Liste
	i = 1;
	while (i < argc)
	{
		value = adjusted_ft_atoi(argv[i], &listA);
		insertAtEnd(&listA, value);
		i++;
	}
	printList(listA);
	write(1, "\n", 1);
	freeList(&listA);
	return (0);
}
