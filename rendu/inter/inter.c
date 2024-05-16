/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:41:42 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/05/15 18:52:03 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(const char *str)
{	
	int 	counter;

	counter = 0;

	while (str[counter])
		counter++;
	return (counter);
}

void	ft_init_str(char *str, int len)
{
	while (*str && len--)
	{
		*str = '\0';
		str++;
	}
	str = '\0';
}

unsigned int	ft_find_char(const char *str, char c)
{	
	unsigned int	found;

	found = 0;
	while (*str)
	{
		if (*str == c)
			found = 1;
		str++;	
	}
	return (found);
}

int	main(int argc, char **argv)
{
	size_t	max_len;
	char	*auxstr;
	int 	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	if (argc != 3)
		return (write(1, "\n", 1), 0);
	if (ft_strlen(argv[1]) < ft_strlen(argv[2]))
		max_len = ft_strlen(argv[2]);
	else
		max_len = ft_strlen(argv[1]);
	auxstr = malloc (max_len * sizeof (char) + 1);
	if (!auxstr)
       		return (1);
	ft_init_str(auxstr, (int) max_len);
	while (argv[1][i])
	{
		if (!ft_find_char(auxstr, argv[1][i]))
		{
			j = 0;
			while (argv[2][j] && (argv[1][i] != argv[2][j]))
				j++;
			if (argv[2][j])
				auxstr[k++] = argv[2][j];
		}
		i++;
	}
	write(1, auxstr, ft_strlen(auxstr));
	free (auxstr);
	write(1, "\n", 1);
}
