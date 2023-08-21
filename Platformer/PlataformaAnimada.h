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

#ifndef _PLATAFORMA_ANIMADA_H_
#define _PLATAFORMA_ANIMADA_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"              // tipos específicos da engine
#include "Object.h"             // interface de Object
#include "Animation.h"                  // animação de sprites

// ---------------------------------------------------------------------------------

class PlataformaAnimada : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // animação do personagem


public:
    float velX;                 // velocidade horizontal
    float velY;                 // velocidade vertical
    float vel;

    PlataformaAnimada(TileSet* tile, float speed, uint tipo);         // construtor
    ~PlataformaAnimada();                   // destrutor


    //void OnCollision(Object* obj);     // resolução da colisão
    void Update();              // atualização do objeto
    void Draw();                // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void PlataformaAnimada::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif