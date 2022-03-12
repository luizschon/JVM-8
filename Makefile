CXX=g++
CFLAGS=-std=c++11 -g -fsanitize=address -fno-omit-frame-pointer

TARGET=main.out
SRCDIR=./src
IDIR=./include
LIBS=-lm

all: $(TARGET)

# Compila e linka todos os arquivos da pasta src e 
# cria arquivo executável main com o comando 'make'
$(TARGET): $(wildcard $(SRCDIR)/*.cpp)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS) -I $(IDIR)
	
# Remove os arquivos gerados com o comando 'make clean'
clean:
	rm -f $(TARGET)
