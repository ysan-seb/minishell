/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:34:30 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/18 14:21:13 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**shlvl(void)
{
	int			i;
	int			j;
	char		**tmp;
	extern char **environ;

	i = 0;
	if (!*environ)
		return (NULL);
	while (environ[i])
	{
		if (ft_strnequ(environ[i], "SHLVL=", 6))
		{
			tmp = ft_strsplit(environ[i], '=');
			j = ft_atoi(tmp[1]) + 1;
			free(tmp[1]);
			tmp[1] = ft_itoa(j);
			free(environ[i]);
			environ[i] = ft_strjoin("SHLVL=", tmp[1]);
			free_tab(tmp);
		}
		i++;
	}
	return (environ);
}

int		tab_size(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		env_copy(void)
{
	int			i;
	int			size;
	char		**env;
	extern char	**environ;

	i = 0;
	env = NULL;
	if (!*environ)
		return (0);
	size = tab_size(environ);
	env = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		if (!(env[i] = ft_strdup(environ[i])))
			return (0);
		i++;
	}
	env[i] = NULL;
	environ = env;
	return (1);
}

void	print_env(void)
{
	int			i;
	extern char	**environ;

	i = 0;
	while (environ[i])
	{
		ft_putendl(environ[i]);
		i++;
	}
}

int		main(void)
{
	char **env;
	char *line;
	char **argv;

	line = NULL;
	env_copy();
	env = shlvl();
	minishell_title();
	(void)env;
	while (1)
	{
		my_prompt();
		if (get_next_line(0, &line) <= 0)
			break ;
		if (line)
		{
			argv = split(line);
			if (argv[0] != NULL)
				parse_argv(argv);
			free(line);
		}
		(argv) ? free_tab(argv) : 0;
	}
	return (0);
}
