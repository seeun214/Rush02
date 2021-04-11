/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:27:30 by keokim            #+#    #+#             */
/*   Updated: 2021/04/11 19:50:05 by kwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	g_unit;

void	print_all_zero(char *buffer, char *str, int i, int len)
{
	if (str[i] != '0')
	{
		ft_write_char(str[i], buffer, 0);
		print_unit(buffer, len - i);
		g_unit = 1;
	}
	else
	{
		if (g_unit == 0)
		{
			print_unit(buffer, len - i);
			g_unit = 1;
		}
	}
}

int		print_all_one(char *buffer, char *str, int i, int len)
{
	char temp[3];

	temp[0] = str[i];
	temp[2] = 0;
	if (str[i] == '1')
	{
		temp[1] = str[i + 1];
		ft_write_str(temp, buffer, len - i - 2);
		i++;
		if (len - i - 1 != 0)
		{
			print_unit(buffer, len - i);
			g_unit = 1;
		}
	}
	else if (str[i] != '0')
	{
		temp[1] = '0';
		if (str[i + 1] != '0')
			len++;
		ft_write_str(temp, buffer, len - i - 2);
	}
	return (i);
}

void	print_unit(char *buffer, int zamt)
{
	char	unit[40];
	int		j;

	unit[0] = '1';
	j = 1;
	while (j < zamt)
	{
		unit[j] = '0';
		j++;
	}
	unit[j] = 0;
	ft_write_str(unit, buffer, 1);
}

int		print_all_sub(char *buffer, char *str, int i, int len)
{
	if (len - i - 1 == 0)
	{
		if (str[i] != '0')
			ft_write_char(str[i], buffer, 1);
	}
	else if ((len - i - 1) % 3 == 2)
	{
		if (str[i] != '0')
		{
			ft_write_char(str[i], buffer, 0);
			ft_write_str("100", buffer, 1);
		}
	}
	else if ((len - i - 1) % 3 == 1)
	{
		if (str[i] != '0')
			i = print_all_one(buffer, str, i, len);
	}
	else
		print_all_zero(buffer, str, i, len);
	return (i);
}

void	print_all(char *buffer, char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	g_unit = 0;
	i = -1;
	while (++i < len)
	{
		i = print_all_sub(buffer, str, i, len);
	}
}
