NAME = converter

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Iinclude

OBJDIR = obj

SRC = 	src/main.cpp\


OBJ = $(OBJDIR)/main.o #$(OBJDIR)/Bureaucrat.o 

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

$(OBJDIR)/main.o: src/main.cpp 
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $(OBJDIR)/main.o

# $(OBJDIR)/AForm.o: src/AForm.cpp include/AForm.hpp 
# 	@mkdir -p $(OBJDIR)
# 	$(CXX) $(CXXFLAGS) -c src/AForm.cpp -o $(OBJDIR)/AForm.o

clean:
	rm -rf $(OBJDIR) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re