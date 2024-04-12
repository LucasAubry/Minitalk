/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasaubry <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:43:03 by lucasaubry        #+#    #+#             */
/*   Updated: 2024/04/11 18:43:06 by lucasaubry       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_p(void *adresse);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putunbr(unsigned int nb);
int		ft_putstr(char *str);
void	ft_puthexa_2(unsigned int nb, char *base);
int		ft_puthexa(unsigned int nb, char *base);
int		ft_printf(const char *format, ...);
void	ft_putnbr_fd(int n, int fd);

#endif
