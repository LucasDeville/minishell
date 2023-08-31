/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:42:03 by ldeville          #+#    #+#             */
/*   Updated: 2023/08/31 10:18:16 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_mini *mini)
{
	free(mini);
}



void	ft_init_mini(t_mini *mini)
{
	mini->exit = 0;
	mini->args = 0;
	mini->line = NULL;
}

int	main(int argc, char **argv, char **str)
{
	(void)argv;
	(void)argc;
	(void)str;
	t_mini	*mini;

	mini = ft_calloc(1, sizeof(t_mini));

	ft_init_mini(mini);
	while (!mini->exit)
	{
		mini->line = readline("🔹𝓜 𝓲𝓷𝓲𝓼𝓱𝓮𝓵𝓵 ⦒ ");
		ft_pre_parse(mini);
		//mini->args = ft_count_args(mini->line);
		ft_command(mini);
		free(mini->line);
	}
	free_all(mini);
	return (0);
}
