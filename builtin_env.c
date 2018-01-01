/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:44:37 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/18 14:13:31 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		realloc_env(char *str)
{
	int			i;
	int			size;
	char		**tmp;
	extern char **environ;

	i = 0;
	if (!*environ)
	{
		if (!(environ = ft_memalloc(sizeof(char*))))
			return (0);
	}
	size = tab_size(environ) + 2;
	tmp = (char **)malloc(sizeof(char *) * size);
	if (!environ)
		return (0);
	while (environ[i])
	{
		tmp[i] = environ[i];
		i++;
	}
	tmp[i] = str;
	tmp[i + 1] = NULL;
	free(environ);
	environ = tmp;
	return (1);
}

void	builtin_env(void)
{
	int			i;
	extern char	**environ;

	if (!*environ)
		return ;
	i = 0;
	while (environ[i])
	{
		ft_putendl(environ[i]);
		i++;
	}
}

int		loc_var_env(char *str, int n, char **env)
{
	int		i;

	i = 0;
	while (env && env[i])
	{
		if (ft_strnequ(env[i], str, n) && env[i][n] == '=')
			return (i);
		i++;
	}
	return (-1);
}

void	builtin_setenv(char **env, char *name, char *value)
{
	int		pos;
	int		size;
	char	*tmp;
	char	*tmp_b;

	size = tab_size(env);
	tmp_b = (char *)malloc(sizeof(char) * ft_strlen(name) + 2);
	ft_strcpy(tmp_b, name);
	if (name[ft_strlen(name) - 1] != '=')
		ft_strcat(tmp_b, "=");
	if (loc_var_env(name, ft_strlen(name), env) > 0)
	{
		pos = loc_var_env(name, ft_strlen(name), env);
		free(env[pos]);
		env[pos] = ft_strjoin(tmp_b, value);
		var_env_color(env[pos], 2);
	}
	else
	{
		tmp = ft_strjoin(tmp_b, value);
		realloc_env(tmp);
		var_env_color(tmp, 1);
	}
	free(tmp_b);
}

char	**builtin_unsetenv(char **env, char *name)
{
	int		i;
	int		j;
	int		pos;
	int		size;
	char	**tmp;

	i = 0;
	j = 0;
	size = tab_size(env);
	pos = loc_var_env(name, ft_strlen(name), env);
	tmp = (char **)malloc(sizeof(char *) * size);
	if (!get_env(name, ft_strlen(name)))
		return (env);
	while (env[i])
	{
		(i == pos) ? i++ : 0;
		tmp[j] = ft_strdup(env[i]);
		env[i] ? i++ : 0;
		j++;
	}
	tmp[j] = NULL;
	var_env_color(env[pos], 3);
	free_tab(env);
	env = tmp;
	return (env);
}
