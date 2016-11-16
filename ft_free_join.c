/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:19:37 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/14 15:56:51 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char const *s1, char const *s2, char c)
{
	if (c == 'L')
		free((char*)s1);
	if (c == 'R')
		free((char*)s2);
	if (c == 'B')
	{
		free((char*)s1);
		free((char*)s2);
	}
}

char		*ft_free_join(char const *s1, char const *s2, char c)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	if (!(new = (char*)malloc(sizeof(*new) * (ft_strlen(s1)
						+ ft_strlen(s2) + 1))))
		return (0);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	ft_free(s1, s2, c);
	return (new);
}
