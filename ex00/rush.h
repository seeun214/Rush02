/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:42:25 by keokim            #+#    #+#             */
/*   Updated: 2021/04/11 22:10:44 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define DICT_FILE "default.dict"

void	throw_error(void);
void	dict_error(void);
void	rush(char *dict, char *num);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_strcpy(char *dst, char *begin, char *end);
char	*ft_strstr(char *str, char *to_find);
int		is_space(char c);
int		is_num(char c);
int		is_valid_num(char *str);
int		is_num(char c);
int		is_valid_num(char *str);
void	ft_write_str(char *num, char *buffer, int last);
void	ft_write_char(char c, char *buffer, int end);
char	*ft_open_read(char *dict);
int		print_all_one(char *buffer, char *str, int i, int len);
int		print_all_sub(char *buffer, char *str, int i, int len);
void	print_all_zero(char *buffer, char *str, int i, int len);
void	print_unit(char *buffer, char *str, int zamt);
void	print_all(char *buffer, char *str);
char	*unique_num(char *num);

#endif
