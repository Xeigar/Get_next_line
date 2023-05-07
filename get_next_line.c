/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:10:09 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/07 20:01:20 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_txt(int fd, char *txt)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(sizeof(*temp) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	i = 1;
	while (!find(txt) && i != 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[i] = 0;
		//printf("temp ->%s end\n", temp);
		txt = strjoiner(txt, temp);
		//printf("txt ->%s end\n", txt);
	}
	free(temp);
	return (txt);
}

char	*get_next_line(int fd)
{
	static char	*txt;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	txt = get_txt(fd, txt);
	if (!txt)
		return (NULL);
	line = extraction(txt);
	txt = removal(txt, line);
	return (line);
}
