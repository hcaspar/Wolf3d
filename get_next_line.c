/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:48:45 by hcaspar           #+#    #+#             */
/*   Updated: 2016/08/25 15:24:20 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static int			ft_join(char buf[BUFF_SIZE + 1], t_link *tmp)
{
	char			*new;
	char			*ptr;

	if (tmp->text == NULL)
		tmp->text = ft_strdup(buf);
	else
	{
		new = tmp->text;
		tmp->text = ft_strjoin(new, buf);
		if (new)
			free(new);
	}
	if ((new = ft_strchr(tmp->text, '\n')))
	{
		new[0] = '\0';
		ptr = tmp->text;
		tmp->text = ft_strdup(tmp->text);
		if (new[1] != '\0')
			tmp->rest = ft_strdup(&(new[1]));
		if (ptr)
			free(ptr);
		return (1);
	}
	return (0);
}

static int			buf_read(t_link *tmp)
{
	long long		ret;
	char			buf[BUFF_SIZE + 1];

	ret = 1;
	while (ret)
	{
		ret = read(tmp->fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (ret == 0 && tmp->text == NULL)
		{
			tmp->eof = 1;
			break ;
		}
		if (ft_join(buf, tmp))
			break ;
	}
	return (0);
}

static t_link		*init_list(int const fd, t_link **begin_list)
{
	t_link			*tmp;

	tmp = *begin_list;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp)
		return (tmp);
	tmp = (t_link*)malloc(sizeof(t_link));
	tmp->fd = fd;
	tmp->text = NULL;
	tmp->rest = NULL;
	tmp->eof = 0;
	tmp->next = *begin_list;
	*begin_list = tmp;
	return (tmp);
}

int					get_next_line(int const fd, char **line)
{
	static t_link	*begin_list = NULL;
	t_link			*tmp;

	if (begin_list == NULL)
	{
		begin_list = (t_link*)malloc(sizeof(t_link));
		begin_list->text = NULL;
		begin_list->rest = NULL;
		begin_list->next = NULL;
		begin_list->fd = fd;
		begin_list->eof = 0;
	}
	tmp = init_list(fd, &begin_list);
	tmp->text = tmp->rest;
	tmp->rest = NULL;
	if (BUFF_SIZE <= 0 || buf_read(tmp) == -1)
		return (-1);
	*line = tmp->text;
	if (tmp->eof == 1 && tmp->rest == NULL && tmp->text == NULL)
		return (0);
	return (1);
}
