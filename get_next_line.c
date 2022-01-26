/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macar <macar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:21:10 by macar             #+#    #+#             */
/*   Updated: 2022/01/25 14:21:10 by macar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*reading;
	int			from_read;

	from_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (n_line_checker(reading, '\n') == 0 && from_read != 0)
	{
		from_read = read(fd, buf, BUFFER_SIZE);
		if (from_read <= 0)
			break ;
		buf[from_read] = 0;
		reading = ft_strcat(reading, buf);
	}
	f_line = check_line(reading);
	reading = s_line(reading);
	return (f_line);
}

/*    int main(void)
{
	char *p;
	int fd = open("text.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	close(fd);
	//system("leaks a.out");
	return (0);
} */