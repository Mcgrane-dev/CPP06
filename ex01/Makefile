NAME = serializer

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Iinclude

OBJDIR = obj

SRC = 	src/main.cpp\
		src/Serializer.cpp\

OBJ = $(OBJDIR)/main.o $(OBJDIR)/Serializer.o 

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

$(OBJDIR)/main.o: src/main.cpp 
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Serializer.o: src/Serializer.cpp include/Serializer.hpp 
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c src/Serializer.cpp -o $(OBJDIR)/Serializer.o

clean:
	rm -rf $(OBJDIR) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re