/**********************************************************************************
// Level1 (Código Fonte)
//
// Criação:     18 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível 1 do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Player.h"
#include "Plataforma.h"
#include "PlataformaAnimada.h"
#include "PokemonRun.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // cria background
    backg = new Sprite("Resources/back.png");

    // cria jogador
    Player* player = new Player();
    scene->Add(player, MOVING);

    whiscashSmall = new Image("Resources/whiscashSmall.png");
    whiscashBig = new Image("Resources/whiscashBig.png");
    wailmer = new Image("Resources/wailmerInvertida.png");
    lotadSmall = new Image("Resources/lotadSmallInvertido.png");
    lotadBig = new Image("Resources/lotadBig.png");



    //cria plataformas
    Plataforma* plataforma;
    PlataformaAnimada* plataformaAnimada;

    //rio
    plataforma = new Plataforma(new Image("Resources/rio.png"), 0, INIMIGO);
    plataforma->MoveTo(480, 200, Layer::BACK);
    plataforma->BBox(new Rect(-475, -100, 475, 100));
    scene->Add(plataforma, STATIC);

    //quinta faixa
    plataforma = new Plataforma(lotadSmall, -200, AMIGAVEL);
    plataforma->MoveTo(150, 115);
    plataforma->BBox(new Rect(-65, -15, 65, 15));
    scene->Add(plataforma, MOVING);

    plataforma = new Plataforma(lotadSmall, -200, AMIGAVEL);
    plataforma->MoveTo(550, 115);
    plataforma->BBox(new Rect(-65, -15, 65, 15));
    scene->Add(plataforma, MOVING);

    //quarta faixa
    plataforma = new Plataforma(whiscashBig, 150, AMIGAVEL);
    plataforma->MoveTo(480, 155);
    plataforma->BBox(new Rect(-85, -16, 85, 16));
    scene->Add(plataforma, MOVING);

    plataforma = new Plataforma(whiscashBig, 150, AMIGAVEL);
    plataforma->MoveTo(1080, 155);
    plataforma->BBox(new Rect(-85, -16, 85, 16));
    scene->Add(plataforma, MOVING);

    //terceira faixa
    plataforma = new Plataforma(wailmer, -250, AMIGAVEL);
    plataforma->MoveTo(200, 195);
    plataforma->BBox(new Rect(-75, -16, 75, 16));
    scene->Add(plataforma, MOVING);

    plataforma = new Plataforma(wailmer, -250, AMIGAVEL);
    plataforma->MoveTo(700, 195);
    plataforma->BBox(new Rect(-75, -16, 75, 16));
    scene->Add(plataforma, MOVING);

    //segunda faixa
    plataforma = new Plataforma(whiscashSmall, 300, AMIGAVEL);
    plataforma->MoveTo(350, 235);
    plataforma->BBox(new Rect(-65, -20, 65, 20));
    scene->Add(plataforma, MOVING);

    plataforma = new Plataforma(whiscashSmall, 300, AMIGAVEL);
    plataforma->MoveTo(850, 235);
    plataforma->BBox(new Rect(-65, -20, 65, 20));
    scene->Add(plataforma, MOVING);

    plataforma = new Plataforma(whiscashSmall, 300, AMIGAVEL);
    plataforma->MoveTo(1250, 235);
    plataforma->BBox(new Rect(-65, -20, 65, 20));
    scene->Add(plataforma, MOVING);

    //primeira faixa
    
    plataforma = new Plataforma(lotadBig, 250, AMIGAVEL);
    plataforma->MoveTo(150, 280);
    plataforma->BBox(new Rect(-85, -19, 85, 19));
    scene->Add(plataforma, MOVING);

    plataforma = new Plataforma(lotadBig, 250, AMIGAVEL);
    plataforma->MoveTo(450, 280);
    plataforma->BBox(new Rect(-85, -19, 85, 19));
    scene->Add(plataforma, MOVING);

    plataforma = new Plataforma(lotadBig, 250, AMIGAVEL);
    plataforma->MoveTo(750, 280);
    plataforma->BBox(new Rect(-85, -19, 85, 19));
    scene->Add(plataforma, MOVING);

    plataforma = new Plataforma(lotadBig, 250, AMIGAVEL);
    plataforma->MoveTo(1050, 280);
    plataforma->BBox(new Rect(-85, -19, 85, 19));
    scene->Add(plataforma, MOVING);

    // ---------------------------
    // obstáculos da pista
    // 

    //quarta faixa
    plataformaAnimada = new PlataformaAnimada(new TileSet("Resources/wobbuffet-andando.png", 57, 50, 5, 4), -350, INIMIGO);
    plataformaAnimada->MoveTo(50, 380);
    plataformaAnimada->BBox(new Rect(-25, -24, 25, 24));
    scene->Add(plataformaAnimada, MOVING);

    plataformaAnimada = new PlataformaAnimada(new TileSet("Resources/wobbuffet-andando.png", 57, 50, 5, 4), -350, INIMIGO);
    plataformaAnimada->MoveTo(561, 380);
    plataformaAnimada->BBox(new Rect(-25, -24, 25, 24));
    scene->Add(plataformaAnimada, MOVING);
   
    //terceira faixa
    plataformaAnimada = new PlataformaAnimada(new TileSet("Resources/moltres-andando.png", 63, 63, 5, 4), 350, INIMIGO);
    plataformaAnimada->MoveTo(200, 450);
    plataformaAnimada->BBox(new Rect(-25, -24, 25, 24));
    scene->Add(plataformaAnimada, MOVING);

    plataformaAnimada = new PlataformaAnimada(new TileSet("Resources/moltres-andando.png", 63, 63, 5, 4), 350, INIMIGO);
    plataformaAnimada->MoveTo(600, 450);
    plataformaAnimada->BBox(new Rect(-25, -24, 25, 24));
    scene->Add(plataformaAnimada, MOVING);

    //segunda faixa
    plataformaAnimada = new PlataformaAnimada(new TileSet("Resources/weezing-andando.png", 63, 63, 5, 4), 350, INIMIGO);
    plataformaAnimada->MoveTo(400, 530);
    plataformaAnimada->BBox(new Rect(-25, -24, 25, 24));
    scene->Add(plataformaAnimada, MOVING);

    plataformaAnimada = new PlataformaAnimada(new TileSet("Resources/weezing-andando.png", 63, 63, 5, 4), 350, INIMIGO);
    plataformaAnimada->MoveTo(50, 530);
    plataformaAnimada->BBox(new Rect(-25, -24, 25, 24));
    scene->Add(plataformaAnimada, MOVING);

    plataformaAnimada = new PlataformaAnimada(new TileSet("Resources/weezing-andando.png", 63, 63, 5, 4), 350, INIMIGO);
    plataformaAnimada->MoveTo(700, 530);
    plataformaAnimada->BBox(new Rect(-25, -24, 25, 24));
    scene->Add(plataformaAnimada, MOVING);

    //primeira faixa
    plataformaAnimada = new PlataformaAnimada(new TileSet("Resources/garbodor-andando.png", 60, 60, 5, 4), 350, INIMIGO);
    plataformaAnimada->MoveTo(760, 600);
    plataformaAnimada->BBox(new Rect(-25, -24, 25, 24));
    scene->Add(plataformaAnimada, MOVING);

    plataformaAnimada = new PlataformaAnimada(new TileSet("Resources/garbodor-andando.png", 60, 60, 5, 4), 350, INIMIGO);
    plataformaAnimada->MoveTo(300, 600);
    plataformaAnimada->BBox(new Rect(-25, -24, 25, 24));
    scene->Add(plataformaAnimada, MOVING);
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete backg;
    delete scene;
    delete whiscashSmall;
    delete wailmer;
    delete lotadSmall;
    delete lotadBig;
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    // habilita/desabilita bounding box
    if (window->KeyPress('B'))
    {
        viewBBox = !viewBBox;
    }

    if (window->KeyPress(VK_ESCAPE))
    {
        // volta para a tela de abertura
        Engine::Next<Home>();
    }
    else if (window->KeyPress('N'))
    {
        // passa manualmente para o próximo nível
        Engine::Next<Home>();
    }
    else
    {
        // atualiza cena
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    // desenha cena
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();

    // desenha bounding box dos objetos
    if (viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------