OUT 	= sudokusmile
SRC 	= main.c
SRCO 	= $(SRC:.c=.o)

all: $(SRCO)
	gcc $(SRCO) -Wall -o $(OUT)

clean:
	rm -f -- $(SRCO)
	rm -f -- $(OUT)

re:	clean all
