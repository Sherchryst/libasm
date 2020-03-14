# DIRECTORIES
BUILD	= .build
DEP_DIR = $(BUILD)/dep
OBJ_DIR = $(BUILD)/obj
DIRS	:= $(OBJ_DIR) $(DEP_DIR)

# FILES
NAME	= libasm.a
EXEC	= exec.out
ASM		= ft_strlen.s ft_strcpy.s
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
	@echo "\n\033[01mThe library archive of \033[00m"
	@echo "\033[31m	██▓     ██▓ ▄▄▄▄    ▄▄▄        ██████  ███▄ ▄███▓\033[05m"
	@echo "\033[31m	▓██▒    ▓██▒▓█████▄ ▒████▄    ▒██    ▒ ▓██▒▀█▀ ██▒\033[05m"
	@echo "\033[31m	▒██░    ▒██▒▒██▒ ▄██▒██  ▀█▄  ░ ▓██▄   ▓██    ▓██░\033[05m"
	@echo "\033[31m	▒██░    ░██░▒██░█▀  ░██▄▄▄▄██   ▒   ██▒▒██    ▒██ \033[05m"
	@echo "\033[31m	░██████▒░██░░▓█  ▀█▓ ▓█   ▓██▒▒██████▒▒▒██▒   ░██▒\033[05m"
	@echo "\033[31m	░ ▒░▓  ░░▓  ░▒▓███▀▒ ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░░ ▒░   ░  ░\033[05m"
	@echo "\033[31m	░ ░ ▒  ░ ▒ ░▒░▒   ░   ▒   ▒▒ ░░ ░▒  ░ ░░  ░      ░\033[05m"
	@echo "\033[31m	  ░ ░    ▒ ░ ░    ░   ░   ▒   ░  ░  ░  ░      ░   \033[05m"
	@echo "\033[31m	    ░  ░ ░   ░            ░  ░      ░         ░   \033[05m"
	@echo "\033[32m						\033[03mHas been created!\n\033[00m"

all: $(NAME)

clean:
	@rm -rf $(BUILD)
	@echo "\033[1;34mExecute:\t\033[1;33mCleaning build\t\033[0;31m[OK]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;34mExecute:\t\033[1;33mCleaning lib\t\033[0;31m[OK]\033[0m"
	@rm -f $(EXEC)
re: fclean all

test:
	@$(CC) $(CFLAGS) $(NAME) main.c -o $(EXEC)
	@./$(EXEC)

$(BUILD):
	@echo "\033[1;31m\nCreation of .build\033[0m \n"
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o: src/%.s | $(BUILD)
	@echo "\033[1;34mExecute: \t\033[1;33mCompilation of \033[1;36m$(notdir $<)\033[0m"
	@$(NA) $(NAFLAGS) -s $< -o $@
	@$(NA) $(DFLAGS) -o $@ -s $<

-include $(DEP)

.PHONY: all clean fclean re
