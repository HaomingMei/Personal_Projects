CC = gcc
CFLAGS = -O0 

run: simplethread
#* ./simplethread runs the simplethread executable
	@echo "To run: ./simplethread"

#* -o Links object files and ouptut executable 
#* -lphthread links the object files with the pthread libraries
#* $@ tells the program to use the target name, thus $@.o means target_name.o
simplethread: simplethread.o 
#* We output simplethread using simplethread.o and also link it with pthread library
	$(CC) $(CFLAGS) -o $@ $@.o -lpthread

simplethread.o: simplethread.c
	$(CC) $(CFLAGS) -c simplethread.c -o simplethread.o

# Refresh/reset the unncessary fles
clean:
#* If we find any object of dependence file, delete it
#* -f tells the program not to complain (warning) if file does not exist
	rm -f *.o *.d
	rm -f simplethread

# For all c files, we convert into object files

.c.o: 
#* Recall object files contain symbol table, section headers, etc. But does not include
#  Up to references' symbol table, thus, linking is necessary
#* The -c flag tells us to preprocess -> compile -> assemble -> object file
#* The $< file is automatically filled by the compilation as the first prerequist
#  which is an .c file
	$(CC) $(CFLAGS) -c $<
