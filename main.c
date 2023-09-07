/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:42:03 by ldeville          #+#    #+#             */
/*   Updated: 2023/09/05 11:16:24 by bpleutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all(t_mini *mini)
{
	if (mini->line)
		free(mini->line);
	if (mini->path)
		free(mini->path);
	/*if (mini->args->arg)
		free_lists(mini);*/
	free(mini);
}



void	ft_init_mini(t_mini *mini, char **env)
{
	int	j;
	int	i;

	j = 0;
	i = 4;
	mini->env = env;
	while (env[j] && ft_strncmp(env[j], "PWD=", 4))
		j++;
	mini->path = ft_strdup(&env[j][0] + 4);
	printf("%s", mini->path);
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)argc;
	t_mini	*mini;

	mini = ft_calloc(1, sizeof(t_mini));

	ft_init_mini(mini, env);
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
