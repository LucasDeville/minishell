/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeville <ldeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:43:32 by ldeville          #+#    #+#             */
/*   Updated: 2023/08/31 17:50:08 by ldeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef enum e_operator
{
	OP_NONE	= 0,
	OP_PIPE,
	OP_2PIPE,
	OP_2AMP,
	OP_INF,
	OP_2INF,
	OP_SUP,
	OP_2SUP,
	OP_WILD
}	operator;

typedef enum e_amp
{
	AMP_FALSE = -1,
	AMP_NONE,
	AMP_SUCCESS,
}	prev_amp;

typedef enum e_or
{
	OR_FALSE = -1,
	OR_NONE,
	OR_SUCCESS,
}	prev_or;

# include "Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef	struct	s_lists
{
	char			*arg;
	operator 		operator;
	prev_amp		prev_amp;
	prev_or			prev_or;
	int				is_pipe;
	char			*result;
	int				priorities;
	struct s_lists	*previous;
	struct s_lists	*next;
}	t_lists;

typedef struct s_mini
{
	char	*line;
	int		size_args;
	t_lists	*args;
	int		has_operator;
	int		exit;
}		t_mini;

void	ft_command(t_mini *mini);
void    ft_pre_parse(t_mini *mini);
int		ft_has_operator(t_mini *mini);
int		ft_check_line(char *str);

#endif
