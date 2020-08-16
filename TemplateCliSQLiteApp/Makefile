# Build mode
# 0: development (max safety, no optimisation)
# 1: release (min safety, optimisation)

BUILD_MODE?=0

# Path to SQLite

PATH_SQLITE=../../../Tools/SQLite

# Path to PBMake

PATH_PBMAKE=../../PBMake

# Compiler arguments depending on BUILD_MODE

ifeq ($(BUILD_MODE), 0)
	BUILD_ARG=-I$(PATH_SQLITE) -I$(PATH_PBMAKE)/Include -Wall -Wextra -Og -ggdb -g3 -DPBERRALL='1' \
	  -DBUILDMODE=$(BUILD_MODE)
	LINK_ARG=-L$(PATH_PBMAKE)/Lib/`uname -m` -lpbdev -lm -lpthread -ldl -rdynamic
else 
  ifeq ($(BUILD_MODE), 1)
	  BUILD_ARG=-I$(PATH_SQLITE) -I$(PATH_PBMAKE)/Include -Wall -Wextra -Werror -Wfatal-errors -O3 \
		  -DPBERRSAFEMALLOC='1' -DPBERRSAFEIO='1' -DBUILDMODE=$(BUILD_MODE)
	  LINK_ARG=-L$(PATH_PBMAKE)/Lib/`uname -m` -lpbrelease -lm -lpthread -ldl -rdynamic
	endif
endif

# Compiler

COMPILER=gcc-7

# Rules for the executable

all: clean main

main: main.o sqlite3.o Makefile
	$(COMPILER) main.o sqlite3.o $(LINK_ARG) -o main 

main.o: main.c Makefile
	$(COMPILER) $(BUILD_ARG) -c main.c 

sqlite3.o: $(PATH_SQLITE)/sqlite3.c
	gcc -O3 -c $(PATH_SQLITE)/sqlite3.c

clean:
	rm -f *.o main

sqllite:
	wget https://sqlite.org/2020/sqlite-amalgamation-3320200.zip; \
	unzip sqlite-amalgamation-3320200.zip; \
	cd sqlite-amalgamation-3320200; \
	gcc shell.c sqlite3.c -lpthread -ldl -O3 -o sqlite3; \
	cd -
