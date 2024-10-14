####################### 🛠️ ##############################

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

####################### 🛠️ ##############################

RM = rm -rf

####################### 🤖 ##############################

NAME = philosophers

######################## 📁 #############################

LIBFT = libft.a
LIBFT_DIR = libft

LIBC = libc/ft_isalpha.c libc/ft_isdigit.c libc/ft_isalnum.c libc/ft_isascii.c libc/ft_isprint.c libc/ft_strlen.c\
	libc/ft_memset.c libc/ft_bzero.c libc/ft_memcpy.c libc/ft_memmove.c libc/ft_strlcat.c libc/ft_strlcpy.c\
	libc/ft_strchr.c libc/ft_strrchr.c libc/ft_strncmp.c libc/ft_memchr.c libc/ft_strnstr.c libc/ft_toupper.c\
	libc/ft_memcmp.c libc/ft_tolower.c libc/ft_atoi.c libc/ft_calloc.c libc/ft_strdup.c\
	libc/ft_substr.c libc/ft_strjoin.c libc/ft_strtrim.c libc/ft_itoa.c libc/ft_strmapi.c libc/ft_striteri.c\
	libc/ft_putchar_fd.c libc/ft_putstr_fd.c libc/ft_putendl_fd.c libc/ft_putnbr_fd.c libc/ft_split.c\
	libc/ft_lstnew_bonus.c libc/ft_lstadd_front_bonus.c libc/ft_lstsize_bonus.c libc/ft_lstlast_bonus.c\
	libc/ft_lstadd_back_bonus.c libc/ft_lstdelone_bonus.c libc/ft_lstclear_bonus.c libc/ft_isspace.c\
	libc/ft_lstiter_bonus.c libc/ft_lstmap_bonus.c libc/ft_atol.c libc/ft_signe.c libc/ft_isdigitsigne.c\
	libc/ft_strtok.c libc/ft_strcat.c libc/ft_strcmp.c

LIBFT_OBJS = $(LIBC:.c=.o)

######################## 📁 #############################

PRINTF = libftprintf.a
PRINTF_DIR = printf

PRINTF_SRC =  printf/ft_converse_base.c printf/ft_hexa_base.c printf/size_hexa.c\
	printf/ft_hexa_lower.c  printf/ft_putchar.c printf/ft_putnbr.c printf/ft_printf.c\
	printf/ft_print_usigned.c printf/ft_putstr.c printf/ft_swap.c

PRINTF_OBJS = $(PRINTF_SRC:.c=.o)

######################## 📁 #############################

SRC = srcs/main.c

SRCS = ${SRC} ${LIBC} ${PRINTF_SRC} ${GNL_SRC}

OBJS = $(SRCS:.c=.o)

######################## 🧠 #############################

INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(PRINTF_DIR)

######################## 🎨 #############################

BLUE	=	\033[0;34m
GREEN	=	\033[0;32m
RED		=	\033[31m
RESET	=	\033[0m
YELLOW	=	\033[0;33m

define HEADER

██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗
██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝
██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗
██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║
██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║
╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝

endef
export HEADER

######################## 🗃️ #############################

%.o: %.c
	@$(CC) $(CFLAGS)  $(INCLUDES) $(INC) -c $< -o $@

######################## 🎶🎹 ############################

all: $(LIBFT) $(PRINTF) $(NAME) header

$(LIBFT): $(LIBFT_OBJS)
		@ar rcs $(LIBFT) $(LIBFT_OBJS)

$(PRINTF): $(PRINTF_OBJS)
		@ar rcs $(PRINTF) $(PRINTF_OBJS)

header:
	@echo "$(BLUE)$$HEADER$(RESET)"

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	@$(RM) $(OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)

fclean: clean
	@$(RM) $(LIBFT) $(PRINTF) $(NAME)

re: fclean all

.PHONY: all clean fclean header re