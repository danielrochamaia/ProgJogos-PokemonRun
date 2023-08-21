/**********************************************************************************
// Block (Arquivo de Cabe�alho)
//
// Cria��o:     22 Dez 2012
// Atualiza��o: 01 Dez 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Bloco do jogo Breakout
//
**********************************************************************************/

#ifndef _PLATAFORMA_ANIMADA_H_
#define _PLATAFORMA_ANIMADA_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"              // tipos espec�ficos da engine
#include "Object.h"             // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ---------------------------------------------------------------------------------

class PlataformaAnimada : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // anima��o do personagem


public:
    float velX;                 // velocidade horizontal
    float velY;                 // velocidade vertical
    float vel;

    PlataformaAnimada(TileSet* tile, float speed, uint tipo);         // construtor
    ~PlataformaAnimada();                   // destrutor


    //void OnCollision(Object* obj);     // resolu��o da colis�o
    void Update();              // atualiza��o do objeto
    void Draw();                // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void PlataformaAnimada::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif