/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:57:35 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/12 13:57:35 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_str(t_arg *arg, va_list ap)
{
	char		*str;
	const char	*temp;

	temp = va_arg(ap, const char *);
	if (temp == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(temp);
	if (str == NULL)
		return (NULL);
	if (apply_precision_str(&str, arg)
		|| apply_width(&str, arg))
		return (NULL);
	arg->printed += ft_strlen(str);
	return (str);
}
