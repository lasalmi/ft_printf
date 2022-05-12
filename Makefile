SOURCE_FILES = ft_printf.c \
ft_printf_read_specifiers.c \
ft_pf_stages.c \
ft_pf_handle_char.c \
ft_pf_conv_handler.c \
ft_pf_conv_char.c \
ft_pf_pad_with.c \
ft_pf_read_conversion.c \
ft_pf_print.c \
ft_pf_conv_str.c \
ft_pf_handle_str.c \
ft_pf_convert_base.c \
ft_pf_handle_ptr.c \
ft_pf_oux_handler.c \
ft_conv_oux.c \
ft_pf_get_uint_len.c \
ft_pf_get_int_len.c \
ft_pf_read_length.c \
ft_pf_check_zeropadding.c \
ft_pf_conv_di.c \
ft_pf_handle_di.c \
ft_pf_skip_leading_zeroes.c \
ft_pf_handle_f.c \
ft_pf_conv_f2.c \
ft_pf_round_f_str.c \
ft_pf_get_double_len.c \
ft_need_to_roundup.c
LIB_FILES = ft_strdup.c \
ft_strlen.c \
ft_isdigit.c \
ft_strlcpy.c \
ft_toupper.c \
ft_strnequ.c \
ft_strncmp.c \
ft_uintlen.c
SOURCE_DIR = ./
LIB_DIR = ./libft/
SOURCES := $(addprefix $(SOURCE_DIR),$(SOURCE_FILES))
LIBSOURCES := $(addprefix $(LIB_DIR),$(LIB_FILES))
OBJECTS := $(SOURCES:.c=.o)
LIBOBJECTS := $(LIB_FILES:.c=.o)
LIB_NAME = libft.a
#OBJECTS += ft_strdup.o ft_strlen.o ft_isdigit.o
NAME = libftprintf.a

CFLAGS := -I $(SOURCE_DIR) -I libft
CFLAGS += -Wall -Wextra -Werror -pedantic

CC = gcc

all : $(NAME)

re : fclean all

$(NAME) : $(OBJECTS) libft
	ar rcs $(NAME) $(OBJECTS) $(LIBOBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -g -c $(SOURCES)

libft : $(LIB_NAME)
	ar -xv $(LIB_DIR)$(LIB_NAME) $(LIBOBJECTS)

$(LIB_NAME) :
	make -C libft/

TEST : $(NAME) main.c
	gcc -g -Ilibft -I. -L. main.c -lftprintf
	./a.out

clean : 
	rm -f $(OBJECTS) $(LIBOBJECTS)
	make clean -C libft/

fclean : clean
	rm -f $(NAME)
	make fclean -C libft/