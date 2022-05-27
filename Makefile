SOURCE_FILES = ft_printf.c \
ft_pf_read_specifiers.c \
ft_pf_stages.c \
ft_pf_handle_char.c \
ft_pf_conv_char.c \
ft_pf_pad_with.c \
ft_pf_read_conversion.c \
ft_pf_print.c \
ft_pf_conv_str.c \
ft_pf_handle_str.c \
ft_pf_convert_hexa.c \
ft_pf_handle_ptr.c \
ft_pf_handle_oux.c \
ft_pf_conv_oux.c \
ft_pf_get_uint_len.c \
ft_pf_get_int_len.c \
ft_pf_read_length.c \
ft_pf_check_zeropadding.c \
ft_pf_conv_di.c \
ft_pf_handle_di.c \
ft_pf_skip_leading_zeroes.c \
ft_pf_handle_f.c \
ft_pf_conv_f.c \
ft_pf_round_f_str.c \
ft_pf_get_double_len.c \
ft_pf_need_to_roundup.c \
ft_pf_initializers.c \
ft_pf_mallocfail.c \
ft_dprintf.c \
ft_sprintf.c \
ft_snprintf.c \
ft_pf_writers.c
LIB_FILES = ft_strdup.c \
ft_strlen.c \
ft_isdigit.c \
ft_strlcpy.c \
ft_toupper.c \
ft_strnequ.c \
ft_strncmp.c \
ft_uintlen.c \
ft_memcpy.c
SOURCE_DIR = ./
LIB_DIR = ./libft/
SOURCES := $(addprefix $(SOURCE_DIR),$(SOURCE_FILES))
LIBSOURCES := $(addprefix $(LIB_DIR),$(LIB_FILES))
OBJECTS := $(SOURCES:.c=.o)
LIBOBJECTS := $(LIB_FILES:.c=.o)
LIB_NAME = libft.a
NAME = libftprintf.a

CFLAGS := -I $(SOURCE_DIR) -I libft
CFLAGS += -Wall -Wextra -Werror -pedantic

CC = gcc

all : $(NAME)

re : fclean all

$(NAME) : $(OBJECTS) $(LIBOBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(LIBOBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -Wall -Wextra -Werror -c $(SOURCES)

$(LIBOBJECTS) : $(LIB_DIR)$(LIB_NAME)
	ar -xv $(LIB_DIR)$(LIB_NAME) $(LIBOBJECTS)

$(LIB_DIR)$(LIB_NAME) : $(LIBSOURCES)
	make -C libft/

TEST : $(NAME) main.c
	gcc -Wall -Wextra -Werror -g -Ilibft -I. -L. main.c -lftprintf
	./a.out

clean : 
	rm -f $(OBJECTS) $(LIBOBJECTS)
	make clean -C libft/

fclean : clean
	rm -f $(NAME)
	make fclean -C libft/