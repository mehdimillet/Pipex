/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:07:36 by memillet          #+#    #+#             */
/*   Updated: 2025/10/23 05:59:14 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s == (void *)0 && d == (void *)0)
		return (dest);
	while (i < n)
	{
		*d = *s;
		d++;
		s++;
		i++;
	}
	return (dest);
}

// int main(void)
// {
// 	char dest[] = "Hello, World!";
// 	const char src[] = "42cursus";
// 	size_t n = 8;
// 	printf("Before memcpy: %s\n", dest);
// 	ft_memcpy(dest, src, n);
// 	printf("After memcpy: %s\n", dest);
// 	return (0);
// }
