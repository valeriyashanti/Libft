/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:01:50 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/22 17:05:55 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl(char const *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, s + i, 1);
			i++;
		}
		write(1, "\n", 1);
	}
}
