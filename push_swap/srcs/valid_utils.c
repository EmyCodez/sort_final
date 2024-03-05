/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:26:42 by esimpson          #+#    #+#             */
/*   Updated: 2024/02/27 16:04:33 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	free_array_exit(char **str_array, int index, int exit_code)
{
	int	i;

	i = 0;
	while (i <= index && str_array[i])
		free(str_array[i++]);
	free(str_array);
	if (exit_code)
		ft_putstr_fd("Error\n", 2);
	exit(exit_code);
}

int	valid_number(char **num_list)
{
	int	i;
	int	j;

	i = 0;
	while (num_list[i])
	{
		j = 0;
		if (num_list[i][j + 1] && (num_list[i][0] == '-'
				|| num_list[i][0] == '+') && num_list[i][j + 1] != '0')
			j++;
		while (num_list[i][j])
		{
			if (num_list[i][j] && ft_isdigit(num_list[i][j]))
				j++;
			else
				free_array_exit(&num_list[i], i, 1);
		}
		free(num_list[i++]);
	}
	return (i);
}

static int	*fill_array(int arg_cnt, char **num_list, int *num_array)
{
	int		i;
	char	**result;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (++i < arg_cnt)
	{
		result = ft_split(num_list[i], ' ');
		j = 0;
		while (result[j])
		{
			if (ft_atol(result[j]) > INT_MIN && ft_atol(result[j]) < INT_MAX)
			{
				num_array[k++] = ft_atoi(result[j]);
				free(result[j]);
			}
			else
				free_array_exit(&result[j], j, 1);
			j++;
		}
		free(result);
	}
	return (num_array);
}

int	*check_duplicate(int arg_cnt, char **num_list, int num_cnt)
{
	int	i;
	int	*num_array;
	int	j;

	num_array = (int *)malloc(sizeof(int) * num_cnt);
	if (!num_array)
		return (NULL);
	num_array = fill_array(arg_cnt, num_list, num_array);
	i = 0;
	while (i < num_cnt - 1)
	{
		j = i + 1;
		while (j < num_cnt)
		{
			if (num_array[i] == num_array[j])
			{
				ft_putstr_fd("Error\n", 2);
				free(num_array);
				exit(0);
			}
			j++;
		}
		i++;
	}
	return (num_array);
}

int	check_sorted(int *num_array, int num_cnt)
{
	int	i;
	int	j;

	i = 0;
	while (i < num_cnt - 1)
	{
		j = i + 1;
		while (j < num_cnt)
		{
			if (num_array[i] < num_array[j])
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
