#ifndef _LIBASM_BONUS_H
#define	_LIBASM_BONUS_H

#include <errno.h>
#include <sys/types.h>

typedef	struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

int		ft_isspace(char c);
size_t	ft_count_char(const char *str, char c);
ssize_t	ft_get_index(const char *str, char c);
int		ft_validate_base(const char *base);
char	*ft_trim_spaces(const char *str);
int		ft_get_sign(char **str);
long	ft_atoui_base(char *str, char *base);	
int		ft_atoi_base(char *str, char *base);
t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void 	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),\
							void (*free_fct)(void *));

#endif