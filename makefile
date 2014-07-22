CC=gcc
WINCC=i586-mingw32msvc-gcc
CFLAGS=-Wall
WINFLAGS=-Wall -lmingw32
SDLFLAGS=-lSDL -lSDL_image -lSDL_ttf
WINSDLFLAGS=-lSDLmain -lSDL -lSDL_image -lSDL_ttf

SOURCEDIR=./
BINDIR=../bin/

CSOURCE=galama.c gal_interf.c
INDIR_CSOURCE=$(addprefix $(SOURCEDIR),$(CSOURCE))
CHEADER=galama.h
INDIR_CHEADER=$(addprefix $(SOURCEDIR),$(CHEADER))
BIN=galama
EXE=galama.exe

all: ubu win

ubu: $(BINDIR)$(BIN)

win: $(BINDIR)$(EXE)

clean:
	rm -fv $(BINDIR)$(BIN)

$(BINDIR)$(BIN): $(INDIR_CSOURCE) $(INDIR_CHEADER)
	$(CC) $(INDIR_CSOURCE) -o $(BINDIR)$(BIN) $(CFLAGS) $(SDLFLAGS)

$(BINDIR)$(EXE): $(INDIR_CSOURCE) $(INDIR_CHEADER)
	$(WINCC) $(INDIR_CSOURCE) -o $(BINDIR)$(EXE) $(WINFLAGS) $(WINSDLFLAGS)
