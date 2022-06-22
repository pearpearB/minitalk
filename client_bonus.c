/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:24:47 by jabae             #+#    #+#             */
/*   Updated: 2022/06/23 01:03:08 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_binary(int pid, int c)
{
	unsigned int	idx;
	unsigned char	base;

	base = 128;
	idx = 0;
	while (idx < 8)
	{
		if (c & base)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		base = base >> 1;
		idx++;
		usleep(100);
	}
}

static void	slice_str(int pid, unsigned char *str)
{
	unsigned int	idx;

	idx = 0;
	while (str[idx])
	{
		send_binary(pid, str[idx]);
		idx++;
	}
	send_binary(pid, 0);
}

static void	error_exit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	unsigned char		*input_str;
	pid_t				pid;

	if (argc != 3)
		error_exit("[Error] Parameters format is [server PID] [msg] !");
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99999)
		error_exit("[Error] Invalid PID");
	input_str = (unsigned char *)ft_strdup(argv[2]);
	slice_str(pid, input_str);
	free(input_str);
	input_str = 0;
	return (0);
}
