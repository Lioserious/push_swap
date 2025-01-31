/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:16:29 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/31 15:54:10 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

struct			Node
{
	int			data;
	struct Node	*next;
};

// error handling
void			freeList(struct Node **head);
void			handle_error(struct Node **head);
void			free_the_mellok(char ***split_array);
// input_processing
int				process_string_with_spaces(char *str, struct Node **listA);
int				process_single_arg(char *str, struct Node **listA);
int				process_input(int argc, char **argv, struct Node **listA);
// input_validation
int				check_if_numeric(const char *str);
long long int	convert_to_int(const char *str, struct Node **head);
long long int	adjusted_ft_atoi(const char *str, struct Node **head);
// list_operations_basics
struct Node		*createNode(int value);
void			insertAtEnd(struct Node **head, long long int value);
int				getListLength(struct Node *head);
// sollte ich entfernen
void			printList(struct Node *head);
//
int				exists_in_list(struct Node *head, long long int value);
// int				count_numbers(const char *str);
// sorting functions
void			sa_swap_a(struct Node **head);
void			ss_swap_swap(struct Node **head_a, struct Node **head_b);
void			pa_push_a(struct Node **head_a, struct Node **head_b);
void			pb_push_b(struct Node **head_a, struct Node **head_b);
void			ra_rotate_a(struct Node **head_a);
void			rb_rotate_b(struct Node **head_b);
void			rr(struct Node **head_a, struct Node **head_b);
void			rra_reverse_a(struct Node **head_a);
void			rrb_reverse_b(struct Node **head_b);
void			rrr(struct Node **head_a, struct Node **head_b);

#endif