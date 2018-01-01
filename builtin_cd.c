/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:48:06 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/18 13:44:22 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_cd(char **argv, char **env)
{
	if (ft_strequ(argv[0], "cd") && argv[1] == NULL)
		bui_cd(env);
	else if (ft_strequ(argv[0], "cd") && ft_strequ(argv[1], "-"))
		bui_cd_(env);
	else if (ft_strequ(argv[0], "cd") && argv[1])
		bui_cd_arg(argv, env);
}

void	bui_cd(char **env)
{
	char *pwd;

	pwd = NULL;
	pwd = getcwd(pwd, 512);
	builtin_setenv(env, "OLDPWD", pwd);
	free(pwd);
	chdir(get_env("HOME", 5));
	pwd = getcwd(pwd, 512);
	builtin_setenv(env, "PWD", pwd);
}

void	bui_cd_(char **env)
{
	char *tmp;
	char *pwd;

	pwd = NULL;
	if (get_env("OLDPWD", 7))
	{
		tmp = getcwd(pwd, 512);
		chdir(get_env("OLDPWD", 7));
		builtin_setenv(env, "OLDPWD", tmp);
		free(tmp);
		pwd = getcwd(pwd, 512);
		builtin_setenv(env, "PWD", pwd);
		free(pwd);
	}
	else
		ft_putendl("\e[31;5;208mOLDPWD not set\e[0m");
}

void	bui_cd_arg(char **argv, char **env)
{
	char *pwd;

	pwd = NULL;
	if (is_dir(argv[1]) == 1)
	{
		pwd = getcwd(pwd, 512);
		builtin_setenv(env, "OLDPWD", pwd);
		free(pwd);
		chdir(argv[1]);
		pwd = getcwd(pwd, 512);
		builtin_setenv(env, "PWD", pwd);
	}
	else
	{
		ft_putstr("cd: ");
		ft_putstr(argv[1]);
		ft_putendl(": No such file or directory");
	}
}

int		is_dir(char *path)
{
	struct stat st;

	stat(path, &st);
	if (S_ISDIR(st.st_mode))
		return (1);
	else
		return (0);
}
