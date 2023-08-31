/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:50:33 by bpleutin          #+#    #+#             */
/*   Updated: 2023/08/31 16:31:38 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_mini *mini)
{
	if (mini->size_args > 2)
		printf("exit: too many arguments\n");
	else
		mini->exit = 1;
}

void	ft_command(t_mini *mini)
{
	int	i;

	i = 0;
	if (mini->line[0])
	{
		while (mini->line[i] == ' ' || (mini->line[i] >= 9 && mini->line[i] <= 13))
			i++;
		if (ft_strncmp(mini->line + i, "exit", 4) == 0)
			ft_exit(mini);
		else if (ft_strncmp(mini->line + i, "echo", 4) == 0)
			mini->exit = 1;
		else if (ft_strncmp(mini->line + i, "cd", 2) == 0)
			mini->exit = 1;
		else if (ft_strncmp(mini->line + i, "pwd", 3) == 0)
			mini->exit = 1;
		else if (ft_strncmp(mini->line + i, "export", 6) == 0)
			mini->exit = 1;
		else if (ft_strncmp(mini->line + i, "unset", 5) == 0)
			mini->exit = 1;
		else if (ft_strncmp(mini->line + i, "env", 3) == 0)
			mini->exit = 1;
	}
	mini->size_args = 1;
}
