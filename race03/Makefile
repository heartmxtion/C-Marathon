flags := -Wall -Wextra -Werror -Wpedantic -lncursesw
name := matrix_rain

all: MINILIBMX

MINILIBMX:
	@clang $(flags) src/*.c -o $(name)

clean:
	@rm -f $(name)

uninstall:
	@rm -f $(name)

reinstall:
	make uninstall
	make
