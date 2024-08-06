# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 15:56:04 by apuchill          #+#    #+#              #
#    Updated: 2024/08/06 11:51:02 by omoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libasm.a
TEST		:= test.out

DIR_SRCS	:= srcs
DIR_OBJS	:= objs
DIR_TEST	:= tests
DIR_TEST_OBJS	:= t_objs

SRCS		:= ft_write.s
OBJS		:= $(patsubst %.s, ${DIR_OBJS}/%.o, ${SRCS})

TEST_SRCS	:= use_write.c test_write.c
#$(foreach dir, $(DIR_TEST), $(wildcard $(dir)/*.c))
TEST_OBJS	:= $(patsubst %.c, ${DIR_TEST_OBJS}/%.o, ${TEST_SRCS})

INCLUDES	= -I includes

ASM			:= nasm
ASM_FLAGS	:= -f elf64

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror
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

$(DIR_TEST_OBJS)/%.o :	$(DIR_TEST)/%.c
			@echo	$(GRN_COL)"Compiling Test File "$(RST_COL) $@
			@mkdir -p $(DIR_TEST_OBJS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			@echo	$(GRN_COL)"Linking libasm ..."$(RST_COL)
			@ar -rcs $(NAME) $(OBJS)

test:	$(NAME) $(TEST_OBJS)
			@echo	$(GRN_COL)"Linking test ..."$(RST_COL)
			@$(CC) $(TEST_OBJS) $(CFLAGS) $(LFLAGS) -o test

clean:
			@echo	$(RED_COL)"Cleaning ..."$(RST_COL)
			@$(RM) $(DIR_OBJS)
			@$(RM) $(DIR_TEST_OBJS)
.PHONY:	clean

fclean: clean
			@echo	$(RED_COL)"Fully Cleaning ..."$(RST_COL)
			@$(RM) $(NAME)
			@$(RM) test
.PHONY:	fclean

re: fclean $(NAME)
.PHONY:	re