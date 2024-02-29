/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:58:01 by esimpson          #+#    #+#             */
/*   Updated: 2024/02/29 15:46:10 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**result;
	int		numbers;
	t_stack	*stack_a;
	t_stack	*stack_b;

	numbers = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	i = 0;
	while (++i < argc)
	{
		result = ft_split(argv[i], ' ');
		numbers += valid_number(result);
		free(result);
	}
	init_stack_a(argc, argv, numbers, &stack_a);
	sort_stack(&stack_a, &stack_b, numbers);
	free_stack(&stack_a);
	return (0);
}
