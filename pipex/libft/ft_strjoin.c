/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:01:31 by memillet          #+#    #+#             */
/*   Updated: 2025/10/17 21:50:17 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = (ft_strlen(s1) + ft_strlen (s2));
	dest = ft_calloc (sizeof (char), size + 1);
	if (!dest)
		return (NULL);
	while (*(s1 + i))
	{
		*(dest + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j))
	{
		*(dest + j + i) = *(s2 + j);
		j++;
	}
	*(dest + i + j) = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char	*dest;
// 	dest = ft_strjoin("coucou", " bebe");
// 	printf ("%s\n",dest);
// 	return (0);
// }