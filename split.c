/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:58:37 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/18 14:28:25 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		count_length(int i, char const *s)
{
	int			lengthword;

	lengthword = i;
	while (s[lengthword] != ' ' && s[lengthword] != '\t'
			&& s[lengthword] != '\0')
		lengthword++;
	lengthword = lengthword - i;
	return (lengthword);
}

static int		ft_countwords(char const *s)
{
	int			i;
	int			nbwords;

	i = 0;
	nbwords = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\t')
			i++;
		else
		{
			while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
				i++;
			nbwords++;
		}
	}
	return (nbwords);
}

static char		**do_split(int i, char const *s, char **str)
{
	int			lengthword;
	int			j;
	int			k;

	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\t')
			i++;
		else
		{
			lengthword = count_length(i, s);
			str[j] = (char *)malloc(sizeof(char) * (lengthword + 1));
			while (lengthword-- > 0)
			{
				str[j][k++] = s[i++];
			}
			str[j++][k] = '\0';
			k = 0;
			lengthword = 0;
		}
	}
	str[j] = NULL;
	return (str);
}

char			**split(char const *s)
{
	int			i;
	char		**str;
	int			nbwords;
	char		*str2;

	i = 0;
	if (s)
	{
		nbwords = ft_countwords(s);
		str = (char **)malloc((nbwords + 1) * sizeof(char *));
		if (str == 0)
			return (0);
		str = do_split(i, s, str);
		return (str);
	}
	else
	{
		str2 = ft_strnew(0);
		return ((char **)str2);
	}
}
