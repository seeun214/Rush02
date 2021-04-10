/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 11:42:54 by keokim            #+#    #+#             */
/*   Updated: 2021/04/10 11:46:37 by keokim           ###   ########.fr       */
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

int		is_valid_num(char *str)
{
	if (!str || (*str == '0' && *(str + 1)))
		return (0);
	while (*str)
	{
		if (!is_number(*str))
			return (0);
		str++;
	}
	return (1);
}
