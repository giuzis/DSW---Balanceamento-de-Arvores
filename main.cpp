#include "arvores2.h"

int main()
{
    node *raiz = NULL;
    int dado = 1, contador = 0, comando = 7;
    bool criou_espinha = false;
    system("clear");

    while(comando)
    {
        cout << "Digite 1 para inserir um dado. " << endl;
        cout << "Digite 2 para remover um dado. " << endl;
        cout << "Digite 3 para imprimir a arvore. " << endl;
        cout << "Digite 4 para criar espinha dorsal. " << endl;
        cout << "Digite 5 para criar árvore balanceada. " << endl;
        cout << "Digite 0 para sair. " << endl;
        cin >> comando;
        switch (comando){
        case 1:
            //system("clear");
            cout << "Digite o dado que quer inserir: ";
            cin >> dado;
            contador += insere(&raiz, dado);
            break;
        case 2:
            //system("clear");
            if(contador == 0)
            {
                cout << "Arvore vazia, nao ha o que remover. " << endl;
                break;
            }
            cout << "Digite o dado que quer remover: ";
            cin >> dado;
            contador -= remove(&raiz, dado);
            break;
        case 3:
            //system("clear");
            mostraArvore(raiz, contador);
            break;
        case 4:
        	criou_espinha = true;
            if(contador == 0)
            {
                cout << "Arvore vazia. " << endl;
                break;
            }
            criaEspinhaDorsal(&raiz);
            break;
        case 5:
            if(contador == 0)
            {
                cout << "Arvore vazia. " << endl;
                break;
            }
            if(criou_espinha)
            	balanceiaArvore(&raiz, contador);
            else
            	cout << "Necessario criar espinha antes. " << endl;
            criou_espinha = false;
            break;
        case 0:
            break;
        default:
            //system("clear");
            cout << "Comando invalido! Tente novamente: ";
        }
        cout << endl;
    }
    return 0;
}
