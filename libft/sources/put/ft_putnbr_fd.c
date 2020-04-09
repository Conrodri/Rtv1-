/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:42:55 by conrodri          #+#    #+#             */
/*   Updated: 2020/02/20 18:55:15 by conrodri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb2;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb2 = -n;
	}
	else
		nb2 = n;
	if (nb2 >= 10)
	{
		ft_putnbr_fd(nb2 / 10, fd);
		ft_putnbr_fd(nb2 % 10, fd);
	}
	else
		ft_putchar_fd(nb2 + '0', fd);
}
