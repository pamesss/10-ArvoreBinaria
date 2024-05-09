#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* esq;
	NO* dir;
};

NO* raiz = NULL;
NO* elementoBuscar;

// headers
// estrutura principal
void menu();
void inicializar();
void inserir();
void exibir();
void esquerda();
void direita();
void exibirQuantidade();
void buscarElemento();


// funcoes auxiliares Arvore
NO* insereArvore(NO* no, int valor);
NO* criaNO(int valor);
int elementosArvore(NO* no);
void exibirElementosArvore(NO* no);
void exibirEsquerda(NO* no);
void exibirDireita(NO* no);
bool buscar(NO* no, int valor);

//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 8) {
		system("cls"); // somente no windows
		cout << "Menu Arvore";
		cout << endl << endl;
		cout << "1 - Inicializar Arvore \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Inserir elemento \n";
		cout << "4 - Exibir elementos \n";
		cout << "5 - Exibir Esquerda \n";
		cout << "6 - Exibir Direita \n";
		cout << "7 - buscar Elemento \n";

		cout << "8 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:exibirQuantidade();
			break;
		case 3: inserir();
			break;
		case 4: exibir();
			break;
		case 5: esquerda();
			break;
		case 6: direita();
			break;
		case 7: buscarElemento();
			break;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// provisório porque não libera a memoria usada pela arvore
	NO* raiz = NULL;
	cout << "Arvore inicializada \n";

}


void inserir()
{
	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;
	if (raiz == NULL) {
		raiz = criaNO(valor);
	}
	else {
		insereArvore(raiz, valor);
	}


}

void exibirQuantidade() {
	cout << "Quantidade de elementos: " << elementosArvore(raiz) << endl;
}

void exibir() {
	if (raiz == NULL) {
		cout << "Arvore Vazia." << endl;
	}
	else {
		exibirElementosArvore(raiz);
	}
}

void esquerda() {
	if (raiz == NULL) {
		cout << "Arvore Vazia." << endl;
	}
	else {
		exibirEsquerda(raiz);
	}
}

void direita() {
	if (raiz == NULL) {
		cout << "Arvore Vazia." << endl;
	}
	else {
		exibirDireita(raiz);
	}
}

void buscarElemento() 
{
	int valor;
	cout << "Insira o valor a ser encontrado: ";
	cin >> valor;
	if (buscar(raiz, valor)) {
		cout << "Elemento encontrado\n";
	}
	else {
		cout << "Elemento nao encontrado\n";
	}
}


NO* criaNO(int valor)
{
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return NULL;
	}

	novo->valor = valor;
	novo->esq = NULL;
	novo->dir = NULL;

	return novo;
}

NO* insereArvore(NO* no, int valor)
{
	if (no->valor > valor && no->esq == NULL) {
		no->esq = criaNO(valor);
		return no->esq;
	}
	else if (no->valor < valor && no->dir == NULL) {
		no->dir = criaNO(valor);
		return no->dir;
	}
	else if (no->valor > valor) {
		return insereArvore(no->esq, valor);
	}
	else if (no->valor < valor) {
		return insereArvore(no->dir, valor);
	}
	else {
		return NULL;
	}
}

int elementosArvore(NO* no)
{
	if (no == NULL) {
		return 0;
	}

	return 1 + elementosArvore(no->esq) + elementosArvore(no->dir);
}

void exibirElementosArvore(NO* no)
{
	if (no != NULL) {
		cout << no->valor << " ";
		exibirElementosArvore(no->esq);
		exibirElementosArvore(no->dir);
	}
}

void exibirEsquerda(NO* no)
{
	if (no != NULL) {
		cout << no->valor << " ";
		exibirEsquerda(no->esq);
	}
}

void exibirDireita(NO* no)
{
	if (no != NULL) {
		cout << no->valor << " ";
		exibirDireita(no->dir);
	}
}


bool buscar(NO* no, int valor) 
{
	if (no == NULL) {
		return false;
	}
	if (no->valor == valor) {
		return true;
	}
	return buscar(no->esq, valor) || buscar(no->dir, valor);
}
