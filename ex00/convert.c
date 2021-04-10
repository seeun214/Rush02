/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:27:30 by keokim            #+#    #+#             */
/*   Updated: 2021/04/10 23:10:02 by kwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

void	ft_write_str(char *num, char *buffer)
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
	write(1, " ", 1);
}

void	ft_write_char(char c, char *buffer)
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
	write(1, " ", 1);
}

int		print_all_one(char *buffer, char *str, int i, int len)
{
	char temp[3];

	temp[0] = str[i];
	if (str[i] == '1')
	{
	   temp[1] = str[i + 1];
	   ft_write_str(temp, buffer);
	   i++;
	   if (len - i - 1 != 0)
		   print_unit(buffer, len - i);
	}
	else if (str[i] != '0')
	{
		temp[1] = '0';
		ft_write_str(temp, buffer);
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
	ft_write_str(unit, buffer);
}
void    print_all(char *buffer, char *str)
{
    int i;
    int len;
	int unit;

    len = ft_strlen(str);
    i = 0;
	unit = 0;
    while (i < len)
    {
        if (len - i - 1 == 0)
		{
			if (str[i] != '0')
	            ft_write_char(str[i], buffer);
		}
        else if ((len - i - 1) % 3 == 2)
        {	
			if (str[i] != '0')
			{	
				ft_write_char(str[i], buffer);
				write(1, " ", 1);
            	ft_write_str("100", buffer);
			}
        }
        else if ((len - i - 1) % 3 == 1)
		{
			if (str[i] != '0')
        		i = print_all_one(buffer, str, i, len);
		}
		else
        {
			if (str[i] != '0')
			{
				ft_write_char(str[i], buffer);
				print_unit(buffer, len - i);
			}
			else 
			{
				if (unit == 0)
				{
					print_unit(buffer, len - i);
					unit++;					
				}
			}
        }
        i++;
    }
}
