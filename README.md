# JVM-8
Implementação menos avançada de JVM já vista na UnB. Projeto da disciplina de Software Básico 2021/2 - Universidade de Brasília

## TL;DR
Compilar: `$ make`  
Exibidor: `$ ./main.exe -r ./examples/<nome_da_classe>.class`  
Interpretador: `$ ./main.exe ./examples/<nome_da_classe>.class`  
Docs: `$ doxygen Doxyfile` (`docs/index.html`)

## Linux
Para compilar e rodar o programa em modo debug, basta utilizar `$ make debug` e `$ ./debug ./examples/<nome_da_classe>.class`, que irá compilar o programa com sanitize address para verificar vazamentos de memória.

## Windows
Para compilar e rodar o programa, basta utilizar `$ make` para compilar e `$ ./main.exe examples/double_aritmetica.class` para executar os arquivos contidos na pasta `examples` (ou outro arquivo da sua escolha). 

## Documentação
É possível gerar uma página HTML com a documentação do código. Para isso, basta utilizar o comando `$ doxygen Doxyfile` (é preciso ter o doxygen instalado). Então, basta abrir na pasta docs o arquivo `index.html` no navegador, que ele irá te direcionar à página.