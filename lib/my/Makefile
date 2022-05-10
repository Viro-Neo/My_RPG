##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## csfml is the best thing ever
##

SRCNAMES = 	my_read_file\
		str_to_array\
		my_itoa\
		my_strdup\
		my_strcat\
		my_strlen\
		my_atoi	\
		my_strcmp\
		my_printf\
		my_putchar\
		my_putnbr\
		my_putstr

## DON'T TOUCH BELOW THIS LINE ##

SRC = $(addsuffix .c, $(SRCNAMES))
CC = gcc
CFLAGS = -Wall -Wextra

OUTPUTFILE	= libmy.a

OBJ =	$(SRC:c=o)

TESTFILES =     *.gnco\
	        *.gcda
TEMPFILES =     *~\
				*\#
VGFILES =       vgcore.*

all: $(OBJ)
	ar rc $(OUTPUTFILE) $(OBJ)
	mkdir -p ../../include
	cp my.h ../../include/

clean:
	$(RM) $(OBJ)
	$(RM) $(TESTFILES)
	$(RM) $(TEMPFILES)
	$(RM) $(VGFILES)

fclean:	clean
	$(RM) $(OUTPUTFILE)
	$(RM) ../$(OUTPUTFILE)
	$(RM) ../../include/my.h

re: fclean all
