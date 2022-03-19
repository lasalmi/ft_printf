SOURCE_FILES = ft_printf.c \
ft_printf_read_specifiers.c \
ft_printf_percent.c \
ft_pf_stages.c
SOURCE_DIR = ./
SOURCES := $(addprefix $(SOURCE_DIR),$(SOURCE_FILES))
OBJECTS := $(SOURCES:.c=.o)
NAME = libftprintf.a

CFLAGS := -I $(SOURCE_DIR) -I libft
#CFLAGS += -Wall -Wextra -Werror -pedantic

CC = gcc

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -g -Ilibft -c $(SOURCES)

TEST : $(NAME) main.c
	make -C libft
	gcc -g -Ilibft -I. -L. -Llibft main.c -lftprintf -lft
	./a.out

clean : 
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)