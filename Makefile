####################### 🛠️ ##############################

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -g3 -o2
#-fsanitize=thread
####################### 🛠️ ##############################

RM = rm -rf

####################### 🤖 ##############################

NAME = philo

######################## 📁 #############################

SRC = srcs/main.c srcs/parsing.c srcs/routines.c srcs/monitor.c srcs/utils.c\
	srcs/mutex.c srcs/time.c srcs/threads.c

SRCS = ${SRC}

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
	@echo "Compilation $< in $@"


######################## 🎶🎹 ############################

all: $(NAME) header

header:
	@echo "$(BLUE)$$HEADER$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "Compiled ✅"
	@echo "The program $(NAME) is created ✅"

clean:
	@$(RM) $(OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)
	@echo ".o files are destroyed ✅"

fclean: clean
	@$(RM) $(NAME)
	@echo "Everything is clean ✅"

re: fclean all

.PHONY: all clean fclean header re