/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:21:03 by lihrig            #+#    #+#             */
/*   Updated: 2025/02/04 19:30:45 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	return_word_nbr(char const *s, char c)
{
	size_t	i;
	size_t	word_nbr;
	int		in_word;

	i = 0;
	word_nbr = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !in_word)
		{
			word_nbr++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (word_nbr);
}

static char	*allocate_word(char const *s, size_t start, size_t end)
{
	char	*word;
	size_t	len;

	len = end - start;
	word = (char *)ft_calloc(len + 1, sizeof(char));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, s + start, len + 1);
	return (word);
}

static void	extract_words(char const *s, char c, char ***split_array)
{
	size_t	i;
	size_t	word_start;
	size_t	word_index;

	i = 0;
	word_start = 0;
	word_index = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word_start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			(*split_array)[word_index] = allocate_word(s, word_start, i + 1);
			if ((*split_array)[word_index] == NULL)
			{
				free_the_mellok(split_array);
				return ;
			}
			word_index++;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split_array;
	size_t	word_nbr;

	if (s == NULL)
		return (NULL);
	word_nbr = return_word_nbr(s, c);
	split_array = (char **)ft_calloc(word_nbr + 1, sizeof(char *));
	if (split_array == NULL)
		return (NULL);
	extract_words(s, c, &split_array);
	return (split_array);
}
