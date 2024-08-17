/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:35:36 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/17 19:50:58 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libasm.h>
#include <libasm_bonus.h>
#include <tests.h>
#include <tests_bonus.h>

void clear_list(t_list **l, void (*free_fct)(void *))
{
	printf(GRN_COL"Clear list"RST_COL"\n");
	ft_list_remove_if(l, NULL, ft_always_equal, free_fct);
	print_list(*l);
}	
