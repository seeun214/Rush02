/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:58:29 by keokim            #+#    #+#             */
/*   Updated: 2021/04/11 21:14:17 by kwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*ft_open_read(char *dict)
{
	int		fd;
	char	*buffer;
	int		file_read;
	int		file_size;

	if (!(buffer = (char *)malloc((sizeof(char) * 2048))))
	{
		dict_error();
		return (0);
	}
	file_size = 0;
	fd = open(dict, O_RDONLY);
	if ((file_read = read(fd, buffer, 2048)) == -1)
	{
		dict_error();
		return (0);
	}
	else
	{
		file_size = file_read;
		close(fd);
	}
	return (buffer);
}
