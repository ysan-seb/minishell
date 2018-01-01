/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:42:02 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/18 12:16:54 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		exc_cmd(char *path, char **argv)
{
	int		i;
	char	*cmd;
	char	**tab_path;

	i = 0;
	if ((access(argv[0], F_OK) == 0))
	{
		cmd = ft_strdup(argv[0]);
		fork_cmd(cmd, argv);
		return ;
	}
	tab_path = ft_strsplit(path, ':');
	while (tab_path[i])
	{
		cmd = build_path(argv, tab_path, i);
		if ((access(cmd, F_OK) == 0))
			break ;
		free(cmd);
		i++;
	}
	free_tab(tab_path);
	fork_cmd(cmd, argv);
}

void		fork_cmd(char *cmd, char **argv)
{
	pid_t		pid;
	extern char	**environ;

	if ((pid = fork()) < 0)
		ft_putstr("Une erreur ses produit fork == -1");
	if (pid > 0)
		wait(NULL);
	if (pid == 0)
	{
		execve(cmd, argv, environ);
		ft_putstr("minishell: fichier non trouver\n");
		exit(-1);
	}
	else
		free(cmd);
}
