NAME = btc
C = c++
CFLAGS = -Wshadow -Wall -Wextra -Werror -g -std=c++98 -MMD

############################Sources########################
SRCS_DIR = srcs/
FILES = main BitcoinExchange


SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .cpp, $(FILES)))
###########################Objects#########################
OBJS_DIR = objs_and_deps/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

DEPS = $(addprefix $(OBJS_DIR), $(addsuffix .d, $(FILES)))
##########################Libs#############################


##########################Rules############################
$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	mkdir -p $(OBJS_DIR)
	$(C) $(CFLAGS) -c $< -o $@

all: ${NAME}

$(NAME): $(OBJS)
	$(C) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)
