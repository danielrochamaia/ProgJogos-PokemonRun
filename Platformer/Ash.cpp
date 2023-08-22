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

#include "Ash.h"
#include "PokemonRun.h"
#include "Level1.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

Ash::Ash(Image* img, float speed, uint tipo)
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

Ash::~Ash()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Ash::Update()
{
}

// ---------------------------------------------------------------------------------