/* 
 * File:   main.cpp
 * Author: Osmir e leonardo
 *
 */

#include <cstdlib>
#include "Pessoa.cpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Pessoa *raiz, *pessoa;
    int idade, opcao;
    string nome;
    raiz = NULL;
    /*raiz = new Pessoa("5",5);//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("3",3));//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("2",2));//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("4",4));//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("7",7));//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("8",8));//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("6",6));//adicionando nós na árvore para agilizar testes*/
    do {
        cout << "1 - Inserir" << endl;
        cout << "2 - Listar Pré" << endl;
        cout << "3 - Listar Ordem" << endl;
        cout << "4 - Listar Pós" << endl;
        cout << "5 - Contar Nós" << endl;
        cout << "6 - Somar Idades" << endl;
        cout << "7 - Profundidades Nós" << endl;
        cout << "8 - Deletar por idade" << endl;
        cout << "0 -  Sair" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite um nome" << endl;
                cin >> nome;
                cout << "Digite a idade" << endl;
                cin >> idade;
                pessoa = new Pessoa(nome, idade);
                if (raiz == NULL)
                    raiz = pessoa;
                else
                    raiz->inserirFilho(pessoa);
                break;
            case 2:
                if (raiz == NULL)
                    cout << "Raiz vazia" << endl;
                else
                    raiz->listaPre();
                break;
            case 3:
                if (raiz == NULL)
                    cout << "Raiz vazia" << endl;
                else
                    raiz->listaOrdem();
                break;
            case 4:
                if (raiz == NULL)
                    cout << "Raiz vazia" << endl;
                else
                    raiz->listaPos();
                break;
            case 5:
                if (raiz == NULL)
                    cout << "Raiz vazia" << endl;
                else
                    cout << "Quantidade de Nós:" << raiz->contarNos() << endl;
                break;
            case 6:
                if (raiz == NULL)
                    cout << "Raiz vazia" << endl;
                else
                    cout << "Soma das idades:" << raiz->somarNos() << endl;
                break;
            case 7:
                if (raiz == NULL)
                    cout << "Raiz vazia" << endl;
                else
                    cout << endl << "Profundidade da arvore:" << raiz->profundidadeNos() << endl << endl;
                break;
            case 8:
                if (raiz == NULL)
                    cout << "Raiz vazia" << endl;
                else {
                    cout << "Informe a idade a ser deletada: " << endl;
                    cin >> idade;
                    Pessoa *raizAux = new Pessoa("aux", (raiz->getIdade() - 1));//ponteiro auxiliar que serve como pai fictício e aponta para a nova raiz, caso a antiga seja apagada. A idade é "-1" para
		                                         			//garantir que a raiz sempre será filha à direita de raizAux
                    raizAux->setFilhoDireito(raiz);//ponteiro auxiliar "herda" raiz
                    cout << "------Lista Antes------" << endl;
                    raiz->listaPos();//faz a listagem antes da remoção
                    cout << endl << endl;
                    raiz->removerNo(idade, raizAux);//procura e remove a pessoa com a idade especificada
                    if(raizAux->filhoDireito!=NULL){//se raizAux tem um filho à direita, quer dizer que ainda existe árvore. Se for NULL, significa que o último nó foi apagado
                    	raiz=raizAux->filhoDireito;//raiz atualiza a referência (ou recebe ela mesma, se o nó apagado não foi o raiz)
			cout<<"raiz é: "<<raiz->getNome()<<endl;
		        cout << "------Lista Depois------" << endl;
		        raiz->listaPos();
		        cout << endl << endl;
		    }else{//se o ultimo nó foi apagado, Seta raiz para NULL e avisa que a árvore está vazia
			cout<<"A árvore agora é vazia!!"<<endl;
			raiz=NULL;
		     }
		    delete raizAux;//deleta raiz auxiliar
                }
                break;
            case 0:
                if (raiz != NULL)
                    raiz->deletarArvore();
        }

    } while (opcao != 0);









    return 0;
}

