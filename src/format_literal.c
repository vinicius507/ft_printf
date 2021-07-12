/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_literal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 18:00:19 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/12 18:00:19 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_literal(t_arg *arg)
{
	char		*str;

	str = ft_strdup("%");
	if (str == NULL)
		return (NULL);
	arg->printed += 1;
	return (str);
}
