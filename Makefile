# Colors
_END		=	\033[00m
_RED		=	\033[31m
_GREEN		=	\033[1;32m

# DIRECTORIES
BUILD	= .build
DEP_DIR = $(BUILD)/dep
OBJ_DIR = $(BUILD)/obj
DIRS	:= $(OBJ_DIR) $(DEP_DIR)

# FILES
NAME	= libasm.a
EXEC	= exec.out
ASM		= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_write.s ft_read.s
SRC		= $(ASM)
OBJ		:= $(SRC:%.s=$(OBJ_DIR)/%.o)
DEP		:= $(SRC:%.s=$(DEP_DIR)/%.d)

# COMPILATION
NA		= nasm
CC		= gcc
NAFLAGS	= -f macho64
CFLAGS	= -Wall -Wextra -Werror -Ofast -fno-builtin
DFLAGS = -M -MP -MD $(DEP_DIR)/$*.d -MT '$@'

$(NAME): $(OBJ)
	@ar -rcs $@ $^
	@echo "\n\033[01mThe library archive of $(_END)"
	@echo "$(_RED)	██▓     ██▓ ▄▄▄▄    ▄▄▄        ██████  ███▄ ▄███▓$(_END)"
	@echo "$(_RED)	▓██▒    ▓██▒▓█████▄ ▒████▄    ▒██    ▒ ▓██▒▀█▀ ██▒$(_END)"
	@echo "$(_RED)	▒██░    ▒██▒▒██▒ ▄██▒██  ▀█▄  ░ ▓██▄   ▓██    ▓██░$(_END)"
	@echo "$(_RED)	▒██░    ░██░▒██░█▀  ░██▄▄▄▄██   ▒   ██▒▒██    ▒██ $(_END)"
	@echo "$(_RED)	░██████▒░██░░▓█  ▀█▓ ▓█   ▓██▒▒██████▒▒▒██▒   ░██▒$(_END)"
	@echo "$(_RED)	░ ▒░▓  ░░▓  ░▒▓███▀▒ ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░░ ▒░   ░  ░$(_END)"
	@echo "$(_RED)	░ ░ ▒  ░ ▒ ░▒░▒   ░   ▒   ▒▒ ░░ ░▒  ░ ░░  ░      ░$(_END)"
	@echo "$(_RED)	  ░ ░    ▒ ░ ░    ░   ░   ▒   ░  ░  ░  ░      ░   $(_END)"
	@echo "$(_RED)	    ░  ░ ░   ░            ░  ░      ░         ░   $(_END)"
	@echo "$(_GREEN)						\033[03mHas been created!\n$(_END)"

all: $(NAME)

clean:
	@rm -rf $(BUILD)
	@echo "\033[1;34mExecute:\t\033[1;33mCleaning build\t\033[31m[OK]$(_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;34mExecute:\t\033[1;33mCleaning lib\t\033[31m[OK]$(_END)"
	@rm -f $(EXEC)
re: fclean all

test:
	@$(CC) $(CFLAGS) $(NAME) main.c -o $(EXEC)
	@./$(EXEC)

$(BUILD):
	@echo "\033[1;31m\nCreation of .build\033[0m \n"
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o: src/%.s | $(BUILD)
	@echo "\033[1;34mExecute: \t\033[1;33mCompilation of \033[1;36m$(notdir $<)$(_END)"
	@$(NA) $(NAFLAGS) -s $< -o $@
	@$(NA) $(DFLAGS) -o $@ -s $<

-include $(DEP)

.PHONY: all clean fclean re
