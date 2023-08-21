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

#include "Plataforma.h"
#include "PokemonRun.h"
#include "Level1.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

Plataforma::Plataforma(Image* img, float speed, uint tipo)
{
    // tamanho do bloco é 60x24
    /*BBox(new Rect(-30, -12, 29, 11));*/

    // sprite do bloco
    sprite = new Sprite(img);

    // velocidades iniciais
    vel = speed;
    velX = 0.0f;
    velY = 0.0f;

    // tipo do objeto
    type = tipo;
}

// ---------------------------------------------------------------------------------

Plataforma::~Plataforma()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Plataforma::Update()
{
    // objeto caminha no eixo x
    Translate(-vel * gameTime, 0.0f);

    // passa objeto de um lado da tela para o outro
    if (int(x) + sprite->Width() < 0)
        MoveTo(float(window->Width() + sprite->Width()), y);

    if (vel < 0 && int(x) + sprite->Width() > window->Width() + sprite->Width()) {
        MoveTo(float(-sprite->Width()), y);
    }

    //// destrói ao sair da janela
    //if (y > window->Height())
    //    Level1::scene->Delete();
}

// ---------------------------------------------------------------------------------
