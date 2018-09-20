# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmatshiy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 12:31:20 by cmatshiy          #+#    #+#              #
#    Updated: 2018/09/13 14:52:02 by cmatshiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap
NAME2	= checker

SRC1	=	push_swap.c \
			push.c \
			rotate.c \
			rrotate.c \
			swap.c \
			test_push.c \
			test_rotate.c \
			test_rrotate.c \
			test_swap.c \
			helper.c \
			stack_list.c \
			just_sort.c \
			sort_stack.c \
			slowly_sort.c \
			testers.c \
			sort_stack1.c \
			combined_sort.c \
			helper1.c \
			combined_hp.c

SRC2	=	checker.c \
			push.c \
			rotate.c \
			rrotate.c \
			swap.c \
			stack_list.c \
			sort_stack.c \
			helper.c \
			helper1.c

ifdef ALLOCWRAP
	LDFLAGS += $(HOME)/lib/alloc_wrap.c -ldl
endif

OBJ1		= $(addprefix $(OBJDIR),$(SRC1:.c=.o))
OBJ2		= $(addprefix $(OBJDIR),$(SRC2:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3 -funroll-loops -march=native

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft
LIBLINK	= -L./libft -lft

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj libft $(NAME1) $(NAME2)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME2): $(OBJ2)
	$(CC) $(LDFLAGS) -o $(NAME2) $(OBJ2) $(LIBLINK)

$(NAME1): $(OBJ1)
	$(CC) $(LDFLAGS) -o $(NAME1) $(OBJ1) $(LIBLINK)


clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	make -C ./libft fclean
re: fclean all
