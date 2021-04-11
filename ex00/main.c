/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:36:28 by keokim            #+#    #+#             */
/*   Updated: 2021/04/11 21:09:24 by kwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	throw_error(void)
{
	write(2, "Error\n", 6);
}

void	dict_error(void)
{
	write(2, "Dict Error\n", 11);
}

int		main(int argc, char **argv)
{
	char	*num;

	if (argc > 3 || argc == 1)
		throw_error();
	else if (argc == 2)
	{
		num = unique_num(argv[1]);
		if (is_valid_num(num))
			rush(DICT_FILE, num);
		free(num);
	}
	else if (argc == 3)
	{
		num = unique_num(argv[2]);
		if (is_valid_num(num))
			rush(argv[1], num);
		free(num);
	}
	return (0);
}
