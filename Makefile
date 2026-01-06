# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseche <tseche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 23:39:11 by tseche            #+#    #+#              #
#    Updated: 2025/12/16 19:09:30 by tseche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Colors ---
RED    := \033[0;31m
GREEN  := \033[0;32m
YELLOW := \033[0;33m
BLUE   := \033[0;34m
PURPLE := \033[0;35m
CYAN   := \033[0;36m
NC     := \033[0m # No Color

NAME_SERVER = server
NAME_CLIENT = client
CFLAGS = -Wall -Werror -Wextra -g 
CC	= cc
 
LIBNAME = libft.a
LIBDIR = lib_ft
LIB = $(LIBDIR)/$(LIBNAME)


LIBMAKE := $(MAKE) --no-print-directory -C $(LIBDIR)

all: libs $(NAME_SERVER) $(NAME_CLIENT)

LIBFT:
	@make -C ./lib_ft --no-print-directory
	
$(NAME_CLIENT):
	@echo "$(BLUE)🔗 Creating Executable client $@...$(NC)"
	@$(CC) $(CFLAGS) srcs/client.c -L$(LIBDIR) -l:$(LIBNAME) -o $(NAME_CLIENT)
	@echo "$(GREEN)✅ Created $@$(NC)"

$(NAME_SERVER):
	@echo "$(BLUE)🔗 Creating Executable server $@...$(NC)"
	@$(CC) $(CFLAGS) srcs/server.c -L$(LIBDIR) -l:$(LIBNAME) -o $(NAME_SERVER)
	@echo "$(GREEN)✅ Created $@$(NC)"

libs:
	@echo "$(BLUE)📦 Building library in $(LIBDIR)...$(NC)"
	@$(LIBMAKE)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean: libclean
	@echo "$(RED)🧹 Cleaning...$(NC)"
	@rm -rf ./srcs/client.o ./srcs/server.o $(OBJS_SERVER)

libclean:
	@echo "$(RED)🧹 Cleaning lib in $(LIBDIR)...$(NC)"
	@$(LIBMAKE) clean


fclean: clean
	@echo "$(RED)🗑️ Removing Executable and library ...$(NC)"
	@rm -rf $(NAME_CLIENT) $(NAME_SERVER) $(LIB)

re: fclean all

credit:
	@echo "SO a pchazalm"

help:
	@echo "$(PURPLE)=== Makefile Help ===$(NC)"
	@echo "$(PURPLE)all:$(NC) Build the library"
	@echo "$(PURPLE)clean:$(NC) Remove object files"
	@echo "$(PURPLE)fclean:$(NC) Remove object files and library"
	@echo "$(PURPLE)re:$(NC) Rebuild the library from scratch"
	@echo "$(PURPLE)help:$(NC) Show this help message"
	@echo "$(PURPLE)credit:$(NC) Show the people who help with this project"
	

.PHONY: all LIBFT libs clean libclean fclean re credit help