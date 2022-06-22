/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:25:00 by jabae             #+#    #+#             */
/*   Updated: 2022/06/23 01:02:57 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	ft_itoa_binary(char *set)
{
	int	i;
	int	chr;

	i = 0;
	while (set[i])
	{
		if (set[i] == '1')
			chr = chr * 2 + 1;
		else if (set[i] == '0')
			chr = chr * 2;
		i++;
	}
	return (chr);
}

static void	print_char(char *arr, int *idx)
{
	char	set;
	int		i;

	set = ft_itoa_binary(arr);
	if (set == 0)
	{
		write(1, "\n", 1);
		i = 0;
		while (arr[i])
		{
			arr[i] = 0;
			i++;
		}
	}
	ft_putchar_fd(set, 1);
	*idx = 0;
}

static void	change_binary(int signo)
{
	static char	arr[8];
	static int	idx = 0;

	if (signo == 30)
		arr[idx] = '1';
	else if (signo == 31)
		arr[idx] = '0';
	idx++;
	if (idx == 8)
		print_char(arr, &idx);
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	ft_putstr_fd("Server PID: ", 1);
	ft_putendl_fd(pid, 1);
	signal(SIGUSR1, change_binary);
	signal(SIGUSR2, change_binary);
	while (1)
		pause();
	free(pid);
	pid = 0;
	return (0);
}
