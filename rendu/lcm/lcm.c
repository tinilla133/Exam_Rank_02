/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:53:26 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/05/16 15:34:41 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	divisor;
	unsigned int	found;

	found = 0;
	divisor = 1;
	if ((int) a < 0 || (int) b < 0)
		return (0);
	if (!(a % b))
		return (a);
	if (!(b % a))
		return (b);
	if ((a % b) || (b % a))
		return (a * b);
	while (divisor <= a && divisor <= b && \
		!(a % divisor) && !(b % divisor) && ! found)
	{
		found = 1;
		divisor++;
	}
	return ((a * b) / divisor);
}
/*
int	main(void)
{
	printf("%u\n", lcm( 10,  70));
}
*/

