/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:40:31 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/18 14:19:17 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <stdio.h>

void	print_env(void);
int		env_copy(void);
int		tab_size(char **tab);
char	**shlvl(void);
void	free_tab(char **tab);
void	my_prompt(void);
void	minishell_title(void);
char	**split(char const *s);
void	parse_argv(char **argv);
int		is_bui(char **argv);
int		is_cmd(char *path, char **argv);
char	*get_env(char *str, int n);
char	*build_path(char **argv, char **tab_path, int i);
void	exc_cmd(char *path, char **argv);
void	fork_cmd(char *cmd, char **argv);
void	exc_bui(char **argv);
void	builtin_echo(char **argv);
void	var_env_color(char *str, int n);
void	builtin_env(void);
void	bui_env(char **argv);
void	bui_setenv(char **argv, char **env);
char	**bui_unsetenv(char **argv, char **env);
void	builtin_setenv(char **env, char *name, char *value);
char	**builtin_unsetenv(char **env, char *name);
int		loc_var_env(char *str, int n, char **env);
int		is_dir(char *path);
void	builtin_cd(char **argv, char **env);
void	bui_cd(char **env);
void	bui_cd_(char **env);
void	bui_cd_arg(char **argv, char **env);
int		next(char **cmd, char ***tab_path);

#endif
