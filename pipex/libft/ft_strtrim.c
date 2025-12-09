/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:56:18 by memillet          #+#    #+#             */
/*   Updated: 2025/10/23 06:03:36 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_start(char const *s1, char const *set)
{
	size_t	start;
	size_t	i;
	int		flag;

	start = 0;
	while (s1[start] != '\0')
	{
		flag = 0;
		i = 0;
		while (set[i])
		{
			if (s1[start] == set[i])
			{
				flag = 1;
				break ;
			}
			i++;
		}
		if (flag == 1)
			start++;
		else
			break ;
	}
	return (start);
}

static size_t	ft_find_end(char const *s1, char const *set, size_t start)
{
	size_t	end;
	size_t	i;
	int		flag;

	end = ft_strlen(s1) - 1;
	while (end > start)
	{
		flag = 0;
		i = 0;
		while (set[i] != '\0')
		{
			if (s1[end] == set[i])
			{
				flag = 1;
				break ;
			}
			i++;
		}
		if (flag == 1)
			end--;
		else
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*dest;

	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set, start);
	if (!s1 || !set)
		return (NULL);
	if ((end - start + 1) < 1)
	{
		dest = malloc(1);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc ((end - start + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (start <= end)
		dest[i++] = s1[start++];
	dest[i] = '\0';
	return (dest);
}

// int main(void)
// {
// 	char *s = ft_strtrim("  Hello, World!  ", " ");
// 	printf("'%s'\n", s); // Output: 'Hello, World!'
// 	free(s);
// 	return 0;
// }