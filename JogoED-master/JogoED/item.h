#include <allegro5\allegro.h>
#include "personagem.h"
#ifndef ITEM_H
#define ITEM_H


typedef struct obj {
	//Coordenada mapa;
	int cY;
	int cX;
	//posição na matriz
	int mY;
	int mX;
	//Coordenada x,y (em px) para borda
	int bY;
	int bX;
	ALLEGRO_BITMAP *imagem;

}obj;

static int posXPegar = 355;
static int posYPegar = 430;

static int posXInvetario = 475;
static int posYInvetario = 535;

typedef struct no *TipoApontador;

typedef struct {
	obj objeto;
	} Item;

typedef struct no {
	Item item;
	struct no* prox;
}no;


typedef struct lista {
	TipoApontador Primeiro, Ultimo;
} lista;

void verificaPegouItem(personagem p, lista *pegar, lista *inventario);
void RemoveNo(lista *l, obj o);
void adicionaNo(lista *l, Item I);
void moveItens(lista *pegar, int x, int y);
void mostraItemMapa(lista *l);
void mostraListaInventario(lista *l);
void CriarNo(lista *l);
void RemoveLista(lista *l, obj o);
void InsereLista(lista *l, obj o);
void Crialista(lista *l);
TipoApontador PesquisaLista(lista *L, obj o);

#endif // !ITEM_H
