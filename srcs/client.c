/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:34:31 by tseche            #+#    #+#             */
/*   Updated: 2025/12/18 15:56:34 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static volatile int	g_sync = 0;

void	handler(int signum)
{
	if (signum == SIGUSR1)
		g_sync = 1;
	else if (signum == SIGUSR2)
		g_sync = 2;
}

void	send(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_sync = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_sync)
			pause();
		if (g_sync == 2)
			return ;
		i--;
	}
}

int	check_pid(char **av)
{
	int	i;

	i = 0;
	if (av[1][0] == '+')
		i++;
	while (av[1][i] >= '0' && av[1][i] <= '9')
		i++;
	if (av[1][i] != '\0')
	{
		write(2, "The <PID> Provided is not a number\n", 36);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		err;
	int		i;

	if (ac != 3)
	{
		write(2, "USAGE: ./client <PID> <MESSAGE>\n", 33);
		return (1);
	}
	err = check_pid(av);
	if (err)
		return (1);
	pid = ft_atoi(av[1]);
	if (pid == 0 || kill(pid, 0) == -1)
	{
		write(2, "Couldn't communicate with provided <PID>\n", 42);
		return (1);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	i = 0;
	while (av[2][i])
		send(pid, av[2][i++]);
	send(pid, '\0');
	return (0);
}
