/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:42:25 by keokim            #+#    #+#             */
/*   Updated: 2021/04/10 12:34:09 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

# define DICT_FILE "numbers.dict"

typedef struct		s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}					t_dict;

void	throw_error(void);
void	rush(int argc, char **argv);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *s1, char *s2);
char	*ft_strstr(char *str, char *to_find);
int		is_space(char c);
int		is_num(char c);
int		is_valid_num(char *str);
int		is_space(char c);
int		is_num(char c);
int		is_valid_num(char *str);
int		ft_atoi(char *str);
char	*create_str(int size, char **strs, char *sep);
char	*ft_strjoin(int size, char **strs, char *sep);

#endif
