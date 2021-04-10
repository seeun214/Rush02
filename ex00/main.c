/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:36:28 by keokim            #+#    #+#             */
/*   Updated: 2021/04/10 10:13:40 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	throw_error(void)
{
	write(2, "Error\n", 6);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		throw_error();
	else if (argc == 2)
	{
		//if (!is_valid(argv[1]))
			//throw_error();
		rush(argc, argv);
	}
}
