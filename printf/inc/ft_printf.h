/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:38:10 by vserrao-          #+#    #+#             */
/*   Updated: 2022/02/01 10:53:38 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

# define SPECIFIERS "cspdiuxX%"

# define HEXAUPPER "0123456789ABCDEF"

# define HEXALOWER "0123456789abcdef"

# define MIN_INT -2147483648

typedef struct s_format
{
	int		minus;
	int		plus;
	int		width;
	int		precision;
	int		neg_prec;
	char	specifier;
	int		zero;
	int		dot;
	int		space;
	int		hash;
}			t_format;

int			ft_printf(const char *str, ...);

int			ft_print_specific(t_format new, va_list args);

int			ft_eval(char *c, va_list args);

t_format	ft_init_format(void);

int			ft_putnchar(char c, int n);

int			ft_putnstr(char *s, int n);

int			ft_nbrlen(long n, int base);

int			ft_print_char(t_format new, va_list args);

int			ft_print_str(t_format new, va_list args);

int			ft_print_int(t_format new, va_list args);

int			ft_print_hexa_int(t_format new, va_list args);

int			ft_print_hexa_ptr(t_format new, va_list args);

char		*ft_uitoa(unsigned int n);
#endif
