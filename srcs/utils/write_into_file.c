/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_into_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:30:36 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/10 20:31:58 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

void	write_into_file(char *str, char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	//0644 = premissions i think
	if (fd == -1)
		return ;
	ft_putstr_fd(str, fd);
}
