/*
submissão: 
    pasta: projeto/
        bin/ -> executável
        docs/ -> documentação
        lib/ -> .h
        src/ -> .c
guardar os projetos:
    gcc -Wall -Wextra src/*.c
                        V
                busca tds os ficheiros .c
                e aloca em projeto/src/
    gcc -Wall -Wextra -o bin/proj -g
                           V       V
                guarda em proj-   roda e debuga
                eto/bin/proj,     o código
                sendo proj um 
                executável
valgrind --leak-check-full --track-origins-yes ./main
--> vai dizer o que o programa faz, e vai dizer se libertei a 
memória de todas as variáveis e onde estão os erros.
sempre libertar o mesmo tanto que foi feito malloc's

não utilizar scanf, usar o fgets e se quiser numero converter, 
sem utilizar o atoi()
cleanbuffer_removeline <- para remover \n e dps:
e colocar '\0'
Meter um ciclo até o input ser válido e uma mesagem caso seja inválido,
mas sem parar o projeto
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
