main: util_lib
	make -C main

util_lib:
	make -C util_lib

.PHONY: util_lib clean main

clean:
	make -C util_lib clean
	make -C main clean