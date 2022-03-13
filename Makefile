all:
	gcc get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=$(BUFFER_SIZE)
check: all
	@./a.out
	@rm -f a.out