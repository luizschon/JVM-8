CXX=g++
CFLAGS=-std=c++11 -g -fsanitize=address -fno-omit-frame-pointer

TARGET=main
SRCDIR=./src
IDIR=./include
LIBS=-lm

all: $(TARGET)

# Compila e linka todos os arquivos da pasta src e 
# cria arquivo executável main com o comando 'make'
$(TARGET): $(wildcard $(SRCDIR)/*.cpp)
  $(CXX) -o $@ $^ $(CFLAGS) $(LIBS) -I $(IDIR)
  
# Executa o arquivo main usando flag especial com o 
# comando 'make run'
run:
  ASAN_OPTIONS=detect_leaks=1 ./$(TARGET)
  
# Remove os arquivos gerados com o comando 'make clean'
clean:
  rm -f $(TARGET)
