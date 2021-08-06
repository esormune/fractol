# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/03 11:48:55 by esormune          #+#    #+#              #
#    Updated: 2021/03/27 18:13:22 by esormune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDES = -I includes/ -I printf/includes/
FLAGS = -c -Wall -Wextra -Werror -g
SRCS = $(IS_SRC) $(LIST_SRC) $(MATH_SRC) $(MEM_SRC) $(PUT_SRC) $(OTHER_SRC) \
	$(STR_SRC) $(PRINTF_SRC)
LIBFT_SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstadd.c \
	ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	ft_is_whitespace.c ft_min.c ft_max.c ft_isupper.c ft_islower.c \
	ft_lstlast.c ft_lstsize.c ft_lstpush.c ft_calloc.c ft_realloc.c \
	get_next_line.c ft_print_hex.c ft_itoa_base.c ft_print_bits.c \
	ft_numlength.c ft_numlength_neg.c ft_itoa_llong_base.c \
	ft_itoa_ulong_base.c ft_itoa_size_t_base.c ft_itoa_intmax_base.c \
	ft_itoa_uintmax_base.c ft_tolower_str.c ft_toupper_str.c ft_pow.c \
	ft_flitoa.c ft_itoa_exp.c ft_flitoa_ldouble.c ft_neg_pow_ten.c \
	ft_brounding.c ft_print_array.c ft_putnstr.c ft_strndup.c \
	ft_implode.c ft_free_array.c ft_is_neg.c ft_putnstr_fd.c \
	ft_brounding_ld.c ft_atoi_max.c ft_uintmax_pow.c \
	ft_strjoin_free.c ft_abs.c ft_rand.c ft_colour.c ft_avg.c \
	ft_c_add.c ft_c_multiply.c ft_c_sq.c ft_c_divide.c

IS_SRC = $(addprefix is/, ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_is_neg.c ft_is_whitespace.c \
	ft_isupper.c)

LIST_SRC = $(addprefix list/, ft_lstadd.c ft_lstdel.c \
	ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	ft_lstlast.c ft_lstpush.c)

MATH_SRC = $(addprefix math/, ft_abs.c ft_atoi.c ft_atoi_max.c \
	ft_avg.c ft_brounding.c ft_brounding_ld.c ft_flitoa.c \
	ft_flitoa_ldouble.c ft_itoa_base.c ft_itoa_exp.c ft_itoa_intmax_base.c \
	ft_itoa_llong_base.c ft_itoa_size_t_base.c ft_itoa_uintmax_base.c \
	ft_itoa_ulong_base.c ft_itoa.c ft_max.c ft_min.c ft_neg_pow_ten.c \
	ft_numlength.c ft_numlength_neg.c ft_pow.c ft_uintmax_pow.c \
	ft_c_add.c ft_c_multiply.c ft_c_sq.c ft_c_divide.c)

MEM_SRC = $(addprefix mem/, ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_free_array.c \
	ft_memalloc.c ft_memdel.c ft_realloc.c ft_calloc.c)

OTHER_SRC = $(addprefix other/, ft_colour.c ft_rand.c \
	get_next_line.c)

PUT_SRC = $(addprefix put/, ft_putchar.c ft_putstr.c ft_putendl.c \
	ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_print_array.c ft_print_bits.c ft_print_hex.c \
	ft_putnstr.c)

STR_SRC = $(addprefix str/, ft_strlen.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strjoin_free.c \
	ft_implode.c ft_tolower.c ft_tolower_str.c ft_toupper.c \
	ft_toupper_str.c ft_strndup.c)

PRINTF_SRC = $(addprefix printf/, ft_parser.c ft_printf.c ft_split.c \
	ft_convert.c ft_specs.c ft_next.c ft_sprintf.c ft_dprintf.c \
	ft_conflicts.c ft_char.c ft_string.c ft_octal.c ft_hex.c \
	ft_int.c ft_exp.c ft_u_int.c ft_pointer.c ft_binary.c ft_float.c \
	ft_percent.c ft_null_string.c ft_init.c ft_rev_split.c \
	ft_width.c ft_nb.c)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $(NAME)
	@echo "$(NAME) created."

%.o: %.c
	@gcc $(FLAGS) $^ -o $@ $(INCLUDES)
	
$(LIBFT_SRCS): includes/libft.h

$(PRINTF_SRC): printf/includes/ft_printf.h

clean:
	@rm -rf $(OBJ)
	@echo "Files .o deleted."

fclean: clean
	@rm -rf $(NAME)
	@echo "Binary $(NAME) deleted."

re: fclean all

.PHONY: all clean fclean re
