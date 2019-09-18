/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:22:40 by ppepperm          #+#    #+#             */
/*   Updated: 2019/09/18 17:48:41 by ppepperm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char    *read_to_arr(int ds)
{
    static char     *des[10240];
    char buff[BUFF_SIZE + 1];
    char *point;
    int r;

    r = 1;
    point = NULL;
    ft_bzero(buff, BUFF_SIZE);
    while (!(point = ft_strchr(buff, '\n')) && r)
    {
        r = read(ds, buff, BUFF_SIZE);
        if (!des[ds])
            des[ds] = ft_strdup(buff);
        else
        {
            point = des[ds];
            des[ds] = ft_strjoin(des[ds],buff);
            free(point);
        }
        if (!r)
            return (point);
    }
    return (point)
}

char    *build_line(int ds)
{
    char *tmp1;
    char *tmp2;
    size_t len;

    tmp1 = read_to_arr(ds);
    tmp2 = des[ds];
    len = 0;
    while (tmp1 != tmp2)
    {
        tmp2++;
        len++;
    }
    tmp1 = ft_strnew(len);
    ft_strncpy()


    
}
/*
static char		read_to_node(int fd, t_list **tmp)
{
	char a;
	char buff[BUFF_SIZE];
	size_t count;
	char *p;

	p = buff;
	ft_bzero((void*)p, BUFF_SIZE);
	count = 0;
	a = -1;
	while (a != '\n' && count < BUFF_SIZE && a != 0)
	{
		count += read(fd, &a, 1);
		if (!count)
			return (-1);
		buff[count - 1] = a;
	}
	if(!(*tmp = ft_lstnew((const void*)p, count - 1)))
		return (-1);
	return (a);
}
static size_t	get_len(const t_list *src)
{
	size_t tmp;

	tmp = 0;
	while (src)
	{
		tmp += src->content_size;
		src = src->next;
	}
	return (tmp);
}

static char		*listoa(const t_list *src)
{
	size_t	size;
	char	*tmp;	

	size = get_len(src);
	if (!(tmp = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
	ft_bzero(tmp, size);
	while (src)
	{
		ft_strncat(tmp, (char*)(src->content), src->content_size);
		src = src->next;
	}
	tmp[size] = 0;
	return (tmp);
}

int	get_next_line(const int fd, char **line)
{
	t_list *head_node;
	t_list *node;
	char a;

	a = -1;
	node = NULL;
	head_node = NULL;
	if (fd < 0)
		return (-1);
	while (a != '\n' && a)
	{
		if ((a = read_to_node(fd, &node)) == -1)
			return (-1);
		ft_lstpushback(&head_node, node);
	}
	*line = listoa(head_node);
	if (line && a == '\n')
		return (1);
	else if (line && a == 0)
		return (0);
	return (-1);
}
*/