/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:42:00 by thda-sil          #+#    #+#             */
/*   Updated: 2024/03/07 19:49:28 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_char(int pid, char c)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		usleep(600);
		i++;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

void	message_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Message received!\n");
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [PID] [message]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	if (pid < 0 || !str)
	{
		ft_printf("ERROR: Invalid arguments");
		return (1);
	}
	signal(SIGUSR1, &message_handler);
	send_message(pid, str);
	return (0);
}
