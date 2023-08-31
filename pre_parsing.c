/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:17:16 by ldeville          #+#    #+#             */
/*   Updated: 2023/08/31 18:03:43 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_args(char *line)
{
	int	res;
	int	i;

	if (!line)
		return (0);
	res = 0;
	i = 0;
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	while (line[i])
	{
		if (line[i] >= 33 && line[i] <= 126)
			res++;
		while (line[i] && line[i] >= 33 && line[i] <= 126)
			i++;
		while (line[i] && (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
			i++;
	}
	return (res);
}

void	ft_init_lists(t_mini *mini)
{
	if (mini->has_operator == 0)
    	mini->args = ft_calloc(ft_count_args(mini->line), sizeof(t_lists));
	else
	{
		//parse operator
	}


}

void    ft_pre_parse(t_mini *mini)
{
	if (ft_check_line(mini->line) == -1)
		return ;
	printf("check success\n");
	mini->has_operator = ft_has_operator(mini);
	//ft_init_lists(mini);
}