# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 15:56:04 by apuchill          #+#    #+#              #
#    Updated: 2024/08/17 19:36:05 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libasm.a
TEST		:= test.out

DIR_SRCS	:= srcs
DIR_OBJS	:= objs
DIR_BONUS_S	:= srcs_bonus
DIR_BONUS_O	:= objs_bonus
DIR_TEST	:= tests
DIR_TEST_OBJS	:= t_objs
DIR_TESTB	:= $(DIR_TEST)/_bonus
DIR_TESTB_OBJS	:= $(DIR_TEST_OBJS)/_bonus

SRCS		:= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s \
				ft_write.s ft_read.s

OBJS		:= $(patsubst %.s, ${DIR_OBJS}/%.o, ${SRCS})

BONUS_SRCS	:= ft_atoi_base_bonus.s ft_list_push_front_bonus.s \
				ft_list_remove_if_bonus.s ft_list_size_bonus.s \
				ft_list_sort_bonus.s
				
BONUS_OBJS	:= $(patsubst %.s, ${DIR_BONUS_O}/%.o, ${BONUS_SRCS})

TEST_SRCS	:= test_strlen.c test_strcpy.c test_strcmp.c test_strdup.c \
				test_write.c test_read.c print_test_header.c

TEST_MSRC	:= main_test.c

TEST_B_SRCS	:= test_isspace.c test_count_char.c test_get_index.c test_validate_base.c \
				test_trim_spaces.c test_get_sign.c test_atoui_base.c test_atoi_base.c \
				test_create_elem.c test_list_push_front.c test_list_push_node_front.c \
				test_list_size.c test_destroy_elem.c test_list_pop_front.c \
				test_list_remove_front.c test_list_remove_if.c test_list_search_pos.c \
				test_list_sort.c test_list_sort_ins.c print_list.c cmp_fncts.c \
				check_list_sort.c clear_list.c

TEST_B_MSRC	:= main_test.c

#$(foreach dir, $(DIR_TEST), $(wildcard $(dir)/*.c))
TEST_OBJS	:= $(patsubst %.c, ${DIR_TEST_OBJS}/%.o, ${TEST_SRCS})
TEST_MOBJ	:= $(patsubst %.c, ${DIR_TEST_OBJS}/%.o, ${TEST_MSRC})

TEST_B_OBJS	:= $(patsubst %.c, ${DIR_TESTB_OBJS}/%.o, ${TEST_B_SRCS})
TEST_B_MOBJ	:= $(patsubst %.c, ${DIR_TESTB_OBJS}/%.o, ${TEST_B_MSRC})

INCLUDES	= -I includes

ASM			:= nasm
ASM_FLAGS	:= -f elf64

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror -g
LFLAGS		:= -lasm -L .

RM			:= rm -rf

GRN_COL		:="\033[32m"
RED_COL		:="\033[31m"
RST_COL		:="\033[0m"

all:		$(NAME)

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.s
			@echo	$(GRN_COL)"Assembling Code File"$(RST_COL) $@
			@mkdir -p $(DIR_OBJS)
			@$(ASM) $(ASM_FLAGS) $< -o $@

$(DIR_BONUS_O)/%.o :	$(DIR_BONUS_S)/%.s
			@echo	$(GRN_COL)"Assembling Code File"$(RST_COL) $@
			@mkdir -p $(DIR_BONUS_O)
			@$(ASM) $(ASM_FLAGS) $< -o $@

$(DIR_TEST_OBJS)/%.o :	$(DIR_TEST)/%.c
			@echo	$(GRN_COL)"Compiling Test File "$(RST_COL) $@
			@mkdir -p $(DIR_TEST_OBJS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_TESTB_OBJS)/%.o :	$(DIR_TESTB)/%.c
			@echo	$(GRN_COL)"Compiling Bonus Test File "$(RST_COL) $@
			@mkdir -p $(DIR_TEST_OBJS)
			@mkdir -p $(DIR_TESTB_OBJS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS) Makefile includes/libasm.h
			@echo	$(GRN_COL)"Linking libasm ..."$(RST_COL)
			@ar -rcs $(NAME) $(OBJS)

.bonus:		$(OBJS) $(BONUS_OBJS) Makefile includes/libasm_bonus.h
			@touch	.bonus
			@echo	$(GRN_COL)"Linking libasm with bonus ..."$(RST_COL)
			@ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

test:	$(NAME) $(TEST_OBJS) $(TEST_MOBJ) \
				Makefile includes/libasm.h includes/tests.h
			@echo	$(GRN_COL)"Linking test ..."$(RST_COL)
			@$(CC)  $(TEST_MOBJ) $(TEST_OBJS) $(CFLAGS) $(LFLAGS) -o test

testbonus:	.bonus $(TEST_OBJS) $(TEST_B_OBJS) $(TEST_B_MOBJ) \
				Makefile includes/libasm.h includes/libasm_bonus.h includes/tests.h includes/tests_bonus.h
			@echo	$(GRN_COL)"Linking bonus test ..."$(RST_COL)
			@$(CC)  $(TEST_B_MOBJ) $(TEST_OBJS) $(TEST_B_OBJS) $(CFLAGS) $(LFLAGS) -o testbonus

bonus:		.bonus
.PHONY:		bonus

clean:
			@echo	$(RED_COL)"Cleaning ..."$(RST_COL)
			@$(RM) $(DIR_OBJS)
			@$(RM) $(DIR_BONUS_O)
			@$(RM) $(DIR_TEST_OBJS)
			@$(RM) $(DIR_TESTB_OBJS)
.PHONY:	clean

fclean: clean
			@echo	$(RED_COL)"Fully Cleaning ..."$(RST_COL)
			@$(RM)	$(NAME)
			@$(RM)	.bonus
			@$(RM)	test
			@$(RM)	testbonus
.PHONY:	fclean

re: fclean $(NAME)
.PHONY:	re