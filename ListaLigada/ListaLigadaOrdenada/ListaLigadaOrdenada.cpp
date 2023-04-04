#include <iostream>

using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
	NO* ult;
	NO* atual;
};

NO* primeiro = NULL;
NO* ultimo = NULL;
NO* atual = NULL;


// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		// a lista está vazia, insere o elemento no início
		primeiro = novo;
		ultimo = novo;
	}
	else if (novo->valor < primeiro->valor)
	{
		// o novo elemento é menor do que o primeiro, insere no início
		novo->prox = primeiro;
		primeiro = novo;
	}
	else if (novo->valor > ultimo->valor)
	{
		// o novo elemento é maior do que o último, insere no final
		ultimo->prox = novo;
		ultimo = novo;
	}
	else
	{
		// procura a posição correta na lista para inserir o novo elemento
		NO* anterior = primeiro;
		NO* atual = primeiro->prox;
		while (atual != NULL && atual->valor < novo->valor)
		{
			anterior = atual;
			atual = atual->prox;
		}
		if (atual != NULL && atual->valor == novo->valor)
		{
			// o novo elemento já existe na lista, não insere novamente
			free(novo);
			return;
		}
		novo->prox = atual;
		anterior->prox = novo;
	}
}

void excluirElemento()
{
	int numero;
	cout << "Digite o numero a ser excluido: ";
	cin >> numero;

	NO* anterior = NULL;
	NO* atual = primeiro;

	// procura o elemento a ser excluido na lista
	while (atual != NULL && atual->valor < numero) {
		anterior = atual;
		atual = atual->prox;
	}

	// verifica se o elemento foi encontrado
	if (atual != NULL && atual->valor == numero) {
		// remove o elemento da lista
		if (anterior == NULL) {
			// o elemento a ser excluido é o primeiro da lista
			primeiro = atual->prox;
		}
		else {
			anterior->prox = atual->prox;
		}

		// atualiza o ponteiro para o último elemento, se necessário
		if (atual == ultimo) {
			ultimo = anterior;
		}

		free(atual);
		cout << "Elemento " << numero << " excluido com sucesso." << endl;
	}
	else {
		cout << "Elemento " << numero << " nao encontrado na lista." << endl;
	}
}



void buscarElemento()
{
		int numero;
		cout << "Digite o elemento a ser buscado: ";
		cin >> numero;

		NO* encontrado = posicaoElemento(numero);

		if (encontrado == NULL)
		{
			cout << "Elemento nao encontrado." << endl;
		}
		else
		{
			cout << "Elemento encontrado: " << encontrado->valor << endl;
		}

}

// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}



