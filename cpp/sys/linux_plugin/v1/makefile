BINS=v1
DLIBS=libprint_hello_world.so libprint_hello_guys.so

all: $(BINS) $(DLIBS)

v1: main.o
	$(CXX) -o $@ $? -ldl

libprint_hello_world.so: print_hello_world.cc
	$(CXX) -fPIC -shared -o $@ $?

libprint_hello_guys.so: print_hello_guys.cc
	$(CXX) -fPIC -shared -o $@ $?

clean:
	- rm -f $(BINS) $(DLIBS) *.o

