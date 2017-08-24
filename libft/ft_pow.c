/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 16:08:20 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/18 16:26:59 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_pow(double a, int b)
{
	double	c;
	int		i;
	int		sign;

	i = 1;
	sign = 1;
	c = a;
	if (b == 0)
		return (1);
	if (b < 0)
	{
		sign = -1;
		b = -b;
	}
	while (i < b)
	{
		a = a * c;
		i++;
	}
	if (sign == -1)
		a = 1 / a;
	return (a);
}
