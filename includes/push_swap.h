/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inwagner <inwagner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:42:15 by inwagner          #+#    #+#             */
/*   Updated: 2023/04/24 20:15:40 by inwagner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/includes/ft_printf.h"

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
int		ft_isalldigit(char *str);
void	ft_putstr_fd(char *str, int fd);
void	exit_program(int ret, char *msg, int fd);

#endif