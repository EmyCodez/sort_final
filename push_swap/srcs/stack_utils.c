/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:27:27 by esimpson          #+#    #+#             */
/*   Updated: 2024/02/29 13:08:16 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

t_stack	*find_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_length(t_stack *stack)
{
	int	length;

	length = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		length++;
	}
	return (length);
}

t_stack	*find_min_node(t_stack *stack)
{
	int		min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (min > stack->nbr)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*find_max_node(t_stack *stack)
{
	int		max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (max < stack->nbr)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

int	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
