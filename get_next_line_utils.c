/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:19:20 by macar             #+#    #+#             */
/*   Updated: 2022/01/25 14:19:20 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != 0)
		i++;
	return (i);
}

int	n_line_checker(char *s, char a)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcat(char *s1, char *s2)
{
	int		i;
	char	*temp;
	int		a;

	temp = malloc(ft_strlen(s1)+ft_strlen(s2) + 1);
	if (!temp)
		return (NULL);
	i = 0;
	a = 0;
	while (s1 && s1[i] != 0)
	{
		temp[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2 && s2[a] != 0)
	{
		temp[i] = s2[a];
		a++;
		i++;
	}
	temp[i] = 0;
	return (temp);
}
