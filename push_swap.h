/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:16:29 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/03 16:51:55 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct				s_Node
{
	int				data;
	struct s_Node	*next;
};

// error handling
void				free_list(struct s_Node **head);
void				handle_error(struct s_Node **head);
void				free_the_mellok(char ***split_array);
// input_processing
int					process_string_with_spaces(char *str,
						struct s_Node **listA);
int					process_single_arg(char *str, struct s_Node **listA);
int					process_input(int argc, char **argv, struct s_Node **listA);
// input_validation
int					check_if_numeric(const char *str);
long long int		convert_to_int(const char *str, struct s_Node **head);
long long int		adjusted_ft_atoi(const char *str, struct s_Node **head);
// list_operations_basics
struct s_Node		*createNode(int value);
void				insert_at_end(struct s_Node **head, long long int value);
int					get_list_length(struct s_Node *head);
// sollte ich entfernen
void				print_list(struct s_Node *head);
//
int					exists_in_list(struct s_Node *head, long long int value);
// int				count_numbers(const char *str);
// sorting functions
void				sa_swap_a(struct s_Node **head);
void				ss_swap_swap(struct s_Node **head_a,
						struct s_Node **head_b);
void				pa_push_a(struct s_Node **head_a, struct s_Node **head_b);
void				pb_push_b(struct s_Node **head_a, struct s_Node **head_b);
void				ra_rotate_a(struct s_Node **head_a);
void				rb_rotate_b(struct s_Node **head_b);
void				rr(struct s_Node **head_a, struct s_Node **head_b);
void				rra_reverse_a(struct s_Node **head_a);
void				rrb_reverse_b(struct s_Node **head_b);
void				rrr(struct s_Node **head_a, struct s_Node **head_b);
// pre sort
int					is_sorted(struct s_Node *head);
void				sort_two(struct s_Node **head);
void				sort_three(struct s_Node **head);
// k_sort_support
void				find_min_max(struct s_Node *head, int *min, int *max);
int					calculate_bucket_size(int min, int max, int list_size);
int					find_next_in_bucket(struct s_Node *head, int bucket_min,
						int bucket_max);
void				move_to_position(struct s_Node **head, int position);
// ksort
void				move_bucket_to_b(struct s_Node **head_a,
						struct s_Node **head_b, int current_bucket_min,
						int bucket_size, int max);
void				move_all_b_to_a(struct s_Node **head_a,
						struct s_Node **head_b);
void				k_sort(struct s_Node **head_a, struct s_Node **head_b);
// support function
int					find_max_position(struct s_Node *head);
#endif