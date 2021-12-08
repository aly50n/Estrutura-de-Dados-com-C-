//usando o getline(cin,STRING); para receber strings.
#include <iostream>
//01-Faça uma função que receba duas listas encadeadas. Essa função deve verificar se as listas possuem o mesmo tamanho e, em caso positivo, intercalar os seus elementos, fazendo com que a primeira lista possua todos os elementos ao fim do processo, enquanto a segunda lista termine vazia. Por intercalar entende-se fazer com que os elementos integrem uma única lista, alternando elementos da primeira com a segunda lista.
using namespace std;

struct noLista{
  string dado;
  noLista *prox;
  noLista *ant;
};

struct descritor{
  noLista *ini;
  noLista *fim;
  int tam;
};

//inicializa um descritor.
descritor* inicializar(){
  descritor *d = new descritor;
  d->ini = NULL;
  d->fim = NULL;
  d->tam = 0;
  return d;
}

//insere info no inicio da lista.
void ins_no_inicio(descritor *d, string dado){
  noLista* aux = new noLista;
  aux->ant= NULL;
  aux->prox= NULL;
  aux->dado = dado;
  if(d->ini == NULL){
    d->ini = aux;
    d->fim = aux;
    d->tam++;
  }
  else{
    aux->prox = d->ini;
    d->ini->ant = aux;
    d->ini= aux;
    d->tam++;
  }
}

//insere info no fim da lista.
void ins_no_fim(descritor *d, string dado){
  noLista* aux = new noLista;
  aux->ant= NULL;
  aux->prox= NULL;
  aux->dado = dado;
  if(d->ini == NULL){
    d->ini = aux;
    d->fim = aux;
    d->tam++;
  }
  else{
    aux->ant= d->fim;
    d->fim->prox= aux;
    d->fim = aux;
    d->tam++;
  }
}

//insere uma info na posição desejada.
bool inserir_posicao(descritor *d, string info, int pos){
  if(pos >  d->tam+1){
    return false;
  }  
  else{
    if(pos == 1){
      ins_no_inicio(d, info);
    }
    else if(pos == d->tam+1){
      ins_no_fim(d, info);
    }
    else{
      int cont = 1;
      noLista* novo = new noLista;
      novo->dado = info;
      novo->ant = NULL;
      novo->prox= NULL;
      noLista* p = d->ini;
      while(cont < pos - 1){
        p = p->prox;
        cont++;
      }
      novo->prox = p->prox;
      novo->ant = p;
      p->prox = novo;
    }
    return true;
  }
}

//função que intercala as listas de tamanhos iguais.
bool intercalar(descritor* d1, descritor* d2){
  if(d1->tam == d2->tam){
    int i;
    noLista *l1,*l2, *aux;
    l1 = d1->ini;
    l2 = d2->ini;
    for(i=0;i<d1->tam;i++){
      if(l1->prox!=NULL){
        aux = l1->prox;
        l1->prox = l2;
        l2->ant = l1;
        l2 = l2->prox;
        l1->prox->prox= aux;
        aux->ant= l1->prox;
        l1 = aux;
      }
      else{
        l1->prox = l2;
        l2->ant = l1;
      }
    }
    d2->ini=NULL;
    d2->fim=NULL;
    d2->tam=0;
    return true;
  }
  return false;  
}

//imprime a lista encadeada.
void imprimir_lista(descritor* d){
  noLista*l= d->ini;
  while(l != NULL){
    cout<<l->dado<<" ";
    l = l->prox;
  }
  cout<<endl;
}

int main() {
  descritor *d1,*d2;
  d1 = inicializar();
  d2 = inicializar();
  string info;
  int tam, pos,i, aux;
  while(true){
    cout<<"MENU:\n1-Inserir no inicio das listas.\n2-Inserir no fim das listas.\n3-Inserir na posição desejada.\n4-Ver tamanho das listas.\n0-Sair e Intercalar Listas.\nEscolha uma opção: ";
    cin>>aux;
    setbuf(stdin, NULL);
    if(aux == 1){
      cout<<"Digite quantas informações quer adicionar no inicio da primeira lista: ";
      cin>>tam;
      setbuf(stdin, NULL);
      //inserindo infos no inicio da primeira lista:
      for(i=0;i<tam;i++){
        cout<<"Digite as informações: ";
        getline(cin,info);
        ins_no_inicio(d1,info);
      }
      cout<< "Lista 1: ";
      imprimir_lista(d1);
      cout<<"=========================\n";
      cout<<"Digite quantas informações quer adicionar no inicio da segunda lista: ";
      cin>>tam;
      setbuf(stdin, NULL);
      //inserindo infos no inicio da segunda lista:
      for(i=0;i<tam;i++){
        cout<<"Digite as informações: ";
        getline(cin,info);
        ins_no_inicio(d2,info);
      }
      cout<< "Lista 2: ";
      imprimir_lista(d2);
      cout<<"=========================\n";
    }
    else if(aux == 2){
      cout<<"Digite quantas informações quer adicionar no fim da primeira lista: ";
      cin>>tam;
      setbuf(stdin, NULL);
      //inserindo infos no fim da primeira lista:
      for(i=0;i<tam;i++){
        cout<<"Digite as informações: ";
        getline(cin,info);
        ins_no_fim(d1,info);
      }
      cout<< "Lista 1: ";
      imprimir_lista(d1);
      cout<<"=========================\n";
      cout<<"Digite quantas informações quer adicionar no fim da segunda lista: ";
      cin>>tam;
      setbuf(stdin, NULL);
      //inserindo infos no fim da segunda lista:
      for(i=0;i<tam;i++){
        cout<<"Digite as informações: ";
        getline(cin,info);
        ins_no_fim(d2,info);
      }
      cout<< "Lista 2: ";
      imprimir_lista(d2);
      cout<<"=========================\n";
    }
    else if(aux == 3){
      cout<<"Digite quantas informações quer adicionar na primeira lista: ";
      cin>>tam;
      //inserindo infos na primeira lista:
      for(i=0;i<tam;i++){
        cout<<"Digite a posição que quer adicionar a informação na primeira lista: ";
        cin>>pos;
        setbuf(stdin, NULL);
        cout<<"Digite as informações: ";
        getline(cin,info);
        if(inserir_posicao(d1, info, pos)){
          cout<<"\nInformação inserida.\n";
        }
        else{
          cout<<"\nFalha ao adicionar, posição maior que a lista.\n";
        }
      }
      cout<< "Lista 1: ";
      imprimir_lista(d1);
      cout<<"=========================\n";
      cout<<"Digite quantas informações quer adicionar na segunda lista: ";
      cin>>tam;
      //inserindo infos na segunda lista:
      for(i=0;i<tam;i++){
        cout<<"Digite a posição que quer adicionar a informação na segunda lista: ";
        cin>>pos;
        setbuf(stdin, NULL);
        cout<<"Digite as informações: ";
        getline(cin,info);
        if(inserir_posicao(d2, info, pos)){
          cout<<"\nInformação inserida.\n";
        }
        else{
          cout<<"\nFalha ao adicionar, posição maior que a lista.\n";
        }
      }
      cout<< "Lista 2: ";
      imprimir_lista(d2);
      cout<<"=========================\n";
    }
    else if(aux == 4){
      cout<<"\n=========================\n";
      cout<<"Tamanho da lista 1: "<<d1->tam;
      cout<<"\nTamanho da lista 2: "<<d2->tam<< "\n";
      cout<<"=========================\n";
    }
    else if(aux == 0){
      break;
    }
  }
  cout<<"=========================\n";
  //teste para intercalar as listas:
  if(intercalar(d1,d2)){
    if(d1->tam == 0 && d2-> tam == 0){
      cout<< "As listas estão vazias.";
    }
    else{
      cout<< "\nAs listas foram intercaladas em uma só!\n";
      cout<< "Lista Intercalada: ";
      imprimir_lista(d1);
    }
  }
  else{
    cout<< "\nFalha! As listas não são dos mesmo tamanho então não foram intercaladas!\n";
    cout<< "Lista 1: ";
    imprimir_lista(d1);
    cout<< "Lista 2: ";
    imprimir_lista(d2);
  }
  
}