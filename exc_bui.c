/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_bui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:43:59 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/18 14:16:05 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exc_bui(char **argv)
{
	extern char **environ;

	if (ft_strequ(argv[0], "env"))
		bui_env(argv);
	else if (ft_strequ(argv[0], "setenv"))
		bui_setenv(argv, environ);
	else if (ft_strequ(argv[0], "unsetenv"))
		environ = bui_unsetenv(argv, environ);
	else if (ft_strequ(argv[0], "cd"))
		builtin_cd(argv, environ);
	else if (ft_strequ(argv[0], "echo"))
		builtin_echo(argv);
	else if (ft_strequ(argv[0], "exit"))
	{
		free_tab(argv);
		exit(0);
	}
}

void	bui_env(char **argv)
{
	extern char **environ;

	if (environ && environ[0] && !argv[1])
		var_env_color(NULL, 0);
	else if (environ[0] == NULL)
		ft_putendl("\e[31;5;208menv is empty");
	else
		ft_putendl("usage: env");
}

void	bui_setenv(char **argv, char **env)
{
	if (argv[1] && argv[2] && !argv[3])
		builtin_setenv(env, argv[1], argv[2]);
	else
		ft_putendl("usage: setenv [name] [value]");
}

char	**bui_unsetenv(char **argv, char **env)
{
	if (argv[1] && !argv[2])
	{
		if (loc_var_env(argv[1], ft_strlen(argv[1]), env) >= 0)
		{
			if (argv[1] && !argv[2])
			{
				env = builtin_unsetenv(env, argv[1]);
				return (env);
			}
			else
				ft_putendl("usage: unsetenv [name]");
		}
	}
	else
		ft_putendl("usage: unsetenv [name]");
	return (env);
}
