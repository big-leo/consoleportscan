CC=gcc
FLAGS=-Wall -g

SOURCEDIR=src
SOURCEDIR2=src/util
BUILDDIR=build

EXECUTABLE=target/cpscan
SOURCES=$(wildcard $(SOURCEDIR)/*.c)
OBJECTS=$(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))

SOURCES2=$(wildcard $(SOURCEDIR2)/*.c)
OBJECTS2=$(patsubst $(SOURCEDIR2)/%.c,$(BUILDDIR)/%.o,$(SOURCES2))

build: create_dirs $(EXECUTABLE)

create_dirs:
	mkdir build target

$(EXECUTABLE): $(OBJECTS) $(OBJECTS2)
	$(CC) $(FLAGS) -pthread $^ -o $@

$(OBJECTS): $(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) $(FLAGS) -c -o $@ $<

$(OBJECTS2): $(BUILDDIR)/%.o: $(SOURCEDIR2)/%.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm $(BUILDDIR)/*.o $(EXECUTABLE)