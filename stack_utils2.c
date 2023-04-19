/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnegre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:31:51 by pnegre            #+#    #+#             */
/*   Updated: 2023/04/19 09:39:17 by pnegre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_elem	*last_stack_elem(t_stack_elem *stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (stack);
	else
		return (last_stack_elem(stack->next));
}

t_stack_elem	*before_last_stack_elem(t_stack_elem *stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (NULL);
	if (stack->next->next == NULL)
		return (stack);
	else
		return (before_last_stack_elem(stack->next));
}

void	stack_add_front(t_stack_elem **stack, t_stack_elem *new)
{
	new->next = *stack;
	*stack = new;
}

void	stack_add_back(t_stack_elem **stack, t_stack_elem *new)
{
	t_stack_elem	*p;

	if (*stack == NULL)
		*stack = new;
	else
	{
		p = last_stack_elem(*stack);
		p->next = new;
	}
}

void	free_stack(t_stack_elem **head)
{
	t_stack_elem	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		tmp = NULL;
	}
}
