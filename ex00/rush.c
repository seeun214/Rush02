/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:48:52 by keokim            #+#    #+#             */
/*   Updated: 2021/04/10 21:41:06 by kwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	rush(char *dict, char *num)
{
	char	*buffer;

	buffer = ft_open_read(dict);
	print_all(buffer, num);
	free(buffer);
}
