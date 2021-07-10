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

static int	apply_sign(char **str, int is_neg)
{
	char	*temp;

	if (!is_neg)
		return (0);
	temp = ft_strjoin("-", *str);
	safe_free((void **)str);
	*str = temp;
	if (*str == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}

int	apply_width_int(char **str, t_arg *arg)
{
	int		pad;
	int		is_neg;
	char	*res;
	char	*temp;
	char	*nbr;

	if (arg->flags & LEFT_JUSTIFY || arg->width < 0
		|| !(arg->flags & ZERO_PAD)
		|| (arg->flags & ZERO_PAD && arg->precision >= 0))
	{
		if (apply_width(str, arg))
			return (FT_PRINTF_ERROR);
		return (0);
	}
	is_neg = **str == '-';
	nbr = ft_substr(*str, is_neg, ft_strlen(*str));
	safe_free((void **)str);
	pad = arg->width - ft_strlen(nbr) - is_neg;
	temp = get_pad_w(pad);
	res = ft_strjoin(temp, nbr);
	safe_free((void **)&temp);
	safe_free((void **)&nbr);
	*str = res;
	return (apply_sign(str, is_neg));
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
	char	*nbr;
	char	*temp;
	uint8_t	is_neg;

	if (arg->precision < 0)
		return (0);
	is_neg = **str == '-';
	nbr = ft_substr(*str, is_neg, ft_strlen(*str));
	temp = get_pad_p(arg->precision - ft_strlen(*str) + is_neg);
	safe_free((void **)str);
	if (is_neg)
	{
		*str = ft_strjoin("-", temp);
		res = ft_strjoin(*str, nbr);
		safe_free((void **)str);
	}
	else if (arg->precision == 0 && ft_strncmp("0", nbr, ft_strlen(nbr)) == 0)
		res = ft_strdup("");
	else
		res = ft_strjoin(temp, nbr);
	safe_free((void **)&temp);
	safe_free((void **)&nbr);
	*str = res;
	return (*str == NULL);
}
