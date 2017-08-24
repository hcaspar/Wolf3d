/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:55:04 by hcaspar           #+#    #+#             */
/*   Updated: 2016/08/25 15:40:57 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# define BUFF_SIZE 4096

typedef struct			s_link
{
	int					fd;
	int					eof;
	char				*text;
	char				*rest;
	struct s_link		*next;
}						t_link;

int						get_next_line(int const fd, char **line);

#endif
