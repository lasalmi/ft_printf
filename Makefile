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
ft_strdup.c \
ft_strlen.c \
ft_isdigit.c \
ft_strlcpy.c \
ft_pf_ouxX_handler.c \
ft_conv_ouxX.c \
ft_pf_get_uint_len.c \
ft_pf_get_int_len.c \
ft_toupper.c \
ft_strnequ.c \
ft_strncmp.c \
ft_pf_read_length.c \
ft_pf_check_zeropadding.c \
ft_pf_conv_di.c \
ft_pf_handle_di.c \
ft_pf_skip_leading_zeroes.c
SOURCE_DIR = ./
SOURCES := $(addprefix $(SOURCE_DIR),$(SOURCE_FILES))
OBJECTS := $(SOURCES:.c=.o)
#OBJECTS += ft_strdup.o ft_strlen.o ft_isdigit.o
NAME = libftprintf.a

CFLAGS := -I $(SOURCE_DIR) -I libft
CFLAGS += -Wall -Wextra -Werror -pedantic

CC = gcc

all : $(NAME)

re : fclean all

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -g -c $(SOURCES)

TEST : $(NAME) main.c
	gcc -g -Ilibft -I. -L. main.c -lftprintf
	./a.out

clean : 
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)