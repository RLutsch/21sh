/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 13:45:17 by rlutsch           #+#    #+#             */
/*   Updated: 2016/08/07 14:58:03 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_echo(char **av)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (av[x++])
		if (av[x])
		{
			if (av[x][0] == '-')
				ft_dostuff(av[x++][1]);
			while (av[x][i])
			{
				if (av[x][i] == 92)
				{
					i++;
					ft_doflag(av[x][i++]);
				}
				if (av[x][i] != '"')
					ft_putchar(av[x][i]);
				i++;
			}
			i = 0;
			ft_putstr(" ");
		}
}

void	ft_doflag(char c)
{
	if (c == 'n')
		ft_putchar(10);
	if (c == '\\')
		ft_putchar(92);
	if (c == 'a')
		write(1, "\a", 1);
	if (c == 'b')
		ft_putchar(8);
	if (c == 'e')
		ft_putchar(27);
	if (c == 'f')
		ft_putchar(12);
	if (c == 'r')
		ft_putchar(13);
	if (c == 't')
		ft_putchar(9);
	if (c == 'v')
		ft_putchar(11);
}

void	ft_dostuff(char c)
{
	if (c == 'n')
		;
}
