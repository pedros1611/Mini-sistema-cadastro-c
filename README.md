# Mini-Sistema de Cadastro em C

Atividade Avaliativa AT1 da disciplina de Lógica de Programação e Algoritmos (Profª Hially).

## Integrantes

- Pedro Henrique Soares Bezerra
- Natan Henrique Pena
- Matheus Pires

## Sobre o projeto

Programa em C que faz o cadastro de produtos pelo terminal, usando vetores,
estruturas condicionais e estruturas de repetição.

## Dados cadastrados

| Informação | Tipo em C | Exemplo |
|------------|-----------|---------|
| Código     | int       | 101     |
| Nome       | char      | Mouse USB |
| Preço      | float     | 59.90   |
| Quantidade | int       | 10      |

O código é o identificador do produto e não pode se repetir.
O sistema comporta até 20 produtos.

## Funcionalidades

1. **Cadastrar:** adiciona um novo produto, respeitando o limite do vetor.
2. **Consultar:** busca um produto pelo código.
3. **Listar:** mostra todos os produtos cadastrados.
4. **Alterar:** modifica nome, preço e quantidade de um produto existente.
5. **Excluir:** remove um produto e reorganiza os vetores.
0. **Sair:** encerra o programa.

O menu volta a aparecer depois de cada operação, até o usuário escolher 0.

## Como compilar e executar

Com o `gcc` instalado:

```
gcc cadastro_produtos.c -o cadastro
./cadastro
```

No Windows, execute `cadastro.exe` no lugar de `./cadastro`.
Também é possível abrir o arquivo no Code::Blocks, Dev-C++ ou em um compilador online.

## Observações

- Use **ponto** nos preços (exemplo: `59.90`), e não vírgula.
- Valores inválidos de preço e quantidade são recusados e pedidos de novo.
- Mensagens de erro tratadas: opção inválida, registro não encontrado,
  lista vazia, exclusão sem resultado e limite de cadastros atingido.

## Como testamos

- Listar sem nenhum cadastro.
- Cadastrar 3 ou mais produtos e conferir a listagem.
- Consultar um código existente e um inexistente.
- Alterar um produto e consultar de novo.
- Excluir um produto do meio e conferir a nova listagem.
- Tentar excluir um código inexistente.
