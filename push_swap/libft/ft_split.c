/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:53:48 by esimpson          #+#    #+#             */
/*   Updated: 2024/01/30 16:31:33 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	word_cnt;

	word_cnt = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			word_cnt++;
		while (*s && *s != c)
			++s;
	}
	return (word_cnt);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static char	**free_array(char **arr, size_t k)
{
	while (k-- > 0)
		free(arr[k]);
	free(arr);
	return (NULL);
}

static char	**result_array(size_t size, char **res_arr, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < size)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		if (end > start)
			res_arr[i] = word_dup(s, start, end);
		if (!res_arr[i])
			return (free_array(res_arr, i));
		start = end;
		i++;
	}
	res_arr[i] = NULL;
	return (res_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	size;

	size = ft_count_words(s, c);
	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	result = result_array(size, result, s, c);
	if (!result)
		return (NULL);
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s;
// 	char	c;
// 	char	**sp;
// 	int		cnt;

// 	s = "sggftjkkkk";
// 	c = ' ';
// 	cnt = ft_count_words(s, c);
// 	sp = ft_split(s, c);
// 	while (cnt--)
// 		printf("\n %s", sp[cnt]);
// 	return (0);
// }
