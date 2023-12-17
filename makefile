main: src/main.c src/git.h src/utils.h
	gcc src/main.c src/git.c src/utils.c -o note
