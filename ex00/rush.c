/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:48:52 by keokim            #+#    #+#             */
/*   Updated: 2021/04/10 11:40:18 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	rush(int argc, char **argv)
{
	int		fd;
	int		dict_read;
	char	buf[1024];

	if ((fd = open(DICT_FILE, O_RDONLY)) == -1)
	{
		throw_error();
		return ;
	}
	dict_read = read(fd, buf, 100);
	if (ft_strstr(buf, argv[1]))
		write(1, ft_strstr(buf, argv[1]), 6);
	else
		throw_error();
	close(fd);
}
