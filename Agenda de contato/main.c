#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char nome[50];
  char telefone[15];
} Contato;

void salvarContato(Contato c) {
  FILE *arquivo = fopen("contatos.txt", "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }
  fprintf(arquivo, "%s,%s\n", c.nome, c.telefone);
  fclose(arquivo);
}

void listarContatos() {
  FILE *arquivo = fopen("contatos.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return;
  }

  char linha[70];
  while (fgets(linha, sizeof(linha), arquivo)) {
    printf("%s", linha);
  }
  fclose(arquivo);
}

int main() {
  Contato c;
  int opcao;

  do {
    printf(
        "1. Salvar Contato\n2. Listar Contatos\n3. Sair\nEscolha uma opção: ");
    scanf("%d", &opcao);
    getchar(); 
      // Para consumir o '\n' após o número

    switch (opcao) {
    case 1:
      printf("Nome: ");
      fgets(c.nome, sizeof(c.nome), stdin);
      c.nome[strcspn(c.nome, "\n")] = 0;
      // Remove o '\n'
      printf("Telefone: ");
      fgets(c.telefone, sizeof(c.telefone), stdin);
      c.telefone[strcspn(c.telefone, "\n")] = 0;
      // Remove o '\n'
      salvarContato(c);
      break;
    case 2:
      listarContatos();
      break;
    case 3:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida!\n");
    }
  } while (opcao != 3);

  return 0;
}