/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:42:57 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/05/15 20:58:55 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int 	count_digits(long int nbr)
{
	unsigned int	counter;

	counter = 0;
	while (nbr)
	{
		nbr = nbr / 10;
		counter++;
	}
	return (counter); 
}

char	*ft_itoa(int nbr)
{
	long int n;
	char	*str;
	unsigned int	numsize;
	unsigned int	index;
	unsigned int	negative;

	n = (long int) nbr;
	negative = 0;
	if (n == 0)
		return ("0");
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	numsize = count_digits(n);
	if (negative)
		numsize++;
	index = numsize;
	str = malloc (numsize * sizeof (char) + 1);
	if (!str)
		return (NULL);
	str[index] = '\0';
	index --;
	if (negative)
		str[0] = '-';
	while (n > 0)
	{
		str[index] = (n % 10) + 48 ;
		n = n / 10;
		index--;
	}
	return (str);
}
/*
int	main(void)
{

	printf("%s\n", ft_itoa(-1342));
	printf("%s\n", ft_itoa(1342));
}
*/
