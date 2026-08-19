NAME = base

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Iinclude

OBJDIR = obj

SRC = 	src/main.cpp\
		src/Base.cpp\

OBJ = $(OBJDIR)/main.o $(OBJDIR)/Base.o 

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

$(OBJDIR)/main.o: src/main.cpp 
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Base.o: src/Base.cpp include/Base.hpp 
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c src/Base.cpp -o $(OBJDIR)/Base.o

clean:
	rm -rf $(OBJDIR) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re