/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:32:06 by esimpson          #+#    #+#             */
/*   Updated: 2024/02/29 15:59:51 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				above_median;
	int				cheapest;
	int				push_cost;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int					valid_number(char **num_list);
int					*check_duplicate(int arg_cnt, char **num_list, int num_cnt);
void				free_array_exit(char **str_array, int index, int exit_code);
void				init_stack_a(int arg_cnt, char **num_list, int num_cnt,
						t_stack **stack_a);
int					check_sorted(int *num_array, int num_cnt);
void				free_stack(t_stack **stack);
void				sort_stack(t_stack **stack_a, t_stack **stack_b,
						int stack_len);

/* Stack Utils */
t_stack				*find_last_node(t_stack *stack);
t_stack				*find_min_node(t_stack *stack);
t_stack				*find_max_node(t_stack *stack);
int					stack_length(t_stack *stack);
int					is_stack_sorted(t_stack *stack);

void				current_index(t_stack *stack);
void				init_stack_b(t_stack *stack_a, t_stack *stack_b);
void				min_to_top(t_stack **stack_a);
void				set_values_stack_a(t_stack *stack_a, t_stack *stack_b);

t_stack				*get_cheapest(t_stack *stack);
void				set_cheapest(t_stack *stack);

/* Commands for sorting */
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				ra(t_stack **a);
void				rb(t_stack **a);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

void				push_prep(t_stack **stack, t_stack *top, char stack_name);
void				sort_three(t_stack **stack_a);
void				sort_three_plus(t_stack **stack_a, t_stack **stack_b);
#endif
