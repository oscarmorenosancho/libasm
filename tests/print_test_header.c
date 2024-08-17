/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:38:15 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/17 19:38:17 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <tests.h>

void	print_test_header(const char *title)
{
	printf(GRN_COL"\n============================\n"RST_COL);
	printf(GRN_COL"TEST %s\n"RST_COL, title);
	printf(GRN_COL"============================\n"RST_COL);	
}

void	print_test_result(int res)
{
	if (res == 0) printf(GRN_COL"\nTEST APROVED\n"RST_COL);
	else printf(RED_COL"\nTEST FAILED\n"RST_COL);
	printf(BLK_COL"============================\n\n"RST_COL);
}
