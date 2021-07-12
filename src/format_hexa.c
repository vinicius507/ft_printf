/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:40:05 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/12 14:40:05 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_hexa(t_arg *arg, va_list ap)
{
	unsigned int	nbr;
	char			*nbr_str;
	char			*temp;

	nbr = va_arg(ap, unsigned int);
	nbr_str = ft_uitoa_base(nbr, "0123456789abcdef");
	if (nbr_str == NULL)
		return (NULL);
	if (apply_precision_uint(&nbr_str, arg)
		|| apply_width_uint(&nbr_str, arg))
		return (NULL);
	arg->printed += ft_strlen(nbr_str);
	if (arg->type == HEXA_U)
	{
		temp = ft_striter(nbr_str, ft_toupper);
		safe_free((void **)&nbr_str);
		nbr_str = temp;
	}
	return (nbr_str);
}
