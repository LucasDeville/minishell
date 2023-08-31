/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:52:03 by ldeville          #+#    #+#             */
/*   Updated: 2023/08/31 18:51:16 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_syntax_error(char *str)
{
	printf("🟥𝓜 𝓲𝓷𝓲𝓼𝓱𝓮𝓵𝓵: syntax error near unexpected token `%s'\n", str);
}

int	ft_check_op2(char *str, int i)
{
	if (str[i] == '<' && str[i + 1] == '<')
	{
		i += 2;
		if (str[i] == '<' && str[i + 1] == '<' )
			return (ft_syntax_error("<"), -1);
		else if (str[i] == '<')
			return (ft_syntax_error("newline"), -1);
	}
	if (str[i] == '>' && str[i + 1] == '>')
	{
		i += 2;
		if (str[i] == '>' && str[i + 1] == '>' )
			return (ft_syntax_error(">>"), -1);
		else if (str[i] == '>')
			return (ft_syntax_error(">"), -1);
	}
	return (0);
}

int	ft_check_op1(char *str, int i)
{
	if (str[i] == '|' && str[i + 1] == '|')
	{
		i += 2;
		if (str[i] == '|' && str[i + 1] == '|' )
			return (ft_syntax_error("||"), -1);
		else if (str[i] == '|')
			return (ft_syntax_error("|"), -1);
	}
	if (str[i] == '&')
	{
		if (str[i + 1] != '&')
			return (ft_syntax_error("&"), -1);
		i += 2;
		if (str[i] == '&' && str[i + 1] == '&' )
			return (ft_syntax_error("&&"), -1);
		else if (str[i] == '&')
			return (ft_syntax_error("&"), -1);
	}
	return (ft_check_op2(str, i));
}

int	ft_check_line(char *str)
{
	int	i;
	int	quote;

	i = 0;
	quote = -1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (!str[i] || ft_check_op1(str, i) == -1)
		return (-1);
	if (str[i] == '|' || str[i] == '&' || str[i] == '\\')
		return (printf("🔹𝓜 𝓲𝓷𝓲𝓼𝓱𝓮𝓵𝓵: syntax error near unexpected token `%c'", str[i]), -1);
	while (str[i])
	{
		if (str[i] == '\'' || str [i] == '"')
			quote *= -1;
		if (quote == -1 && ft_check_op1(str, i) == -1)
			return (-1);
		i++;
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
	}
	if (quote != -1)
		return (printf("🟥𝓜 𝓲𝓷𝓲𝓼𝓱𝓮𝓵𝓵: syntax error quote not closed\n"), -1);
	return (0);
}
