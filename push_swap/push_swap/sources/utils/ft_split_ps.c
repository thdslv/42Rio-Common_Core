/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:08:33 by thda-sil          #+#    #+#             */
/*   Updated: 2024/05/02 11:51:19 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*word;
	int			len;
	int			i;

	while (str[cursor] == separator)
		++cursor;
	len = 0;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	word = malloc((size_t)len * (sizeof(char) + 1));
	if (NULL == word)
		return (NULL);
	i = 0;
	while ((str[cursor] != separator) && str[cursor])
		word[i++] = str[cursor++];
	word[i] = '\0';
	return (word);
}

char	**ft_split_ps(char *str, char separator)
{
	int		word_count;
	char	**words_vector;
	int		i;

	word_count = count_words(str, separator);
	if (!word_count)
		exit(1);
	words_vector = malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (NULL == words_vector)
		return (NULL);
	i = 0;
	while (word_count-- >= 0)
	{
		if (0 == i)
		{
			words_vector[i] = malloc(sizeof(char));
			if (NULL == words_vector[i])
				return (NULL);
			words_vector[i++][0] = '\0';
			continue ;
		}
		words_vector[i++] = get_next_word(str, separator);
	}
	words_vector[i] = NULL;
	return (words_vector);
}
