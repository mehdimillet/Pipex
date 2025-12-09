/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:42:22 by memillet          #+#    #+#             */
/*   Updated: 2025/10/23 05:57:43 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && *str1 == *str2)
	{
		str1++;
		str2++;
		i++;
	}
	if (i >= n)
		return (0);
	return (((int)*str1) - ((int)*str2));
}

// int main(void)
// {
//     printf("%d\n", ft_memcmp("abc", "abd", 3));
//     return 0;
// }