/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <jpedro-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:50:59 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/11/13 11:52:58 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printx(char type, unsigned long n, int base);
int	ft_prints(char *str);
int	ft_printf(const char *type, ...);
int	ft_printc(int c);
int	ft_printd(int n);
int	ft_printu(unsigned int n);
int	ft_printp(unsigned long pointer);

#endif 
