/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:29:05 by vserrao-          #+#    #+#             */
/*   Updated: 2021/10/29 18:12:12 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}
/*
int	main(void)
{
	char str[50] = "Put a few zeros in the middle of this sentence";
    printf("Before ft_bzero(): %s\n", str);

    ft_bzero(str + 13, 8*sizeof(char));

    printf("After ft_bzero():  %s\n", str+21);
    return 0;
}
*/
