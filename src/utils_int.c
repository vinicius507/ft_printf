/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:49:41 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 10:49:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_pad_w(int size, t_arg *arg)
{
	char	*str;

	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (size--)
	{
		if (arg->flags & ZERO_PAD
			&& !(arg->flags & LEFT_JUSTIFY)
			&& !(arg->precision >= 0))
			str[size] = '0';
		else
			str[size] = ' ';
	}
	return (str);
}

int	apply_width_int(char **str, t_arg *arg)
{
	int		size;
	int		pad;
	char	*res;
	char	*temp;

	size = ft_strlen(*str);
	if (size >= arg->width)
		return (0);
	pad = arg->width - size;
	if (arg->flags & (PLUS | SPACE))
		pad -= 1;
	temp = get_pad_w(pad, arg);
	if (arg->flags & LEFT_JUSTIFY)
		res = ft_strjoin(*str, temp);
	else
		res = ft_strjoin(temp, *str);
	safe_free((void *)str);
	safe_free((void **)&temp);
	*str = res;
	if (res == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}

static char	*get_pad_p(int size)
{
	char	*str;

	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (size--)
		str[size] = '0';
	return (str);
}

int	apply_precision_int(char **str, t_arg *arg)
{
	int		size;
	char	*res;
	char	*temp;

	size = ft_strlen(*str);
	if (size >= arg->precision)
		return (0);
	temp = get_pad_p(arg->precision - size);
	res = ft_strjoin(temp, *str);
	safe_free((void **)str);
	safe_free((void **)&temp);
	*str = res;
	if (res == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}

int	apply_sign(char **str, long long int nbr, t_arg *arg)
{
	char	*res;

	if (nbr < 0 || !(arg->flags & (PLUS | SPACE)))
		return (0);
	if (arg->flags & PLUS)
		res = ft_strjoin("+", *str);
	else
		res = ft_strjoin(" ", *str);
	safe_free((void **)str);
	*str = res;
	if (res == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}
