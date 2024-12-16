/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:52:13 by galambey          #+#    #+#             */
/*   Updated: 2023/06/17 21:01:31 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../LIBFT/includes/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

typedef struct a_list
{
	void		*content;
	int			len;
	char		*flag;
	long int	nb;
	long int	prec;
}				t_aglist;

typedef int		(*t_print)(t_aglist *ag);

int				ft_printf(const char *s, ...);
int				ft_arg(va_list ap, char *s, int *count);
int				ft_make_arg(t_aglist *ag, char *s, int *i);
int				ft_free_arg(t_aglist *ag, int result);
long int		ft_atoi_mode(char *s);
int				ck_front_flag(t_aglist *ag, unsigned int j, int id);
int				ck_back_flag(t_aglist *ag, int j);
int				print_char(t_aglist *ag);
int				ft_print_char(void *c);
int				print_str(t_aglist *ag);
int				print_ptr(t_aglist *ag);
int				print_int(t_aglist *ag);
int				print_unsignedint(t_aglist *ag);
int				print_lowhexa(t_aglist *ag);
int				print_upphexa(t_aglist *ag);

#endif