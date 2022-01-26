/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:12:53 by macar             #+#    #+#             */
/*   Updated: 2022/01/25 14:12:53 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*check_line(char *str)
{
	int		i;
	char	*new;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != 0 && str[i] != '\n')
		i++;
	new = (char *)malloc(i + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] != 0 && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new[i++] = '\n';
	new[i] = 0;
	return (new);
}

void	*ft_free(void *str)
{
	free(str);
	return (NULL);
}

char	*s_line(char *str)
{
	int		i;
	char	*other_line;
	int		a;

	a = 0;
	i = 0;
	if (!str)
		return (ft_free(str));
	while (str[i] != 0 && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (ft_strlen(str) - i == 0)
		return (ft_free(str));
	other_line = malloc(ft_strlen(str) - i + 1);
	if (other_line == NULL)
		return (NULL);
	while (str[i])
		other_line[a++] = str[i++];
	other_line[a] = 0;
	free(str);
	return (other_line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*f_line;
	static char	*reading[10240];
	int			from_read;

	from_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (n_line_checker(reading[fd], '\n') == 0 && from_read != 0)
	{
		from_read = read(fd, buf, BUFFER_SIZE);
		if (from_read <= 0)
			break ;
		buf[from_read] = 0;
		reading[fd] = ft_strcat(reading[fd], buf);
	}
	f_line = check_line(reading[fd]);
	reading[fd] = s_line(reading[fd]);
	return (f_line);
}
