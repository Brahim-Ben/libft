/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:59:08 by bbenaali          #+#    #+#             */
/*   Updated: 2024/11/19 09:52:40 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	for_free(char **copy, int word, int len)
{
	int	i;

	i = 0;
	copy[word] = malloc (sizeof(char) * (len + 1));
	if (copy[word] == NULL)
	{
		while (i < word)
		{
			free (copy[i]);
			i++;
		}
		return (1);
	}
	return (0);
}

static int	for_copy(char **copy, const char *s, char c)
{
	int	len;
	int	posistion_word;

	posistion_word = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0')
		{
			len++;
			s++;
		}
		if (len)
		{
			if (for_free(copy, posistion_word, len))
				return (1);
			ft_strlcpy(copy[posistion_word], s - len, len + 1);
			posistion_word++;
		}
	}
	return (0);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	tk;
	char	**copy;

	if (s == NULL)
		return (NULL);
	tk = ft_count_words (s, c);
	copy = malloc(sizeof(char *) * (tk + 1));
	if (copy == NULL)
		return (NULL);
	if (for_copy(copy, s, c))
	{
		free (copy);
		return (NULL);
	}
	copy[tk] = NULL;
	return (copy);
}