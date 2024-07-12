/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:40:39 by thda-sil          #+#    #+#             */
/*   Updated: 2024/07/12 18:40:41 by thda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	./philo 5 800 200 200 [5]
*/
int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		parse_input(&table, argv);//TODO
		data_init(&table);//TODO
		dinner_start(&table);//TODO
		clean(&table);//TODO
	}
	else
	{
		error_exit("Wrong input\n"
		GREEN"Correct form: ./philo 5 800 200 200 [5]"RESET);
	}
}