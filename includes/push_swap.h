/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:42:15 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/14 10:47:02 by inwagner         ###   ########.fr       */
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
	unsigned int	index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_stacks
{
	struct t_list	*stackA;
	struct t_list	*stackB;
}					t_stacks;

long	ft_atol(const char *str);
int		ft_isnumber(char *str);
void	ft_putstr_fd(char *str, int fd);
void	exit_program(int ret, char *msg, t_list *lst);

t_list	*ft_newnode(int num, t_list *previous);
void	ft_lstclear(t_list *lst);

void	sa(s_stacks *stacks);
void	sb(s_stacks *stacks);
void	ss(s_stacks *stacks);
void	pa(s_stacks *stacks);
void	pb(s_stacks *stacks);
void	ra(s_stacks *stacks);
void	rb(s_stacks *stacks);
void	rr(s_stacks *stacks);
void	rra(s_stacks *stacks);
void	rrb(s_stacks *stacks);
void	rrr(s_stacks *stacks);

#endif