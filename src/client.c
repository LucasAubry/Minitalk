/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Laubry <aubrylucas.pro@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:36:02 by Laubry            #+#    #+#             */
/*   Updated: 2024/04/12 14:00:25 by lucasaubry       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	len_of_bits(char **argv, int pid)
{
	int	i;
	int	bit;

	bit = 0;
	i = ft_strlen(argv[2]);
	while (bit < 32)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(500);
	}
}

void	send_bit(int pid, char x)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((x & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		pause();
		usleep(500);
	}
}

void	recup(int signal)
{
	(void)signal;
}

int	main(int argc, char **argv)
{
	int								pid;
	int								i;
	static const struct sigaction	act = (struct sigaction)
	{.sa_handler = recup};

	pid = 0;
	i = 0;
	sigaction(SIGUSR1, &act, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			return (1);
		len_of_bits(argv, pid);
		while (argv[2][i])
		{
			send_bit(pid, argv[2][i]);
			i++;
		}
	}
	else
		ft_printf("les arguments sont pas bon");
	return (0);
}
