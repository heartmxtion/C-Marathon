flags := -std=c11 -Wall -Wextra -Werror -Wpedantic
name := part_of_the_matrix

all: $(name)

$(name):
	clang $(flags) -Iinc -o $(name) src/*.c

clean:
	rm -rf $(name)

uninstall:
	rm -rf $(name)

reinstall:
	make uninstall
	make