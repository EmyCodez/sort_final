/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:30:10 by esimpson          #+#    #+#             */
/*   Updated: 2024/02/29 15:58:22 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	push_prep(stack_a, (*stack_b)->target, 'a');
	pa(stack_a, stack_b);
}

static void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
		rrr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	rotate_both(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
		rr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest);
	push_prep(stack_a, cheapest, 'a');
	push_prep(stack_b, cheapest->target, 'b');
	pb(stack_b, stack_a);
}

void	sort_three_plus(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_len_a;

	stack_len_a = stack_length(*stack_a);
	if (stack_len_a-- > 3 && !is_stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (stack_len_a-- > 3 && !is_stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	while (stack_len_a-- > 3 && !is_stack_sorted(*stack_a))
	{
		set_values_stack_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	if (!is_stack_sorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b)
	{
		init_stack_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_to_top(stack_a);
}
