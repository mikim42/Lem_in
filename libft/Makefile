# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/15 01:56:50 by mikim             #+#    #+#              #
#    Updated: 2017/11/14 10:45:06 by mikim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c\
	  ft_atoi_base.c\
	  ft_bzero.c\
	  ft_intlen.c\
	  ft_itoa.c\
	  ft_itoa_base.c\
	  ft_ltoa.c\
	  ft_ltoa_base.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_printf.c\
	  ft_splitdel.c\
	  ft_strchr.c\
	  ft_strcjoin.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strextract.c\
	  ft_strjoin.c\
	  ft_strlen.c\
	  ft_strlower.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strsplit.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_strupper.c\
	  ft_uitoa.c\
	  ft_uitoa_base.c\
	  ft_ultoa.c\
	  ft_ultoa_base.c\
	  get_next_line.c\
	  init_args.c\
	  init_args_etc.c\
	  parse_args.c\
	  parse_spec.c\
	  print_base.c\
	  print_char.c\
	  print_dice.c\
	  print_digit.c\
	  print_invalid.c\
	  print_non_printable.c\
	  print_prec_a.c\
	  print_prec_e.c\
	  print_prec_f.c\
	  print_prec_g.c\
	  print_prec_tools.c\
	  print_ptraddr.c\
	  print_spec.c\
	  print_spec_etc.c\
	  print_str.c\
	  print_wchar.c\
	  print_wstr.c\
	  settings.c

OBJ = $(SRC:.c=.o)

SRCDIR = srcs
OBJDIR = objs

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
HEADER = -I includes

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
NAME = libft.a

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(OBJDIR):
	@/bin/mkdir -p $(OBJDIR)

$(OBJS): | $(OBJDIR)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@ranlib $@
	@echo "\x1B[32;1m[libft - 모래반지 빵야빵야!]\x1B[0m"

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\x1B[31m[libft - fclean]\x1B[0m"

re: fclean all
