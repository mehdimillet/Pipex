/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 00:27:55 by memillet          #+#    #+#             */
/*   Updated: 2025/10/23 05:56:07 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbchar(int n)
{
	int	nb;

	nb = 0;
	if (n <= 0)
		nb = 1;
	while (n != 0)
	{
		n = n / 10;
		nb++;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	len = ft_nbchar(n);
	nb = n;
	str = malloc ((len + 1) * sizeof (char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb > 0)
	{
		len--;
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

// int main(void)
// {
//     char *s = ft_itoa(-42);
//     puts(s);
//     free(s);
//     return 0;
// }