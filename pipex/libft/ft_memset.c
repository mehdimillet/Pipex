/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 03:09:55 by memillet          #+#    #+#             */
/*   Updated: 2025/10/14 05:25:08 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *) s;
	while (n > 0)
	{
		*(temp++) = (unsigned char) c;
		n--;
	}
	return (s);
}

// int	main(void)
// {
// 	char str[10]= "coucou";
// 	ft_memset(str, '0', 3);
// 	printf("%s\n", str);
// 	return (0);
// }