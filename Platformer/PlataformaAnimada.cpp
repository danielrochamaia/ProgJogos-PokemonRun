/**********************************************************************************
// Block (Arquivo de Cabeçalho)
//
// Criação:     22 Dez 2012
// Atualização: 01 Dez 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Bloco do jogo Breakout
//
**********************************************************************************/

#include "PlataformaAnimada.h"
#include "PokemonRun.h"
#include "Level1.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

PlataformaAnimada::PlataformaAnimada(TileSet * tile, float speed, uint tipo)
{
    // tamanho do bloco é 60x24
    /*BBox(new Rect(-30, -12, 29, 11));*/

    // sprite do bloco
    tileset = tile;
    anim = new Animation(tileset, 0.090f, true);

    uint normal[4] = { 1, 2, 3, 4 };
    anim->Add(0,normal, 4);


    // velocidades iniciais
    vel = speed;
    velX = 0.0f;
    velY = 0.0f;

    // tipo do objeto
    type = tipo;
}

// ---------------------------------------------------------------------------------

PlataformaAnimada::~PlataformaAnimada()
{
    delete tileset;
    delete anim;
}

// ---------------------------------------------------------------------------------

void PlataformaAnimada::Update()
{
    anim->NextFrame();
    anim->Select(0);
    Translate(-vel * gameTime,0);

    // passa objeto de um lado da tela para o outro
    if (int(x) < 0)
        MoveTo(float(window->Width()), y);

    if (int(x) > window->Width())
        MoveTo(0, y);

    //if (vel < 0 && int(x) + tileset->Width() > window->Width() + tileset->Width()) {
    //    MoveTo(float(tileset->Width()), y);
    //}

    //// destrói ao sair da janela
    //if (y > window->Height())
    //    Level1::scene->Delete();
}

// ---------------------------------------------------------------------------------
