/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:30:57 by raydogmu          #+#    #+#             */
/*   Updated: 2025/01/18 17:19:36 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig)
{
	static int	character = 0;
	static int	bitnum = 0;

	if (sig == SIGUSR2)
	{
		character |= 1 << bitnum;
		bitnum++;
	}
	else
		bitnum++;
	if (bitnum == 8)
	{
		bitnum = 0;
		if (character != '\0')
			write(1, &character, 1);
		else
			write(1, "\n", 1);
		character = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
