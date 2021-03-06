/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:51:58 by keokim            #+#    #+#             */
/*   Updated: 2021/04/11 00:14:34 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*unique_num(char *num)
{
	char	*uni_n;
	char	*front;
	char	*back;
	int		i;

	i = 0;
	if (!*num)
		return (0);
	front = num;
	while (*front && is_space(*front))
		front++;
	back = front;
	while (*back)
		back++;
	back -= 1;
	while (is_space(*back))
		back--;
	if ((uni_n = (char *)malloc(back - front + 1)) == NULL)
		return (0);
	ft_strcpy(uni_n, front, back);
	while (uni_n[i])
		i++;
	uni_n[i] = '\0';
	return (uni_n);
}
