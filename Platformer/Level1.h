/**********************************************************************************
// Level1 (Arquivo de Cabe�alho)
//
// Cria��o:     18 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   N�vel 1 do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_LEVEl1_H_
#define _PACMAN_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "PlataformaAnimada.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
    Sprite* backg = nullptr;       // background
   
    bool viewScene = true;              // visualiza sprites da cena
    bool viewBBox = true;             // visualiza bounding box

    Image* whiscashSmall = nullptr;                // pequeno tronco de madeira
    Image* whiscashBig = nullptr;                // pequeno tronco de madeira
    Image* wailmer = nullptr;                // grande tronco de madeira
    Image* lotadSmall = nullptr;                // pequena fila de tartarugas
    Image* lotadBig = nullptr;               // grande fila de tartarugas

public:
    Scene* scene = nullptr;        // gerenciador de cena
    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------

#endif