/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:56:34 by tseche            #+#    #+#             */
/*   Updated: 2025/12/16 17:38:08 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static char *g_mess = "";

void handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit = 0;
	
	(void)context;
	c <<= 1;
	if (signum == SIGUSR2)
		c |= 1;
	bit++;

	if (bit == 8)
	{
		g_mess = ft_strjoin(g_mess, (const char *)&c);
		if (!g_mess)
			g_mess = "";
		bit = 0;
	}
	if (c == '\0')
	{
		write(1, g_mess, ft_strlen(g_mess));
		g_mess = "";
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction sig;
	
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