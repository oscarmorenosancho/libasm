/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:37:36 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/17 19:37:38 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TESTS_H
#define	_TESTS_H

#define BLK_COL "\033[30m"
#define RED_COL "\033[31m"
#define GRN_COL "\033[32m"
#define ORG_COL "\033[33m"
#define BLU_COL "\033[34m"
#define MAG_COL "\033[35m"
#define CYN_COL "\033[36m"
#define RST_COL	"\033[0m"

#include <errno.h>
#include <sys/types.h>

void	print_test_header(const char *title);
void	print_test_result(int res);

int		test_strlen_act(void);
int 	test_strcpy_act(void);
int		test_strcmp_act(void);
int 	test_strdup_act(void);
int		test_write_act(void);
int		test_read_act(void);

#endif