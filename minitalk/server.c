/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:41:49 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/07 18:55:16 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *siginfo, void *context)
{
	static int	i = 0;
	static char	c = 0;

	(void) context;
	if (signum == SIGUSR1)
		c |= (0 << i);
	else if (signum == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
		{
			kill(siginfo->si_pid, SIGUSR1);
			ft_printf("\n");
		}
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	if (pid < 0)
	{
		ft_printf("ERROR: Couldn't get PID\n");
		return (1);
	}
	ft_printf("%d\n", pid);
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) < 0)
			ft_printf("ERROR: Couldn't get PID\n");
		else if (sigaction(SIGUSR2, &sa, NULL) < 0)
			ft_printf("ERROR: Couldn't get PID\n");
		pause();
	}
	return (0);
}
