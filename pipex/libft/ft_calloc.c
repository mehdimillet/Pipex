/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:41:55 by memillet          #+#    #+#             */
/*   Updated: 2025/10/23 05:56:16 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	int				i;

	i = 0;
	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	while (temp[i])
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

// int main(void)
// {
// 	size_t n = 5;
// 	int *a = ft_calloc(n, sizeof *a);
// 	printf("%d\n", a[0]);
// 	free(a);
// 	return 0;
// }