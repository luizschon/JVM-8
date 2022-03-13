CXX=g++

# Development
CFLAGS=-g -fsanitize=address -fno-omit-frame-pointer -static-libasan

# Production
CFLAGS=-std=c++11

TARGET=main.out
SRCDIR=./src
IDIR=./include
LIBS=-lm

all: $(TARGET)

# Compila e linka todos os arquivos da pasta src e 
# cria arquivo executável main com o comando 'make'
$(TARGET): $(wildcard $(SRCDIR)/*.cpp)
    $(CXX) -o $@ $^ $(CFLAGS) $(LIBS) -I $(IDIR)
	
debug:
    $(CXX) -o $@ $^ $(CFLAGS) $(CFLAGSDEBUG) $(LIBS) -I $(IDIR)	

# Remove os arquivos gerados com o comando 'make clean'
clean:
    rm -f $(TARGET)
