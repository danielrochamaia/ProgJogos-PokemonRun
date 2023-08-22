/**********************************************************************************
// Player (Código Fonte)
//
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo PacMan
//
**********************************************************************************/

#include "PokemonRun.h"
#include "Player.h"
#include "Plataforma.h"
#include "Engine.h"
#include "Home.h"
#include "Level1.h"


// ---------------------------------------------------------------------------------

Player::Player()
{
    spriteL = new Sprite("Resources/pikaxu-esq.png");
    spriteR = new Sprite("Resources/pikaxu-dir.png");
    spriteU = new Sprite("Resources/pikaxu-frente.png");
    spriteD = new Sprite("Resources/pikaxu-baixo.png");
    ctrlUp = true;
    ctrlDown = true;
    ctrlLeft = true;
    ctrlRight = true;
    status = false;

    // imagem do pacman é 48x48 (com borda transparente de 4 pixels)
    BBox(new Rect(-15, -15, 15, 15));
    MoveTo(480.0f, 651.0f);
    type = PLAYER;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete spriteL;
    delete spriteR;
    delete spriteU;
    delete spriteD;
}

// ---------------------------------------------------------------------------------

void Player::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::Up()
{
    velX = 0;
    velY = -200.0f;
}

// ---------------------------------------------------------------------------------

void Player::Down()
{
    velX = 0;
    velY = 200.0f;
}

// ---------------------------------------------------------------------------------

void Player::Left()
{
    velX = -200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::Right()
{
    velX = 200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------
void Player::OnCollision(Object* obj)
{
    Plataforma* plataforma = (Plataforma*)obj;

    // bola colidiu com o player
    if (obj->Type() == AMIGAVEL)
    {
        
        // objeto caminha no eixo x
        Translate(-plataforma->vel * gameTime, 0.0f);
        referencia = -plataforma->vel;

    }

    if(obj->Type() == INIMIGO)
    {
        if (referencia == 0) {
            MoveTo(480.0f, 650.0f);
        }

        referencia = 0;
    }

    if (obj->Type() == ASH && currState == LEFT)
    {
            Level1::gameover = true;
    }

}

// ---------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------

void Player::Update()
{
    // desloca sapo para cima
    if (ctrlUp && window->KeyDown(VK_UP))
    {
        Translate(0.0f, -passo);
        ctrlUp = false;
        currState = UP;
    }
    else if (window->KeyUp(VK_UP))
    {
        ctrlUp = true;
    }

    // desloca sapo para baixo
    if (ctrlDown && window->KeyDown(VK_DOWN))
    {
        Translate(0.0f, passo);
        ctrlDown = false;
        currState = DOWN;
    }
    else if (window->KeyUp(VK_DOWN))
    {
        ctrlDown = true;
    }

    if (ctrlLeft && window->KeyDown(VK_LEFT))
    {
        Translate(-passo, 0.0f);
        ctrlLeft = false;
        currState = LEFT;
    }
    else if (window->KeyUp(VK_LEFT))
    {
        ctrlLeft = true;
    }

    if (ctrlRight && window->KeyDown(VK_RIGHT))
    {
        Translate(passo, 0.0f);
        ctrlRight = false;
        currState = RIGHT;
    }
    else if (window->KeyUp(VK_RIGHT))
    {
        ctrlRight = true;
    }

     //mantém sapo dentro da tela
    //Parte de cima
// maintain mc on the screen
    if (x + spriteR->Width() / 2.0f > window->Width())
        MoveTo(window->Width() - spriteR->Width() / 2.0f, y);

    if (x - spriteL->Width() / 2.0f < 0)
        MoveTo(spriteL->Width() / 2.0f, y);

    if (y + spriteD->Width() / 2.0f > window->Height())
        MoveTo(x, window->Height() - spriteD->Height() / 2.0f);

    if (y - spriteU->Height() / 2.0f < 10)
        MoveTo(x, spriteU->Height() / 2.0f + 10);
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
    switch (currState)
    {
    case LEFT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGHT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UP:    spriteU->Draw(x, y, Layer::UPPER); break;
    case DOWN:  spriteD->Draw(x, y, Layer::UPPER); break;
    default:
        switch (nextState)
        {
        case LEFT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGHT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UP:    spriteU->Draw(x, y, Layer::UPPER); break;
        case DOWN:  spriteD->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}

// ---------------------------------------------------------------------------------