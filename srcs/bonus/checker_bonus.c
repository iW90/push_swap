/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:11:11 by inwagner          #+#    #+#             */
/*   Updated: 2023/05/23 22:07:47 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	do_moves(char *move, t_stacks *stks)
{
	if (ft_strncmp(move, "sa\n", 3))
		sa(stks);
	else if (ft_strncmp(move, "sb\n", 3))
		sb(stks);
	else if (ft_strncmp(move, "ss\n", 3))
		ss(stks);
	else if (ft_strncmp(move, "ra\n", 3))
		ra(stks);
	else if (ft_strncmp(move, "rb\n", 3))
		rb(stks);
	else if (ft_strncmp(move, "rr\n", 3))
		rr(stks);
	else if (ft_strncmp(move, "rra\n", 4))
		rra(stks);
	else if (ft_strncmp(move, "rrb\n", 4))
		rrb(stks);
	else if (ft_strncmp(move, "rrr\n", 4))
		rrr(stks);
	else if (ft_strncmp(move, "pa\n", 3))
		pa(stks);
	else if (ft_strncmp(move, "pb\n", 3))
		pb(stks);
	else
		ft_putstr_fd("Error\n", 2);
}

void	checker(t_stacks *stks)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		do_moves(move, stks);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	if (is_sorted(stks->stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stacks	stks;

	if (argc == 1)
		exit_program(1, "", NULL, NULL);
	stks = (t_stacks){0};
	stks.a_size = argc - 1;
	stks.stack_a = parse_list(argc, argv);
	checker(&stks);
	exit_program(0, "", stks.stack_a, stks.stack_b);
	return (0);
}
