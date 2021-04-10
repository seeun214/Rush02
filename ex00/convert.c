/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:27:30 by keokim            #+#    #+#             */
/*   Updated: 2021/04/11 08:28:51 by kwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

void	ft_write_str(char *num, char *buffer, int last)
{
	int		i;
	int		size;
	char	*start_str;

	start_str = ft_strstr(buffer, num);
	size = ft_strlen(num);
	i = 0;
	while (start_str[i] && start_str[i] != '\n')
	{
		while (start_str[i] != ':')
			i++;
		if (start_str[i] == ':')
			i++;
		while (start_str[i] == ' ')
			i++;
		while (start_str[i] >= 32 && start_str[i] <= 126)
		{
			write(1, &start_str[i], 1);
			i++;
		}
	}
	if (last != 0)
		write(1, " ", 1);
}

void	ft_write_char(char c, char *buffer, int end)
{
	int		i;
	int		size;
	char	*start_str;
	char	num[2];

	num[0] = c;
	start_str = ft_strstr(buffer, num);
	size = ft_strlen(num);
	i = 0;
	while (start_str[i] && start_str[i] != '\n')
	{
		while (start_str[i] != ':')
			i++;
		if (start_str[i] == ':')
			i++;
		while (start_str[i] == ' ')
			i++;
		while (start_str[i] >= 32 && start_str[i] <= 126)
		{
			write(1, &start_str[i], 1);
			i++;
		}
	}
	if (end == 0)
		write(1, " ", 1);
}

int		print_all_zero(char *buffer, char *str, int i, int len, int unit)
{
	if(str[i] != '0')
	{
		ft_write_char(str[i], buffer, 0);
		print_unit(buffer, len - i);
		unit = 1;					
	}
	else 
	{
		if (unit == 0)
		{
			print_unit(buffer, len - i);
			unit = 1;					
		}
	}
	return (unit);
}

int		print_all_one(char *buffer, char *str, int i, int len, int *unit)
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
		   *unit = 1;
	   }
	}
	else if (str[i] != '0')
	{
		temp[1] = '0';
		ft_write_str(temp, buffer, 1);
	}
	return (i);
}

void	print_unit(char *buffer, int zamt)
{
    char unit[40];
	int j;
 
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

int    print_all_sub(char *buffer, char *str, int i, int len, int unit)
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
			ft_write_str("100", buffer,1 );
		}
	}
	else if ((len - i - 1) % 3 == 1)
	{
		if (str[i] != '0')
			i = print_all_one(buffer, str, i, len, &unit);
	}
	else
		unit = print_all_zero(buffer, str, i ,len, unit);
	return (i);
}

void    print_all(char *buffer, char *str)
{
    int i;
    int len;
	int unit;

    len = ft_strlen(str);
	unit = 0;
    i = -1;
    while (++i < len)
    {
		i =	print_all_sub(buffer, str, i, len, unit);
    }
}
