# 

## Regras

Haverá duas pilhas, A e B, entre as quais serão realizados alguns movimentos.

- Inicialmente, a pilha A vai conter n números aleatórios, podendo ser positivos ou negativos, e não pode haver números duplicados.

- A pilha B inicia vazia.

O objetivo é organizar os números na pilha A, utilizando os movimentos abaixo:

- **sa (swap a)**: Troca de posição os dois primeiros elementos da pilha A.
	- Não faz nada se houver apenas um ou nenhum elemento.

- **sb (swap b)**: Troca de posição os dois primeiros elementos da pilha A.
	- Não faz nada se houver apenas um ou nenhum elemento.

- **ss (swap a and swap b)**: Faz os movimentos `sa` e `sb` ao mesmo tempo.

- **pa (push a)**: Pega o primeiro elemento do topo da pilha B e coloca no topo da pilha A.
	- Não faz nada se a pilha B estiver vazia.

- **pb (push b)**: Pega o primeiro elemento do topo da pilha A e coloca no topo da pilha B.
	- Não faz nada se a pilha A estiver vazia.

- **ra (rotate a)**: Sobe todos os elementos da pilha A em 1 nível.
	- O primeiro elemento se torna o último.

- **rb (rotate b)**: Sobe todos os elementos da pilha B em 1 nível.
	- O primeiro elemento se torna o último.

- **rr (rotate a and rotate b)**: Faz os movimentos `ra` e `rb` ao mesmo tempo.

- **rra (reverse rotate a)**: Desce todos os elementos da pilha A em 1 nível.
	- O último elemento se torna o primeiro.

- **rrb (reverse rotate b)**: Desce todos os elementos da pilha B em 1 nível.
	- O último elemento se torna o primeiro.

- **rrr (reverse rotate a and reverse rotate b)**: Faz os movimentos `rra` e `rrb` ao mesmo tempo.
