# solution: 
# here: https://stackoverflow.com/questions/78381702/dynamic-linker-in-mac-is-not-reading-rpath
# here: https://stackoverflow.com/questions/66268814/dyld-library-not-loaded-how-to-correctly-tell-gcc-compiler-where-to-find/66284977#66284977

main: util_lib
	make -C main

util_lib:
	make -C util_lib

.PHONY: util_lib clean main

clean:
	make -C util_lib clean
	make -C main clean