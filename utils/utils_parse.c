/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danalmei <danalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:32:46 by danalmei          #+#    #+#             */
/*   Updated: 2023/10/25 13:18:03 by danalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	args_check(char **args, int i)
{
	long	tmp;
	int		err;

	err = 0;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			err = 1;
		if (ft_contains(tmp, args, i))
			err = 1;
		if (tmp < -2147483648 || tmp > 2147483647)
			err = 1;
		i++;
	}
	return (err);
}

int	ft_check_args(int argc, char **argv)
{
	int		i;
	char	**args;
	int		err;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	err = args_check(args, i);
	if (argc == 2)
		ft_free(args);
	return (err);
}
