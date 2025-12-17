/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:56:34 by tseche            #+#    #+#             */
/*   Updated: 2025/12/17 16:41:59 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit = 0;
	static char				*mess = "";
	char					*tmp;

	(void)context;
	c <<= 1;
	if (signum == SIGUSR2)
		c |= 1;
	bit++;
	if (bit == 8)
	{
		tmp = mess;
		mess = ft_strjoin(tmp, (const char *)&c);
		if (!mess)
			mess = "";
		bit = 0;
	}
	if (c == '\0')
	{
		write(1, mess, ft_strlen(mess));
		mess = "";
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
