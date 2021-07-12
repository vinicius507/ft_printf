/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:00:25 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/12 17:00:25 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_ptr(t_arg *arg, va_list ap)
{
	unsigned long int	ptr;
	char				*ptr_str;
	char				*temp;

	ptr = (unsigned long int)va_arg(ap, void *);
	temp = NULL;
	if (ptr != 0)
	{
		temp = ft_ultoa_base(ptr, "0123456789abcdef");
		ptr_str = ft_strjoin("0x", temp);
	}
	else
		ptr_str = ft_strdup(NULL_STR);
	safe_free((void **)&temp);
	if (ptr_str == NULL)
		return (NULL);
	arg->printed += ft_strlen(ptr_str);
	return (ptr_str);
}
