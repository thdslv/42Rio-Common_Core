/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:20:12 by thda-sil          #+#    #+#             */
/*   Updated: 2024/08/08 16:38:12 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_command	command;

	ft_bzero(&command, sizeof(t_command));
	if (argc > 1)
	{
		ft_printf("bash: %s: No such file or directory\n", argv[1]);
		return (0);
	}
	
}
