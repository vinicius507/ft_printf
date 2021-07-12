/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:49:41 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/07/09 10:49:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_pad_w(int size)
{
	char	*pad;

	if (size <= 0)
		return (ft_strdup(""));
	pad = ft_calloc(size + 1, sizeof(char));
	if (pad == NULL)
		return (NULL);
	while (size--)
		pad[size] = '0';
	return (pad);
}

static int	should_default(t_arg *arg)
{
	if (arg->flags & LEFT_JUSTIFY || arg->width < 0
		|| !(arg->flags & ZERO_PAD)
		|| (arg->flags & ZERO_PAD && arg->precision >= 0))
		return (1);
	return (0);
}

int	apply_width_int(char **str, t_arg *arg)
{
	int		is_neg;
	char	*res;
	char	*temp;

	if (should_default(arg))
	{
		if (apply_width(str, arg))
			return (FT_PRINTF_ERROR);
		return (0);
	}
	is_neg = **str == '-';
	temp = get_pad_w(arg->width - ft_strlen(*str));
	res = ft_strjoin(temp, *str + is_neg);
	safe_free((void **)&temp);
	safe_free((void **)str);
	if (is_neg)
	{
		temp = ft_strjoin("-", res);
		safe_free((void **)&res);
		res = temp;
	}
	*str = res;
	if (*str == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}

static char	*get_pad_p(int size)
{
	char	*str;

	if (size <= 0)
		return (ft_strdup(""));
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (size--)
		str[size] = '0';
	return (str);
}

int	apply_precision_int(char **str, t_arg *arg)
{
	char	*res;
	char	*temp;
	uint8_t	is_neg;

	if (arg->precision < 0)
		return (0);
	is_neg = **str == '-';
	temp = get_pad_p(arg->precision - ft_strlen(*str) + is_neg);
	if (arg->precision == 0 && ft_strncmp(*str, "0", ft_strlen(*str)) == 0)
		res = ft_strdup("");
	else
		res = ft_strjoin(temp, (*str) + is_neg);
	safe_free((void **)&temp);
	safe_free((void **)str);
	if (is_neg)
	{
		temp = ft_strjoin("-", res);
		safe_free((void **)&res);
		res = temp;
	}
	*str = res;
	if (*str == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}
