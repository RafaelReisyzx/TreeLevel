
# Descrição
Em árvores binárias, o nível máximo é frequentemente utilizado para compreender a profundidade da estrutura e o tempo necessário para percorrer a árvore em diferentes operações. O
nível máximo, também chamado de altura da árvore, é definido como a distância (em termos
de número de elementos ou nós) da raiz até a folha mais distante.
Neste exercício, você deverá elaborar uma função que não apenas calcule o nível máximo da
árvore, mas que também apresente os seguintes desafios:
1. Cálculo do Nível Máximo: Implemente uma função que calcule o nível máximo de uma
árvore binária sem balanceamento. A função deve percorrer toda a estrutura e identificar
o nível da folha mais distante da raiz, retornando esse valor ao usuário.
2. Visualização Interativa: A cada nova inserção ou remoção de um nó, atualize e exiba
o nível máximo da árvore, permitindo que o usuário visualize como a profundidade da
árvore é impactada pela desbalanceamento natural da estrutura.
3. Análise de Crescimento: Considere dois conjuntos de inserções, um que gere uma árvore "torta" (mais desbalanceada) e outro que resulte em uma árvore mais equilibrada
(embora sem ser balanceada automaticamente). Calcule e compare os níveis máximos
dessas duas árvores ao longo de cada inserção, explicando por que certas inserções
resultam em maiores níveis do que outras. Além disso, tente observar, se possível, se
a prerrogativa de custo de 39% de depreciação de fato ocorre em uma árvore não balanceada em comparação com aquela que se mostra mais organizada.
4. Caminho mais longo: Após calcular o nível máximo da árvore, identifique e mostre ao
usuário o caminho completo da raiz até a folha que define esse nível. Discuta como o
desbalanceamento da árvore afeta o comprimento desse caminho em comparação com
uma árvore idealmente balanceada.

- Desafio adicional: Implemente uma função que, dado o nível máximo calculado, sugira possíveis rotações ou reordenações que poderiam ser realizadas (manual ou hipoteticamente) para
diminuir a profundidade da árvore, sem torná-la balanceada automaticamente. Discuta por que
essas rotações são eficazes ou ineficazes dependendo da estrutura da árvore.

# Compilação e Execução

A pasta do repositorio possui um arquivo Makefile que contém as instruções para compilar e executar. Para usar essas instruções, você pode usar o terminal do seu sistema
operacional e navegar até o diretório raiz do projeto.

Existem três comandos principais que você pode usar no Makefile:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

Em resumo, para executar o programa, você precisa navegar até o diretório raiz do projeto e executar o comando make para compilar o programa e, em seguida, 
executar o comando make run para executá-lo.Se você precisar limpar a compilação anterior, pode usar o comando make clean antes de executar a compilação.
