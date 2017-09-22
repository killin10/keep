BINS=v2
DLIBS=libprint_hello_world.so libprint_hello_guys.so
PLUGIN_DIR=plugins

all: $(BINS) $(DLIBS)  cp_plugins

v2: main.o
	$(CXX) -o $@ $? -ldl

libprint_hello_world.so: print_hello_world.cc
	$(CXX) -fPIC -shared -o $@ $?

libprint_hello_guys.so: print_hello_guys.cc
	$(CXX) -fPIC -shared -o $@ $?

cp_plugins:
	if [ ! -d $(PLUGIN_DIR) ]; then mkdir -p $(PLUGIN_DIR); fi;
	cp *.so $(PLUGIN_DIR)

clean:
	- rm -rf $(BINS) $(DLIBS) $(PLUGIN_DIR) *.o

