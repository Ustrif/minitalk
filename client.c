/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:06:52 by raydogmu          #+#    #+#             */
/*   Updated: 2025/01/18 17:26:49 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	say;

	if (str == NULL)
		return (0);
	say = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		say = (say * 10) + *str - '0';
		str++;
	}
	return (say);
}

void	send_text(int pid, char c)
{
	int	i;

	i = 0;
	while (i != 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		c >>= 1;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	pid = ft_atoi(argv[1]);
	i = 0;
	if (argc != 3 || pid == 0 || kill(pid, 0) == -1)
	{
		ft_printf("Parameter error!\n");
		exit(EXIT_FAILURE);
	}
	while (argv[2][i])
	{
		send_text(pid, argv[2][i]);
		i++;
	}
	send_text(pid, '\0');
	return (0);
}
