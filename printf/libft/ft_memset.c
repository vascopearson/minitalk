/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:05:23 by vserrao-          #+#    #+#             */
/*   Updated: 2021/10/29 18:11:33 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
int	main(void)
{
	char str[50] = "Put a few dots in the middle of this sentence";
    printf("Before memset(): %s\n", str);

    ft_memset(str + 13, '.', 8*sizeof(char));

    printf("After memset():  %s\n", str);
    return 0;
}
*/
