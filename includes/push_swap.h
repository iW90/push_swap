/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:42:15 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/22 20:53:19 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/includes/ft_printf.h"

# define I_MIN -2147483648
# define I_MAX 2147483647

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i_max;
	int		a_size;
	int		b_size;
}			t_stacks;

typedef struct s_cost
{
	int		a;
	int		b;
	int		total;
}			t_cost;

long	ft_atol(const char *str);
void	ft_putstr_fd(char *str, int fd);
void	exit_program(int ret, char *msg, t_list *lst);
int		abs(int num);

t_list	*parse_list(int total, char **num, int *index);
void	parse_index(int *index, t_list *lst, int sz);

void	quick_sort(int *arr, int start, int end);
int		is_sorted(t_list *lst);
int		is_sorted_reverse(t_list *lst);
int		is_ascending(t_list *lst);
int		is_descending(t_list *lst);

t_list	*ft_newnode(int num, t_list *previous);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list *lst);
int		greater_index(t_list *lst);
int		smaller_index(t_list *lst);

void	sort_three(t_stacks *stks);
void	sort_three_reverse(t_stacks *stks);
void	sort_four(t_stacks *stks);
void	sort_five(t_stacks *stks);

void	push_swap(t_stacks *stks);

int		calculate_cost(int index, t_list *lst, int size);
void	get_cost(t_cost *cost, t_stacks *stks);

void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

//LEMBRAR DE APAGAR
void	print_full_stacks(t_stacks *s);
void	print_stacks(t_stacks *s);
void	print_list(t_list *lst);
void	printarr(int *index, int sz);

#endif