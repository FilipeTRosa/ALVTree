compile:
		gcc avltree.c -c -g
		gcc main.c avltree.o -o exec -g
		./exec