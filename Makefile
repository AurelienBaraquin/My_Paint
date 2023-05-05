##
## EPITECH PROJECT, 2022
## name
## File description:
## desc
##

CC = gcc
TARGET = my_paint
FLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lm \
-lcsfml-audio -lcsfml-network
SRC = $(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

all :	$(TARGET)

$(TARGET) :
	$(CC) $(SRC) -o $(TARGET) $(FLAGS)

clean :
	rm -rf $(TARGET)
	rm -rf *.o

fclean : clean

re : fclean all
