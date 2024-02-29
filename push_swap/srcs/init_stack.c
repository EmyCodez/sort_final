/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:38:09 by esimpson          #+#    #+#             */
/*   Updated: 2024/02/29 15:45:07 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void	append_node(t_stack **stack, int num)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->nbr = num;
	node->next = NULL;
	node->above_median = 0;
	node->cheapest = 0;
	node->index = 0;
	node->push_cost = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(int arg_cnt, char **num_list, int num_cnt,
		t_stack **stack_a)
{
	int	*num_array;
	int	i;

	num_array = check_duplicate(arg_cnt, num_list, num_cnt);
	if (check_sorted(num_array, num_cnt))
	{
		free(num_array);
		exit(0);
	}
	i = 0;
	while (i < num_cnt)
		append_node(stack_a, num_array[i++]);
	free(num_array);
}

void	current_index(t_stack *stack)
{
	int	index;
	int	median;

	if (!stack)
		return ;
	index = 0;
	median = stack_length(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		++index;
	}
}

static void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	closest_nbr;

	while (stack_b)
	{
		closest_nbr = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->nbr > stack_b->nbr && current_a->nbr < closest_nbr)
			{
				closest_nbr = current_a->nbr;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_nbr == LONG_MAX)
			stack_b->target = find_min_node(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}

void	init_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
