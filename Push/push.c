/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:49:49 by mnienow           #+#    #+#             */
/*   Updated: 2019/10/30 23:26:48 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int         multi_pivot(t_lst *list, int pivot)
{
    t_lst   *link;
    int     index;

    link = list;
    while (link)
    {
        if (link->val == pivot)
            index = link->index;
        link = link->next;
    }
    return get_value(list, index / 2);
}

void        push_b(t_lst **a, t_lst **b, int len, int pivot)
{
    int     mpivot;

    mpivot = multi_pivot(*a, pivot);
    while (len)
    {
        if ((*a)->val < pivot)
        {
            if ((*a)->next->val < pivot && (*a)->next->val < (*a)->val)
                swap(a, 'a', b);
            push(a, 'b', b);
            if ((*b)->next)
                if ((*b)->val < mpivot)
                    rotate(b, 'b', a);
            len--;
        }
        else if ((*a)->next->val < pivot)
            swap(a, 'a', b);
        else {
            rev_rotate(a, 'a', b);
        }
    }
}

//void        repush(t_lst **a, t_lst **b, int len)
//{
//    int     i;
//
//    i = 0;
//    while (i < len / 2)
//    {
//        i++;
//    }
//}

void        push_swap(t_lst **a, t_lst **b, int len)
{
	int     pivot;

	if (len > 3)
	{
		pivot = get_median(*a, len);
		if (len == 4)
		    push_b(a, b, 1, pivot);
		else if (len > 62)
		{
            push_b(a, b, len / 2, pivot);
//            repush(a, b, len / 2);
        }
		else
            push_b(a, b, len / 2, pivot);
		push_swap(a, b, lstlen(*a));
	}
	else
        sort_a(a, b);
}

