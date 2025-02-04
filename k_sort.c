/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:34:42 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/04 18:31:08 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_stacks(struct s_Node **head_a, struct s_Node **head_b)
{
    int len;
    int decision_line;
    int nums_in_b;
    int max_pos;
    int b_len;

    decision_line = (int)ft_sqrt(len);
    len = get_list_length(*head_a);
    if (*head_a == NULL || is_sorted(*head_a))
        return;
    while (*head_a != NULL)
    {
        nums_in_b = get_list_length(*head_b);
        if ((*head_a)->data <= nums_in_b)
        {
            pb_push_b(head_a, head_b);
            rb_rotate_b(head_b);
        }
        else if ((*head_a)->data <= (decision_line + nums_in_b))
            pb_push_b(head_a, head_b);
        else
            ra_rotate_a(head_a);
    }
    while (*head_b != NULL)
    {
		max_pos = find_max_position(*head_b);
		b_len = get_list_length(*head_b);
		
        if (max_pos <= b_len / 2)
            while (max_pos-- > 0)
                rb_rotate_b(head_b);

        else
            while (max_pos++ < b_len)
                rrb_reverse_b(head_b);
        pa_push_a(head_a, head_b);
    }
}
