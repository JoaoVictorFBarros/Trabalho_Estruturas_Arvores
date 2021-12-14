# Trabalho_Estruturas_Arvores

Código desenvolvido no Windows 10 e compilado no Dev C++;

# comandos
para se referir a árvore avl use: avl

para se referir a árvore rubro negra use: rn

para se referir a árvore binária padrão use: binary

# Introdução
As árvores binárias são de modo geral um método bastante eficiente de armazenamento de dados, por possuírem custo próximo do logaritmico em busca e pesquisa. Um nó dessa estrutura possui dados armazenados, um ponteiro para o filho esquerdo e um ponteiro para o filho direito, sendo os filhos outros nós da mesma árvore.

A árvore binária padrão armazena entradas aleatórias de maneira razoavelmente eficiente, porém possui Ω(n), ou seja se as entradas estiverem totalmente ou parcialmente ordenadas a estrutura perde bastante desempenho na operação de busca. É devido a esse problma que estruturas como a árvore AVL e a Rubro Negra foram desenvolvidas.

A árvore AVL, a fim de reduzir o problema, implementa funções de rotação de nós da estrutura, sendo elas: Simples esquerda, Simples Direita, Dupla esquerda e Dupla direita. A partir da adição do atributo de peso nos nós da árvore, quando um nó possui peso maior que 2 unidades a estrutura é classificada como desbalanceada e é corrigida a partir de tais funções. Assim o custo máximo de busca é Ω(log (n) + 1), melhoria que pode ser observada no tempo de execução do método de busca.

A árvore Rubro Negra prioriza não só o custo da busca mas também o da inserção, que aumenta, no caso da AVL, com a implementação dos metodos de balanceamento. Sendo assim essa estrutura não utiliza o atributo de peso nos nós, mas atribue a eles uma cor (vermelha ou preta) a fim de só executar o metodo de rebalanceamento quando a diferença de alturas for maior que 2*log(n+1) , assim a árvore Rubro Negra possui custo de inserção maior que a binaria e menor que a AVL e possui custo de busca maior que a AVL e menor que a binária, ou seja ela é um balanço entre as 2 estruturas.

# Finalidades

Considerendo-se o o tópico de introdução pode-ser perceber que as 3 estruturas são úteis em cenários diferentes. A árovre binária padrão possui o menor custo de insersão e o maior de pesquisa, então ela deve ser aplicada em casos onde ocorrem muitas insersões e poucas buscas. A AVL possui o maior custo de insersão e o menor custo de busca, sendo assim ela deve ser implementada em contextos onde ocorrem muitas pesquisas e poucas insersões na estrutura. A Rubro Negra por fim, por possuir custo médio de insersão e pesquisa, deve ser utilizada quando for necessária a utlização de ambos o metodos com certa frequência.
