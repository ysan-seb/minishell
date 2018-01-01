/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:35:16 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/18 14:21:20 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	var_env_color(char *str, int n)
{
	if (n == 0)
		builtin_env();
	else if (n == 1)
	{
		ft_putstr("\e[32;5;208m[New] ");
		ft_putstr(str);
		ft_putstr("\e[0m\n");
	}
	else if (n == 2)
	{
		ft_putstr("\e[33;5;208m[Mod] ");
		ft_putstr(str);
		ft_putstr("\e[0m\n");
	}
	else if (n == 3)
	{
		ft_putstr("\e[31;5;208m[Del] ");
		ft_putstr(str);
		ft_putstr("\e[0m\n");
	}
}

char	*get_env(char *str, int n)
{
	int			i;
	extern char	**environ;

	i = 0;
	if (!*environ)
		return (NULL);
	while (environ[i])
	{
		if (ft_strnstr(environ[i], str, n))
			return (environ[i] + n);
		i++;
	}
	return (NULL);
}

void	free_tab(char **tab)
{
	int i;
	int size;

	i = 0;
	size = tab_size(tab);
	while (i < size)
	{
		ft_strclr(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
}
