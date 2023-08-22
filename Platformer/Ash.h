/**********************************************************************************
// ASH (Arquivo de Cabeçalho)
//
// Criação:     22 Dez 2012
// Atualização: 01 Dez 2022
// Compilador:  Visual C++ 2022
//
// Descrição:   Bloco do jogo Pokemon Run
//
**********************************************************************************/

#ifndef _POKEMONRUN_ASH_H_
#define _POKEMONRUN_ASH_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"              // tipos específicos da engine
#include "Object.h"             // interface de Object
#include "Sprite.h"             // interface de Sprites

// ---------------------------------------------------------------------------------

class Ash : public Object
{
private:
    Sprite* sprite;            // sprite do bloco


public:
    float velX;                 // velocidade horizontal
    float velY;                 // velocidade vertical
    float vel;

    Ash(Image* img, float speed, uint tipo);         // construtor
    ~Ash();                   // destrutor


    //void OnCollision(Object* obj);     // resolução da colisão
    void Update();              // atualização do objeto
    void Draw();                // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Ash::Draw()
{
    sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif