NAME = converter

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Iinclude

OBJDIR = obj

SRC = 	src/main.cpp\
		src/ScalarConverter.cpp\
		src/Parser.cpp\

OBJ = $(OBJDIR)/main.o $(OBJDIR)/ScalarConverter.o $(OBJDIR)/Parser.o 

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

$(OBJDIR)/main.o: src/main.cpp 
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/ScalarConverter.o: src/ScalarConverter.cpp include/ScalarConverter.hpp 
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c src/ScalarConverter.cpp -o $(OBJDIR)/ScalarConverter.o

$(OBJDIR)/Parser.o: src/Parser.cpp include/Parser.hpp 
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c src/Parser.cpp -o $(OBJDIR)/Parser.o

clean:
	rm -rf $(OBJDIR) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re