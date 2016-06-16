#include <cstdlib>
#include "pessoa.cpp"
using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    Pessoa *raiz, *pessoa;
    int idade, opcao;
    string nome;
    raiz = NULL;
    //raiz = new Pessoa("5",5);//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("15",15),&raiz);//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("27",27),&raiz);//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("49",49),&raiz);//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("10",10),&raiz);//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("8",8),&raiz);//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("67",67),&raiz);//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("59",59),&raiz);//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("9",9),&raiz);//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("13",13),&raiz);//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("20",20),&raiz);//adicionando nós na árvore para agilizar testes
    raiz->inserirFilho(new Pessoa("14",14),&raiz);//adicionando nós na árvore para agilizar testes*/
    raiz->atualizarFBs(&raiz);
    do {
        cout << "1 - Inserir" << endl;
        cout << "2 - Listar Pré" << endl;
        cout << "3 - Listar Ordem" << endl;
        cout << "4 - Listar Pós" << endl;
        cout << "5 - Contar Nós" << endl;
        cout << "6 - Somar Idades" << endl;
        cout << "7 - Profundidades Nós" << endl;
        cout << "8 - Deletar por idade" << endl;
        cout << "9 - Listar Fator de Balanceamento de todos os nós" << endl;
        cout << "0 -  Sair" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite um nome" << endl;
                cin >> nome;
                cout << "Digite a idade" << endl;
                cin >> idade;
                pessoa = new Pessoa(nome, idade);
               // if (raiz == NULL)
               //     raiz = pessoa;
               // else{
                    raiz->inserirFilho(pessoa,&raiz);
					//raiz->atualizarFBs(&raiz);
				//}
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
                    cout << "------Lista Antes------" << endl;
                    raiz->listaPos();//faz a listagem antes da remoção
                    cout << endl << endl;
                    raiz->removerNo(idade, NULL, &raiz);
                    if(raiz==NULL)//confere se ainda existe árvore
	  		    		cout<<"A árvore agora é vazia!!"<<endl;
			        else{
				        cout << "------Lista Depois------" << endl;
				        raiz->listaPos();//faz a listagem depois da remoção
				        cout << endl << endl;
                        raiz->atualizarFBs(&raiz);
			    	}
                }
                break;
            case 9:
                raiz->listarFBs(&raiz);
            break;
            case 0:
                if (raiz != NULL)
                    raiz->deletarArvore();
            break;
            default:
            	cout<<endl<<"Opção inválida!"<<endl<<endl;
        }

    } while (opcao != 0);









    return 0;
}
