/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 22:00:12 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/08 22:00:12 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_int(t_arg *arg, va_list ap)
{
	int				nbr;
	char			*nbr_str;

	nbr = va_arg(ap, int);
	nbr_str = ft_itoa(nbr);
	if (nbr_str == NULL)
		return (NULL);
	arg->printed += ft_strlen(nbr_str);
	return (nbr_str);
}
