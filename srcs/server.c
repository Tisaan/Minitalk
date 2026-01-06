/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:56:34 by tseche            #+#    #+#             */
/*   Updated: 2026/01/06 14:23:53 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*func(char *str, unsigned char c, pid_t *cur_pid)
{
	char	*tmp;
	char	char_to_str[2];

	if (!str)
	{
		tmp = calloc(sizeof(char), 2);
		if (!tmp)
			return (NULL);
		tmp[0] = c;
		return (tmp);
	}
	if (c == '\0')
	{
		write(1, str, ft_strlen(str));
		free(str);
		*cur_pid = 0;
		return (NULL);
	}
	char_to_str[0] = c;
	char_to_str[1] = '\0';
	tmp = ft_strjoin(str, char_to_str);
	free(str);
	if (!tmp)
		return (NULL);
	return (tmp);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit = 0;
	static char				*mess = NULL;
	static pid_t			cur_pid = 0;

	(void)context;
	if (cur_pid == 0)
		cur_pid = info->si_pid;
	if (info->si_pid != cur_pid)
		return ;
	c <<= 1;
	if (signum == SIGUSR2)
		c |= 1;
	if (++bit == 8)
	{
		mess = func(mess, c, &cur_pid);
		c = 0;
		bit = 0;
		if (!mess)
		{
			kill(info->si_pid, SIGUSR2);
			return ;
		}
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
