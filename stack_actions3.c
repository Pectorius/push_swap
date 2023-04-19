/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnegre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:28:49 by pnegre            #+#    #+#             */
/*   Updated: 2023/04/19 09:22:24 by pnegre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	act_sb(t_stack_elem **head, int output)
{
	t_stack_elem	*p;
	t_stack_elem	*next;

	p = *head;
	if (*head && (*head)->next)
	{
		next = (*head)->next;
		(*head)->next = next->next;
		next->next = p;
		(*head) = next;
		if (output)
			ft_putstr_fd("sb\n", 1);
	}
}

static void	act_ss_output(int flag)
{
	if (flag == 1)
		ft_putstr_fd("sa\n", 1);
	if (flag == 2)
		ft_putstr_fd("sb\n", 1);
	if (flag == 3)
		ft_putstr_fd("ss\n", 1);
}

void	act_ss(t_stack_elem **head_a, t_stack_elem **head_b, int output)
{
	t_stack_elem	*p;
	t_stack_elem	*next;
	int				flag;

	flag = 0;
	p = *head_a;
	if (*head_a && (*head_a)->next)
	{
		next = (*head_a)->next;
		(*head_a)->next = next->next;
		next->next = p;
		(*head_a) = next;
		flag = 1;
	}
	p = *head_b;
	if (*head_b && (*head_b)->next)
	{
		next = (*head_b)->next;
		(*head_b)->next = next->next;
		next->next = p;
		(*head_b) = next;
		flag += 2;
	}
	if (output)
		act_ss_output(flag);
}
