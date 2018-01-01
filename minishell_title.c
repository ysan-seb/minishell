/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_title.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 13:33:05 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/18 14:28:33 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_title(void)
{
	ft_putendl("\n\n\e[38;5;208m");
	ft_putstr("\t    _/      _/  _/            _/");
	ft_putendl("            _/                  _/  _/");
	ft_putstr("\t   _/_/  _/_/      _/_/_/      ");
	ft_putendl("    _/_/_/  _/_/_/      _/_/    _/  _/ ");
	ft_putstr("\t  _/  _/  _/  _/  _/    _/  _/ ");
	ft_putendl(" _/_/      _/    _/  _/_/_/_/  _/  _/  ");
	ft_putstr("\t _/      _/  _/  _/    _/  _/  ");
	ft_putendl("    _/_/  _/    _/  _/        _/  _/   ");
	ft_putstr("\t_/      _/  _/  _/    _/  _/  ");
	ft_putendl("_/_/_/    _/    _/    _/_/_/  _/  _/    ");
	ft_putendl("\e[0m\n\n");
}

void	my_prompt(void)
{
	char *pwd;

	pwd = NULL;
	pwd = getcwd(pwd, 512);
	ft_putstr("\e[38;5;208mMinishell");
	ft_putstr(" \e[38;5;240m");
	ft_putstr(pwd);
	ft_putstr(": \e[0m");
	free(pwd);
}
