  MOD           =       bsh

  BIN           =       bsh
  FLAG          =       -W -Wall -Werror -g -s

  INCLUDE       =       -I./include/
  SRC           =       $(wildcard src/*.c)
  OBJ           =       $(SRC:.c=.o)
  LIBPATH       =       -L${HOME}/.froot/lib/
  LIB           =       -llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm -ldl -lpthread -lopencv_imgproc -lopencv_objdetect -lopencv_video -lopencv_core -l\
avcall -lusb -g -s

  all:          bin
  bin:          $(OBJ)
	@gcc $(OBJ) -o $(BIN) $(LIBPATH)
	@echo ${YELLOW} "[FINISHED] " ${DEFAULT} $(BIN)

  .c.o:
	@gcc $(INCLUDE) $(FLAG) -c $< -o $@
	@echo ${GREEN} "[OK]" ${DEFAULT} $< 
  clean:
	@rm -f $(OBJ)
  fclean:       clean
	@rm -f $(BIN)
  re:           fclean all

  .PHONY: all clean fclean re

  .SUFFIXES: .cpp .o

# Colors                                                                                                                                                                                             
DEFAULT = "\033[00m"
GREEN = "\033[1;32m"
TEAL = "\033[1;36m"
RED = "\033[1;31m"
BLACK = "\033[1;30m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
PURPLE = "\033[1;35m"
WHITE = "\033[1;37m"

