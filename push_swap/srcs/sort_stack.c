/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:07:20 by esimpson          #+#    #+#             */
/*   Updated: 2024/02/29 15:59:09 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->nbr = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*max_node;

	max_node = find_max_node(*stack_a);
	if (max_node == *stack_a)
		ra(stack_a);
	else if ((*stack_a)->next == max_node)
		rra(stack_a);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int stack_len)
{
	if (stack_len == 2)
		sa(stack_a);
	if (stack_len == 3)
		sort_three(stack_a);
	if (stack_len > 3)
		sort_three_plus(stack_a, stack_b);
}
