/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:07:59 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/07/06 11:40:23 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	check_flag(char *arg)
{
	int i;

	i = 1;
	if(arg[0] != '-')
		return (0);
	while(arg[i] && arg[i] == 'n')
		i++;
	if(arg[i] == '\0')
		return (1);
	return (0);
}

void print_echo(char **cmd, int n_flag, int i)
{
	int j;

	if(!cmd[i])
	{
		if(!n_flag)
			write(1, "\n", 1);
		return ;
	}
	while(cmd[i])
	{
		j = 0;
		while(cmd[i][j])
		{
			if(cmd[i][j] == '"')
				;
			else 
				write(1, &cmd[i][j], 1);
			j++;
		}
		if(cmd[i + 1])
			write(1, " ", 1);
		else if(!cmd[i + 1] && !n_flag)
			write(1, "\n", 1);
		i++;
	}
}

void	builtin_echo(char **cmd)
{
	int n_flag;
	int i;

	i = 1;
	n_flag = 0;
	while(cmd[i] && check_flag(cmd[i]))
	{
		n_flag = 1;
		i++;
	}
	print_echo(cmd, n_flag, i);
	//Update global Var para 1
}