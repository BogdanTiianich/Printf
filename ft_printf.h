/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbecki <hbecki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:43:57 by hbecki            #+#    #+#             */
/*   Updated: 2021/11/21 17:38:19 by hbecki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	pr_perc(void);
int		ft_putnbr_fd_big_x(unsigned long int n, int i, int fd, int counter);
int		hex_big_x(unsigned long int n, int fd);
int		ft_putnbr_fd_helper(int n, int i, int fd, int counter);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_fd_hel_u(unsigned int n, int i, int fd, int counter);
int		ft_putnbr_fd_un(unsigned int n, int fd);
int		condition_set_1(va_list argptr, const char *init, int i);
int		condition_set_2(va_list argptr, const char *init, int i);
int		ft_putnbr_fd_hex_l(unsigned long int n, int i, int fd, int counter);
int		hex_x_l(unsigned long int n, int fd);
int		ft_putnbr_fd_hex(unsigned int n, int i, int fd, int counter);
int		hex_x(unsigned int n, int fd);
int		ft_printf(const char *init, ...);
#endif
