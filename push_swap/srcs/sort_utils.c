/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:28:46 by esimpson          #+#    #+#             */
/*   Updated: 2024/02/29 11:08:02 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	closest_index;

	while (stack_a)
	{
		closest_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->nbr < stack_a->nbr && current_b->nbr > closest_index)
			{
				closest_index = current_b->nbr;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_index == LONG_MIN)
			stack_a->target = find_max_node(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

static void	cost_analyze(t_stack *stack_a, t_stack *stack_b)
{
	int	length_a;
	int	length_b;

	length_a = stack_length(stack_a);
	length_b = stack_length(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = length_a - (stack_a->index);
		if (stack_a->target->above_median)
			stack_a->push_cost += stack_a->target->index;
		else
			stack_a->push_cost += length_b - (stack_a->target->index);
		stack_a = stack_a->next;
	}
}

void	min_to_top(t_stack **stack_a)
{
	t_stack	*min;

	min = find_min_node(*stack_a);
	while ((*stack_a)->nbr != min->nbr)
	{
		if (min->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	set_values_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analyze(stack_a, stack_b);
	set_cheapest(stack_a);
}
