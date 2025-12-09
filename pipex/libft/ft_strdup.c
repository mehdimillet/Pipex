/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:52:38 by memillet          #+#    #+#             */
/*   Updated: 2025/10/18 02:38:30 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	const char	*dest;

	dest = malloc (ft_strlen(s) * sizeof (const char) + 1);
	if (dest == NULL)
		return (NULL);
	ft_strcpy ((char *)dest, (char *)s);
	return ((char *)dest);
}

// int	main(void)
// {
// 	char *test;
// 	test = ft_strdup("coucou");
// 	printf("%s\n",test);
// 	return (0);
// }