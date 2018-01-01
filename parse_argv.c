/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:36:53 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/18 14:20:22 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		parse_argv(char **argv)
{
	char	*path;

	path = get_env("PATH=", 5);
	if ((ft_strequ(argv[0], ".") && argv[1] == NULL) ||
			(ft_strequ(argv[0], "..") && argv[1] == NULL))
	{
		ft_putstr(argv[0]);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (is_bui(argv) == -1 && is_cmd(path, argv) == -1)
	{
		ft_putstr(argv[0]);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (is_bui(argv) == 0 && is_cmd(path, argv) == 0)
		exc_bui(argv);
	else if (is_bui(argv) == 0 && is_cmd(path, argv) == -1)
		exc_bui(argv);
	else if (is_bui(argv) == -1 && is_cmd(path, argv) == 0)
		exc_cmd(path, argv);
}

int			is_bui(char **argv)
{
	if (ft_strequ(argv[0], "env") || ft_strequ(argv[0], "setenv") ||
			ft_strequ(argv[0], "unsetenv") || ft_strequ(argv[0], "echo")
			|| ft_strequ(argv[0], "cd") || ft_strequ(argv[0], "exit"))
		return (0);
	return (-1);
}

int			is_cmd(char *path, char **argv)
{
	int		i;
	char	*cmd;
	char	**tab_path;

	i = 0;
	tab_path = NULL;
	if (((access(argv[0], F_OK) == 0) && argv[0][0] == '.'
				&& argv[0][1] == '/') || ((access(argv[0], F_OK) == 0)
					&& argv[0][0] == '/'))
		return (0);
	if (!path)
		return (-1);
	tab_path = ft_strsplit(path, ':');
	while (tab_path && tab_path[i])
	{
		cmd = build_path(argv, tab_path, i);
		if ((access(cmd, F_OK) == 0))
			return (next(&cmd, &tab_path));
		free(cmd);
		i++;
	}
	free_tab(tab_path);
	return (-1);
}

char		*build_path(char **argv, char **tab_path, int i)
{
	char	*tmp;
	char	*cmd;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen(tab_path[i]) + 2));
	ft_strcpy(tmp, tab_path[i]);
	if (tab_path[i][ft_strlen(tab_path[i]) - 1] != '/')
		ft_strcat(tmp, "/");
	cmd = ft_strjoin(tmp, argv[0]);
	free(tmp);
	return (cmd);
}

int			next(char **cmd, char ***tab_path)
{
	free(*cmd);
	free_tab(*tab_path);
	return (0);
}
