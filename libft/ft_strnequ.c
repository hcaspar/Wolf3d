/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:37:02 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/14 14:09:37 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] && s2[i]) && (i != n))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	if ((s1[i] == '\0' && s2[i] == '\0') || (s1[n - 1] == s2[n - 1]))
		return (1);
	return (0);
}