/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:24:44 by memillet          #+#    #+#             */
/*   Updated: 2025/10/23 05:59:24 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*source;
	char	*dst;

	source = (char *)src;
	dst = (char *)dest;
	if (source == (void *)0 && dst == (void *)0)
		return (dest);
	if (source < dst)
	{
		while (n--)
			dst[n] = source[n];
	}
	else
		ft_memcpy(dst, source, n);
	return (dest);
}

// int main(void)
// {
// 	char dest[] = "Hello, World!";
// 	const char src[] = "42cursus";
// 	size_t n = 8;
// 	printf("Before memmove: %s\n", dest);
// 	ft_memmove(dest, src, n);
// 	printf("After memmove: %s\n", dest);
// 	return (0);
// }