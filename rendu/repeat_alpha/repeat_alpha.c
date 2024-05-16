/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:09:36 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/05/15 17:35:01 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{	
	int	i;
	int	j;

	i = 0;
	if (argc != 2)
		return(write(1, "\n", 1), 0);
	while (argv[1][i])
	{
		j = 0;
		write(1, &argv[1][i], 1);	
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		       while (j < argv[1][i] - 0x41)
		       {
			       write(1, &argv[1][i], 1);
			       j++;
		       }	       
		else
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			while(j < argv[1][i] - 0x61)
			{
				write(1, &argv[1][i], 1);
				j++;	
			}
		i++;
	}
	write(1, "\n", 1);
}
