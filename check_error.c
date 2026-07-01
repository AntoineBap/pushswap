/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaptist <abaptist@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-17 09:34:48 by abaptist          #+#    #+#             */
/*   Updated: 2026-06-17 09:34:48 by abaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_prog(int status)
{
	ft_printf("Error : ");
	if (status == 0)
		ft_printf("%s\n", "First character isn't an integer");
	else if (status == 1)
		ft_printf("%s\n", "Two spaces or more in a row");
	else if (status == 2)
		ft_printf("%s\n", "Invalid character in the string");
	else if (status == 3)
		ft_printf("%s\n", "Not enough or too much arguments");
	else if (status == 4)
		ft_printf("%s\n", "Invalid strategy selector");
	else if (status == 5)
		ft_printf("%s\n", "Invalid disorder index");
	exit(status);
	return ;
}

int	is_number(char *str, int *i)
{
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
	if (!str[*i] || !ft_isdigit(str[*i]))
		return (0);
	while (str[*i] && ft_isdigit(str[*i]))
		(*i)++;
	return (1);
}

int	check_format(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '-' && (str[0] < '0' || str[0] > '9'))
		exit_prog(0);
	while (str[i])
	{
		if (!is_number(str, &i))
			exit_prog(2);
		if (str[i] == ' ')
		{
			i++;
			if (str[i] == ' ')
				exit_prog(1);
		}
		else if (str[i] != '\0')
			exit_prog(2);
	}
	return (1);
}
