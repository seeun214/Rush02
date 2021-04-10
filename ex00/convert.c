/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:27:30 by keokim            #+#    #+#             */
/*   Updated: 2021/04/10 21:43:50 by kwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_write_char(char *num, char *buffer)
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
}

int		print_all_one(char *buffer, char *str, int i, int len)
{
	char temp[3];

	temp[0] = str[i];
	if (str[i] == '1')
	{
	   temp[1] = str[i + 1];
	   ft_write_char(temp, buffer);
	   i++;
	   print_unit(buffer, len - i);
	}
	else if (str[i] != '0')
	{
		temp[1] = '0';
		ft_write_char(temp, buffer);
	}
	return (i);
}

void	print_unit(char *buffer, int zamt)
{
    char unit[40];
	int j;
 
	unit[0] = '1';
	j = 0;
	while (++j < zamt)
		unit[j] = '0';
	ft_write_char(unit, buffer);
}
void    print_all(char *buffer, char *str)
{
    int i;
    int len;

    len = ft_strlen(str);
    i = 0;
    while (i < len)
    {
        if (len - i - 1 == 0)
            ft_write_char(&str[i], buffer);
        else if ((len - i - 1) % 3 == 2)
        {
            ft_write_char(&str[i], buffer);
            ft_write_char("100", buffer);
        }
        else if ((len - i - 1) % 3 == 1)
        	i = print_all_one(buffer, str, i, len);
		else
        {
            ft_write_char(&str[i], buffer);
			print_unit(buffer, len - i);
        }
        i++;
    }
}
