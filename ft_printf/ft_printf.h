/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:37:28 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/06 11:54:16 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(va_list list);
int		ft_printstr(va_list list);
int		ft_putstr_int(char *s);
int		ft_printint(va_list list);
int		ft_printunsint(va_list list);
int		ft_printhexa(va_list list, char c);
int		ft_printptr(va_list list);
char	*ft_unsitoa(unsigned int n);
char	*ft_itoa(int n);

#endif
