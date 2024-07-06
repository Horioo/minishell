/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:04:07 by luiberna          #+#    #+#             */
/*   Updated: 2024/07/04 20:04:48 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Atualizei para funcionar com os builtins - Artur

int    execute(t_cmd *cmd, t_env *env)
{
    if (ft_strncmp(cmd->cmd[0], "cd", 3) == 0)
        builtin_cd(env, cmd);
    else if (ft_strncmp(cmd->cmd[0], "pwd", 4) == 0)
        builtin_pwd(cmd);
    else if (ft_strncmp(cmd->cmd[0], "echo", 5) == 0)
        builtin_echo(cmd->cmd);
    else if (ft_strncmp(cmd->cmd[0], "export", 8) == 0)
        builtin_export(env, cmd);
    else if (ft_strncmp(cmd->cmd[0], "unset", 7) == 0)
        builtin_unset(env, cmd);
    else if (ft_strncmp(cmd->cmd[0], "env", 4) == 0)
        builtin_env(env);
    else if (ft_strncmp(cmd->cmd[0], "exit", 5) == 0)
        builtin_exit(cmd, cmd->cmd);
    else
        return (execve(cmd->path, cmd->cmd, env->envp));
	return (1);
}
