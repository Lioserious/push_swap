/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:33:33 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/05 14:30:13 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_numeric(const char *str)
{
	int	i;

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
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

long long int	convert_to_int(const char *str, struct s_Node **head)
{
	long long int	nbr;
	int				vrz;

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
		nbr = nbr * 10 + (*str - '0');
		if ((vrz == 1 && nbr > INT_MAX) || (vrz == -1
				&& nbr > -(long long int)INT_MIN))
			handle_error(head);
		str++;
	}
	return (nbr * vrz);
}

// atoi musste angepasst werden um den Input richtig zu catchen
long long int	adjusted_ft_atoi(const char *str, struct s_Node **head)
{
	if (!check_if_numeric(str))
		handle_error(head);
	return (convert_to_int(str, head));
}
