/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <aappleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:16:15 by aappleto          #+#    #+#             */
/*   Updated: 2023/01/08 19:45:52 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/include.h"

//anti norm struct
typedef struct s_antinorm {
	int	i;
	int	flag_2;
	int	flag_1;
}	t_antinorm;

t_antinorm	screwnorm(void)
{
	t_antinorm	fn;

	fn.i = 4;
	fn.flag_1 = 0;
	fn.flag_2 = 0;
	return (fn);
}

void	screwnorm2(t_antinorm *fn)
{
	fn->i += 3;
	fn->flag_1 = 1;
}

void	screwnorm3(t_antinorm *fn)
{
	fn->flag_2 = 0;
	ft_putchar_fd(info()->line[fn->i], 1);
}

void	echo(void)
{
	t_antinorm	fn;

	fn = screwnorm();
	if (info()->line[fn.i + 1] == '-' && info()->line[fn.i + 2] == 'n')
		screwnorm2(&fn);
	while (is_valid(info()->line[++fn.i]))
	{
		if (info()->line[fn.i] == 34 || info()->line[fn.i] == 39)
		{
			if (!fn.flag_2)
			fn.flag_2 = info()->line[fn.i];
		}
		else if (info()->line[fn.i] == 34 || info()->line[fn.i] == 39)
			if (info()->line[fn.i] == fn.flag_2)
				fn.flag_2 = -1;
		if (info()->line[fn.i] == 34 || info()->line[fn.i] == 39)
		{
			if (info()->line[fn.i] != fn.flag_2 && fn.flag_2 != -1)
				screwnorm3(&fn);
		}
		else
			ft_putchar_fd(info()->line[fn.i], 1);
	}
	if (!fn.flag_1)
		printf("\n");
}
