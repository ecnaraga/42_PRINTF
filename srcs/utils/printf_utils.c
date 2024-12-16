/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:39:09 by garance           #+#    #+#             */
/*   Updated: 2023/06/18 09:24:07 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ck_char(char *s, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (s)
	{
		while (s[++i])
		{
			if (s[i] == c)
				count++;
		}
	}
	return (count);
}

int	ck_sset(char *s, char *set)
{
	int	i;
	int	j;

	i = -1;
	while (s && s[++i])
	{
		j = -1;
		while (set[++j])
		{
			if (s[i] == set[j])
				return (j);
		}
	}
	return (-1);
}

void	digit_len(unsigned int *n, int *j, unsigned int base)
{
	while (*n >= base)
	{
		*j += 1;
		*n = *n / base;
	}
}
