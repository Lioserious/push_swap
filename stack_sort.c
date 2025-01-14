/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:08:46 by lihrig            #+#    #+#             */
/*   Updated: 2025/01/14 17:17:12 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// muss checken wie ich im falle des Edge case fortfahre.
void sa_swap_a(struct Node **head)
{
	int temp;
	if(*head == NULL || (*head)->next == NULL)
		return;
	temp = (*head)->data;
	(*head)->data = (*head)->next->data;
    (*head)->next->data = temp;
}