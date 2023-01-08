/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:06:45 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 18:48:55 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

t_token	*token(void)
{
	static t_token	token;

	return (&token);
}

t_info	*info(void)
{
	static t_info	info;

	return (&info);
}
