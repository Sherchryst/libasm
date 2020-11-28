# Colors
_END		= \033[00m
_RED		= \033[31m
_GREEN		= \033[1;32m
_BLUE		= \033[1;33m
_ITL		= \033[03m


# DIRECTORIES
BUILD	= .build
OBJ_DIR = $(BUILD)/obj
DIRS	:= $(OBJ_DIR)

# FILES
NAME	= libasm.a
ASM		= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_write.s ft_read.s
ASMB	= ft_atoi_base_bonus.s ft_list_push_front_bonus.s ft_list_size_bonus.s
SRC		= $(ASM)
SRCB	= $(ASMB)
OBJB	= $(SRCB:%.s=$(OBJ_DIR)/%.o)
OBJ		:= $(SRC:%.s=$(OBJ_DIR)/%.o)

# COMPILATION
NA		= nasm
NAFLAGS	= -f elf64

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
	@echo "$(_GREEN)						$(_ITL)Has been created!\n$(_END)"

all: $(NAME)

bonus: all $(OBJB)
	@ar -rcs $(NAME) $(OBJB)
	@echo "$(_GREEN)						$(_ITL)BONUS has been add!$(_END)"

clean:
	@rm -rf $(BUILD)
	@echo "\033[1;34mExecute:\t$(_BLUE)Cleaning build\t\033[31m[OK]$(_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;34mExecute:\t$(_BLUE)Cleaning lib\t\033[31m[OK]$(_END)"
re: fclean all

$(BUILD):
	@echo "\033[1;31m\nCreation of .build\033[0m \n"
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o: src/%.s | $(BUILD)
	@echo "\033[1;34mExecute: \t$(_BLUE)Compilation of \033[1;36m$(notdir $<)$(_END)"
	@$(NA) $(NAFLAGS) -s $< -o $@

-include $(DEP)

.PHONY: all clean fclean re bonus
