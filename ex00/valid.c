/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 11:42:54 by keokim            #+#    #+#             */
/*   Updated: 2021/04/11 10:57:07 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int		is_num(char c)
{
	return ('0' <= c && c <= '9');
}

#include <stdio.h>
int		is_valid_num(char *num)
{
	char	*nbr;

	nbr = num;
	if (!num || (*num == '0' && *(num + 1)))
		return (0);
	while (*num)
	{
		if (!is_num(*num))
			return (0);
		num++;
	}
	if (ft_strlen(nbr) > 39)
		return (0);
	return (1);
}
