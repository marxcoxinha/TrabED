#include "item.h"
#include <allegro5\allegro.h>
#include "personagem.h"



void Crialista(lista *L) {
	(*L).Primeiro = NULL;
	(*L).Ultimo = NULL;
}



void verificaPegouItem(personagem p, lista *pegar, lista *inventario) {
	TipoApontador aux = pegar->Primeiro;
	bool pegou = false;
	while ((aux != NULL) && (pegou == false)) {
		if ((aux->item.objeto.mX == p.x) && (aux->item.objeto.mY == p.y)) {
			Item aux2 = aux->item;
			RemoveNo(pegar, aux2.objeto);
			adicionaNo( inventario, aux2);
			pegou = true;
		}
		else aux = aux->prox;
	}
}



void moveItens(lista *pegar, int x, int y) {
	TipoApontador aux = pegar->Primeiro;
	while (aux != NULL) {
		aux->item.objeto.cX += x;
		aux->item.objeto.cY += y;
		aux = aux->prox;
	}
}

void adicionaNo(lista *L, Item I) {

	TipoApontador P;

	P = (TipoApontador) malloc(sizeof(no));
	if (P == NULL) {
		return;
	}

	P->item = I;
	P->prox = NULL;
	if (L->Primeiro == NULL) {
		L->Primeiro = P;
		L->Ultimo = P;
	} else {
		L->Ultimo->prox = P;
		L->Ultimo = P;
	}



}
void mostraListaInventario(lista *l) {
	TipoApontador aux = l->Primeiro;
	if (l != NULL) {
		while (aux != NULL) {
			al_draw_bitmap(aux->item.objeto.imagem, aux->item.objeto.bX, aux->item.objeto.bY, 0);
			aux = aux->prox;
		}
	}
}

void mostraItemMapa(lista *l) {
	TipoApontador aux = l->Primeiro;
	if (l->Primeiro != NULL) {
		while (aux != NULL) {
			al_draw_bitmap(aux->item.objeto.imagem, aux->item.objeto.cX, aux->item.objeto.cY, 0);
			aux = aux->prox;
		}
	}
}
void CriarNo(lista *L) {

	srand(time(NULL));

	int x, y;

	y = rand() % 16;
	x = rand() % 30;


	no novo;

	novo.item.objeto.cY = y * 50;
	novo.item.objeto.cX = x * 50;
	novo.item.objeto.mX = x;
	novo.item.objeto.mY = y;
	novo.item.objeto.bX = posXPegar;
	novo.item.objeto.bY = posYPegar;

	adicionaNo(L, novo.item);
}

int static RemovePosicao(lista *L, TipoApontador P) {


	if (P == L->Primeiro && L->Primeiro == L->Ultimo) {
		L->Primeiro = NULL;
		L->Ultimo = NULL;
		free(P);
		return 0;
	}

	if (P == L->Primeiro) {
		L->Primeiro = L->Primeiro->prox;
		free(P);
		return 0;
	}


	TipoApontador aux = L->Primeiro;
	while(aux->prox != NULL && aux->prox != P) {
		aux = aux->prox;
	}

	aux->prox = P->prox;

	if (aux->prox == NULL)
		L->Ultimo = aux;

	free(P);

	return 0;

}

void RemoveNo(lista *L, obj o) {
	TipoApontador P = PesquisaLista(L, o);
	int r = RemovePosicao(L, P);

}
TipoApontador PesquisaLista(lista *L, obj o) {

	TipoApontador P;

	P = L->Primeiro;
	while(P != NULL) {

		if (P->item.objeto.mX == o.mX && P->item.objeto.mY == o.mY && P->item.objeto.cX == o.cX && P->item.objeto.cY == o.cY && P->item.objeto.bX == o.bX && P->item.objeto.cY == o.cY )
			return P;
		P = P->prox;
	}
	return P;


}


