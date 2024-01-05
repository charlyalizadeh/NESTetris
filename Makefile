NAME=NESTetris
SRCS=$(wildcard srcs/*)
OBJS=$(subst srcs,objs,$(subst .cpp,.o,$(SRCS)))
INC=includes
FLAGS=-lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio -Wall -Wextra -Werror -I $(INC)

$(NAME): build $(OBJS)
	g++ $(OBJS) -o $(NAME) $(FLAGS)

$(OBJS): objs/%.o: srcs/%.cpp
	g++ -c $< -o $@ $(FLAGS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

build:
	@mkdir -p objs

debug:
	g++ $(SRCS) -o "$(NAME)_debug" $(FLAGS) -g
