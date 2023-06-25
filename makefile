compile:
		gcc avltree.c -c -g
		gcc -g main.c avltree.o -o exec
		./exec