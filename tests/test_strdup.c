/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:15:57 by omoreno-          #+#    #+#             */
/*   Updated: 2024/08/17 20:18:04 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libasm.h>
#include <tests.h>
#include <string.h>

static const char *plain = \
	"Plain text and some special characters 你好世界! to copy";
	
static int 	test_strdup(const char *src)
{
	int		res;
	char	*ret1;
	char	*ret2;

	ret1 = NULL;
	printf(GRN_COL"\nUsing ft_strdup\n"RST_COL);
	printf("before dup:\n\treturn is %p \"%s\",\n\tsource is %p \"%s\"\n", \
		ret1, ret1, src, src);
	ret1 = ft_strdup(src);
	printf("after dup:\n\treturn is %p \"%s\",\n\tsource is %p \"%s\"\n", \
		ret1, ret1, src, src);
	ret2 = NULL;
	printf(BLU_COL"\nUsing strdup\n"RST_COL);
	printf("before dup:\n\treturn is %p \"%s\",\n\tsource is %p \"%s\"\n", \
		ret2, ret2, src, src);
	ret2 = strdup(src);
	printf("after dup:\n\treturn is %p \"%s\",\n\tsource is %p \"%s\"\n", \
		ret2, ret2, src, src);
	res = strcmp(ret1, ret2);
	if (ret1)
		free(ret1);
	if (ret2)
		free(ret2);
	print_test_result(res);
	return (res);
}

int 	test_strdup_act(void)
{
	int	ret;

	print_test_header("ft_strdup");
	ret = test_strdup(plain);
	ret += test_strdup("");
	return (ret);
}
