/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:35:53 by esimpson          #+#    #+#             */
/*   Updated: 2023/07/19 09:18:49 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int num, int fd)
{
	int		nb1;
	char	temp;

	if (num < 0)
	{
		write(fd, "-", 1);
		if (num == -2147483648)
			write(fd, "2147483648", 10);
		num = -num;
	}
	if (num > 9)
	{
		nb1 = num;
		ft_putnbr_fd(nb1 / 10, fd);
		temp = nb1 % 10 + '0';
		write(fd, &temp, 1);
	}
	if (num >= 0 && num < 10)
	{
		temp = num + '0';
		write(fd, &temp, 1);
	}
}

// int	main(void)
// {
// 	ft_putnbr_fd(-57, 1);
// 	return (0);
// }
