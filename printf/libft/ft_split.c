/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:55:18 by vserrao-          #+#    #+#             */
/*   Updated: 2021/10/29 19:25:07 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_all(char **str, int word)
{
	while (word--)
		free(str[word]);
	return (-1);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == c || str[i + 1] == '\0')
			&& !(str[i] == c || str[i] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	write_word(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (!(src[i] == c || src[i] == '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	do_split(char **split, const char *str, char c)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == c || str[i] == '\0'))
			i++;
		else
		{
			j = 0;
			while (!(str[i + j] == c || str[i + j] == '\0'))
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (split[word] == NULL)
				return (free_all(split, word - 1));
			write_word(split[word], str + i, c);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		words;

	if (!str)
		return (NULL);
	words = count_words(str, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	res[words] = 0;
	if (do_split(res, str, c) == -1)
		return (NULL);
	return (res);
}
/*
int	main(void)
{
	char	*str = "abbcdebfbgh";
	char	c = 'b';
	char	**res;
	int		i;

	i = 0;
	res = ft_split(str, c);
	while (i < 4)
	{
		printf("%s\n", res[i]);
		i++;
	}
}*/
