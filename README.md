# Trabalho de Implementação para a Cadeira Fundamentos de Sistemas Operacionais

## Descrição do Projeto

O arquivo de dados intergenic.csv contém os dados de uma aplicação de genoma de bactérias. As informações do arquivo estão separadas por “;”. As informações contêm o nome do organismo, nome do gene, tipo do organismo, família do organismo, papel biológico, posição inicial no genoma, posição final no genoma e a sequência de DNA. Este arquivo contém dados repetidos para as cinco primeiras informações.
Objetivo

* Leitura do Arquivo: Deve-se ler o arquivo para a memória, mas o arquivo não pode estar todo na memória ao mesmo tempo.
* Ordenação do Arquivo: Deve-se ordenar este conjunto de dados pelo gene em ordem crescente e, dentro do conjunto do mesmo gene, ordenar pelo nome do organismo. Utilize mais de um processo ou thread para ordenar partes diferentes do arquivo e, depois para juntar o resultado.
* Gravar o Arquivo: Deve-se gravar o conjunto de dados ordenado em um nome arquivo com as informações separadas por “;”.

## Instruções para a compilação e execução

é necessário cmake versão 3.13, ou superior e um compilador com suporte ao standard C++17 para compilar esse programa. Testado no Ubuntu 18.04, com cmake 3.16.5 e clang 6.0.0.

Instruções para compilar o programa:

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Para executar o programa:

```bash
$ ./bin/parallel ../data/intergenidb.csv <numero-de-threads>
```

O resultado será posto no arquivo `output.csv` na pasta de execução do programa.

## Autores

Júlio De Bastiani