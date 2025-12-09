/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:37:21 by memillet          #+#    #+#             */
/*   Updated: 2025/10/23 06:01:47 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// int main(void)
// {
// 	char str[] = "Hello, World!";
// 	void	to_upper(unsigned int i, char *c)
// 	{
// 		if (c[i] >= 'a' && c[i] <= 'z')
// 			c[i] = c[i] - 32;
// 	}
// 	ft_striteri(str, to_upper);
// 	printf("%s\n", str); // Output: "HELLO, WORLD!"
// 	return (0);
// }