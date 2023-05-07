/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoutinh <tmoutinh@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:29:45 by tmoutinh          #+#    #+#             */
/*   Updated: 2023/05/07 19:59:14 by tmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	sizing(const char *txt)
{
	int	i;

	if (!txt)
		return (0);
	i = 0;
	while (txt[i])
		i++;
	return (i);
}

char	*strjoiner(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*p;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	p = (char *)malloc(sizeof(*p) * (sizing(s1) + sizing(s2) + 1));
	if (!p)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i] && s1)
	{
		p[i] = s1[i];
	}
	while (s2[++j] && s2)
	{
		p[i + j] = s2[j];
	}
	p[i + j] = 0;
	free(s1);
	return (p);
}

char	*find(const char *txt)
{
	int	i;

	i = 0;
	if (!txt)
		return (NULL);
	while (txt[i])
	{
		if (txt[i] == '\n')
			return ("found");
		i++;
	}
	return (NULL);
}

char	*extraction(char *txt)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (txt[i] && txt[i] != '\n')
		i++;
	if (txt[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(*line) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = txt[j];
		j++;
	}
	line[i] = 0;
	return (line);
}

char	*removal(char *txt, char *line)
{
	char	*text;
	int		i;

	i = 0;
	while (*txt == *line && *txt)
	{
		txt++;
		line++;
	}
	while (txt[i] && txt[i] != '\n')
		i++;
	if (txt[i] == '\n')
		i++;
	text = (char *)malloc(sizeof(*text) * (i + 1));
	if (!text)
		return (NULL);
	text[i] = 0;
	while (i != 0)
	{
		i--;
		text[i] = txt[i];
	}
	return (text);
}
