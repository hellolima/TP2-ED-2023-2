CC := g++
SRCDIR := src
OBJDIR := build
BINDIR := bin

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# -g debug, --coverage cobertura
CCFLAGS := -Wall -std=c++17 -pg
LDFLAGS := -lpython3.10 -pg
INC := -I include/ -I third_party/ -I /usr/include/python3.10 -I /home/gabriella/.local/lib/python3.10/site-packages/numpy/core/include

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $^ -o $(BINDIR)/tp2.out $(LDFLAGS)


all: main

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/* coverage/* *.gcda *.gcno

.PHONY: clean
