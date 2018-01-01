/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:47:49 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/17 16:47:50 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_echo(char **argv)
{
	int i;

	i = (ft_strequ(argv[1], "-n")) ? 2 : 1;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		if (argv[i + 1])
			ft_putchar(' ');
		i++;
	}
	if (!ft_strequ(argv[1], "-n"))
		ft_putchar('\n');
}
