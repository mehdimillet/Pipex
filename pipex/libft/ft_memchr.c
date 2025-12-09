/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:42:15 by memillet          #+#    #+#             */
/*   Updated: 2025/10/23 05:57:14 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*string;
	size_t				i;

	string = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (string[i] == (unsigned char)c)
			return ((void *) string + i);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     const char *s = "hello";
//     const void *p = ft_memchr(s, 'e', 5);
//     putchar(*(const unsigned char *)p);
//     return 0;
// }