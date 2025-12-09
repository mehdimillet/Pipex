/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:30:10 by memillet          #+#    #+#             */
/*   Updated: 2025/10/23 06:02:08 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	i;

	s = (char *)src;
	i = ft_strlen(src);
	if (i + 1 < size)
		ft_memcpy(dst, s, i + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, s, size - 1);
		dst[size - 1] = '\0';
	}
	return (i);
}

// int main(void)
// {
// 	char dest[20];
// 	const char *src = "Hello, World!";
// 	size_t size = 10;

// 	size_t result = ft_strlcpy(dest, src, size);
// 	printf("Result: %zu\n", result);
// 	printf("Destination: %s\n", dest);
// 	return (0);
// }