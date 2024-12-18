/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:44:03 by garance           #+#    #+#             */
/*   Updated: 2023/06/18 13:16:04 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

long int	ft_atoi_mode(char *str)
{
	int			i;
	long int	n;
	int			count;

	n = 0;
	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (ck_char("0-# +", str[i]) > 0)
		i++;
	if (!str[i] || str[i] < '1' || str[i] > '9')
		return (-1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i++] - 48;
		count++;
	}
	if (n > 2147483647 || count > 10)
		return (-2);
	return (n);
}
