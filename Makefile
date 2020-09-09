# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/09 11:54:28 by floblanc          #+#    #+#              #
#    Updated: 2020/09/09 12:19:35 by floblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL				=	/bin/zsh

# Executable name
NAME				=	openssl

# Compilation mode
WALL				=	yes
WEXTRA				=	yes
WERROR				=	yes
FSANITIZE			=	no
DEBUG				=	no
O2					=	no

CC					:=	gcc
GEN					:=	"Generation in mode"

ifeq ($(WALL), yes)
	CC				:=	$(CC) -Wall
	GEN				:=	$(GEN) all
endif

ifeq ($(WEXTRA), yes)
	CC				:=	$(CC) -Wextra
	GEN				:=	$(GEN) extra
endif

ifeq ($(WERROR), yes)
	CC				:=	$(CC) -Werror
	GEN				:=	$(GEN) error
endif

ifeq ($(FSANITIZE), yes)
	CC				:=	$(CC) -fsanitize=address
	GEN				:=	$(GEN) sanitize
endif

ifeq ($(DEBUG), yes)
	CC				:=	$(CC) -g
	GEN				:=	$(GEN) debug
endif

ifeq ($(O2),yes)
	CC				:=	$(CC) -O2
	GEN				:=	$(GEN) O2
endif

ifeq ($(GEN), "Generation in mode")
	GEN				:=	$(GEN) no flags
endif

# Text format
_DEF				=	$'\033[0m
_END				=	$'\033[0m
_GRAS				=	$'\033[1m
_SOUL				=	$'\033[4m
_CLIG				=	$'\033[5m
_SURL				=	$'\033[7m

# Colors
_BLACK				=	$'\033[30m
_RED				=	$'\033[31m
_GREEN				=	$'\033[32m
_YELLOW				=	$'\033[33m
_BLUE				=	$'\033[34m
_PURPLE				=	$'\033[35m
_CYAN				=	$'\033[36m
_GREY				=	$'\033[37m

# Background
_IBLACK				=	$'\033[40m
_IRED				=	$'\033[41m
_IGREEN				=	$'\033[42m
_IYELLOW			=	$'\033[43m
_IBLUE				=	$'\033[44m
_IPURPLE			=	$'\033[45m
_ICYAN				=	$'\033[46m
_IGREY				=	$'\033[47m

SRC_NAME =			main.c

SRC_PATH =			./src/

OBJ_PATH =			./obj/

INC_PATH =			./include/

INC_NAME =			ft_ssl_md5.h


LIBFT				=	./libftprintf/
LIBFT_NAME			=	libftprintf.a
LIBFTINCLUDES		=	./libftprintf/include/

INC	= $(addprefix $(INC_PATH), $(INC_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

.PHONY :	all clean fclean re

all: $(NAME)

$(LIBFT)/$(LIBFT_NAME):
	@make -C $(LIBFT) -j
	@echo "$(_GREEN)[ LIBFT DONE ]$(_END)"

$(NAME) : $(LIBFT)/$(LIBFT_NAME) $(OBJ)
		@mkdir -p $(OBJ_PATH)
		@echo "\n$(_WHITE)====================================================$(_END)"
		@echo "$(_YELLOW)		COMPILING $(NAME)$(_END)"
		@echo "$(_WHITE)====================================================$(_END)"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)/$(LIBFT_NAME)
		@echo "\n$(_WHITE)$(_BOLD)$@\t$(_END)$(_GREEN)[OK]\n$(_END)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCLUDE)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)md5/
	@$(CC) -I $(INC_PATH) -I $(LIBFTINCLUDES)/libft.h -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)\t"	\
		"COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"

clean:
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(OBJ_PATH)"$(_END)"
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(NAME)
	@rm -f $(LIBFT)$(LIBFT_NAME)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LIBFT)$(LIBFT_NAME)"$(_END)"

re : fclean all