/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:16:29 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/30 18:47:05 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

struct			Node
{
	int			data;
	struct Node	*next;
};
int		ft_atoi(const char *str);
int exists_in_list(struct Node* head, long long int value);
static int count_numbers(const char *str);
static void	free_the_mellok(char ***split_array);

#endif