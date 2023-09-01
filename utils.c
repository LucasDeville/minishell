/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:41:44 by ldeville          #+#    #+#             */
/*   Updated: 2023/08/31 18:27:51 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int	ft_count_args(char *line)
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
}*/


operator	ft_find_operator(char *str, int l)
{
	if (str[l] == '||')
		return (OP_2PIPE);
	else if (str[l] == '&&')
		return (OP_2AMP);
	else if (str[l] == '<' && str[l - 1] == '<')
		return (OP_2INF);
	else if (str[l] == '<')
		return (OP_INF);
	else if (str[l] == '>' && str[l - 1] == '>')
		return (OP_2SUP);
	else if (str[l] == '>')
		return (OP_SUP);
}

int	ft_has_operator(t_mini *mini)
{
	int		i;
	char	c;

	i = 0;
	while (mini->line[i])
	{
		c = mini->line[i];
		if (c == '|' || (c == '&' && mini->line[i + 1] == '&') || c == '(' 
			|| c == ')' || c == '<' || c == '>')
			return (1);
		i++;
	}
	return (0);
}
