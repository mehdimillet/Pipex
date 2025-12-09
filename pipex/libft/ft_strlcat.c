/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:33:27 by memillet          #+#    #+#             */
/*   Updated: 2025/10/23 06:01:59 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_d;
	size_t	len_s;

	i = ft_strlen(dst);
	j = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (size < 1)
		return (len_s + size);
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (size < len_d)
		return (len_s + size);
	else
		return (len_d + len_s);
}

// int main(void)
// {
// 	char dest[20] = "Hello, ";
// 	const char *src = "World!";
// 	size_t size = 15;

// 	size_t result = ft_strlcat(dest, src, size);
// 	printf("Result: %zu\n", result);
// 	printf("Destination: %s\n", dest);
// 	return (0);
// }