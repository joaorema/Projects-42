/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:51:07 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/12/16 14:52:44 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char sep)
{
	int	count;
	int	i;
	int	flag;

	i = 0;
	count = 0;
	while (str[i])
	{
		flag = 0;
		while (str[i] && str[i] == sep)
			i++;
		while (str[i] && str[i] != sep)
		{
			if (!flag)
			{
				count++;
				flag = 1;
			}
			i++;
		}
	}
	return (count);
}

static char	*next_word(char *str, char sep)
{
	static int	pos = 0;
	char	*next_str;
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[pos] == sep)
	{
		pos++;
	}
	while ((str[pos + len]) && str[pos + len] != sep)
	{
		len++;
	}
	next_str = malloc(sizeof(char) * (size_t) len + 1); 
	if (!next_str)
	{
		return NULL;
	}
	while ((str[pos]) && str[pos] != sep)
	{
		next_str[i] = str[pos++];
	}
	next_str[i] = '\0';
	return (next_str);
}

char	**split(char *str, char sep)
{
	int	wc;
	int	i;
	char 	**strings;

	i = 0;
	wc = count_words(str, sep);
	if (!wc)
	{
		return 0;
	}
	strings = malloc(sizeof(char *) * (size_t)(wc + 2));
	if (!strings)
	{
		return NULL;
	}
	while (wc-- >= 0)
	{
		if(i == 0)
		{
			strings[i] = malloc(sizeof(char));
			if (!strings[i])
			{
				return NULL;
			}
			strings[i++][0] = '\0';
			continue ;
		}
		strings[i++] = next_word(str, sep);
	}
	strings[i] = NULL;
	return (strings);
}
