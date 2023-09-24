#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

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

	if (primeiro == NULL) {

		primeiro = novo;
	}
	else if (primeiro->valor == novo->valor) {
		cout << "Elemento já presente!" << endl;
	}
	else {
		NO* ant = NULL;
		NO* valorAtual = primeiro;

		while (valorAtual != NULL) {
			if (valorAtual->valor < novo->valor) {
				ant = valorAtual;
			}
			else if (valorAtual->valor == novo->valor) {
				cout << "Elemento já presente!" << endl;
			}
			else {
				return;
			}
			valorAtual = valorAtual->prox;
		}
		if (ant == NULL) {
			novo->prox = primeiro;
			primeiro = novo;
		}
		else {
			ant->prox = novo;
			novo->prox = valorAtual;
		}
	}
}

void excluirElemento()
{
	NO* valorAtual, * anterior;
	anterior = NULL;
	int deletar;

	if (primeiro == NULL) {
		cout << "A lista está vazia!" << endl;
	}
	else {
		cout << "Digite qual será o valor que voce deseja exluir: ";
		cin >> deletar;
		valorAtual = primeiro;

		while (valorAtual != NULL) {
			if (valorAtual->valor == deletar) {
				if (anterior == NULL) {
					primeiro = valorAtual->prox;
				}
				else {
					anterior->prox = valorAtual->prox;
				}
				free(valorAtual);
				cout << "Valor deletado!" << endl;
				return;
			}
			anterior = valorAtual;
			valorAtual = valorAtual->prox;
		}

		cout << "Valor nao presente!" << endl;
	}
}

void buscarElemento()
{
	{
		NO* aux = primeiro;
		int achado = false;
		int buscar;

		if (primeiro == NULL) {
			cout << "A lista esta vazia!" << endl;
		}
		else {
			cout << "Digite o valor que deseja buscar: ";
			cin >> buscar;

			while (aux != NULL) {
				if (aux->valor == buscar) {
					cout << "O valor foi encontrado!" << endl;
					achado = true;
					break;
				}
				aux = aux->prox;
			}
			if (!achado) {
				cout << "O valor nao foi encontrado!" << endl;
			}
		}
	}
}


