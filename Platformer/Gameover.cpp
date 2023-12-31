#include "GameOver.h"
#include "Level1.h"
#include "Home.h"

string GameOver::score = "";

void GameOver::Init()
{
    bg = new Sprite("Resources/gameOver.png");
    scoreimg = new Sprite("Resources/score.png");
    tileset = new TileSet("Resources/numbers.png", 24, 32, 5, 10);
    anim = new Animation * [score.length()];

    for (uint i = 0; i < score.length(); i++)
    {
        anim[i] = new Animation(tileset, 0.0f, false);
    }
}

void GameOver::Finalize()
{
    delete bg;
    delete tileset;
    delete[] anim;
    delete scoreimg;
}

void GameOver::Update()
{
    if (window->KeyDown(VK_RETURN))
        return Engine::Next<Level1>();

    if (window->KeyDown(VK_SPACE))
        return Engine::Next<Home>();
}

void GameOver::Draw()
{
    bg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scoreimg->Draw(window->Width() * 0.81f, window->CenterY() - 80.0f);
    for (int i = 0; i < score.length(); ++i)
        anim[i]->Draw(score.at(i) - '0', window->Width() * 0.79f + (24.0f * i), window->CenterY() - 40.0f, Layer::FRONT);
}
