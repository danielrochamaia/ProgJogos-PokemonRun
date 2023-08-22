#include "Painel.h"

Painel::Painel()
{
    numbers = new TileSet("Resources/numbers.png", 24, 32, 5, 10);
    anim = new Animation[9]{
        Animation(numbers, 0.0f, false), Animation(numbers, 0.0f, false), Animation(numbers, 0.0f, false),
        Animation(numbers, 0.0f, false), Animation(numbers, 0.0f, false), Animation(numbers, 0.0f, false),
        Animation(numbers, 0.0f, false), Animation(numbers, 0.0f, false), Animation(numbers, 0.0f, false),
    };
}


Painel::~Painel()
{
    delete[] anim;
    delete numbers;
}

uint Painel::Score() {
    return score;
}

void Painel::Update()
{
    time += gameTime;
    if (time > 1) {
        AddScore(1);
        time = 0.0f;
    }
}

void Painel::Draw()
{
    for (int i = 0; i < scoreTxt.length(); ++i)
        anim[i].Draw(scoreTxt.at(i) - '0', 35.0f + (24.0f * i), 58.0f, 0.0001f);
}

void Painel::AddScore(uint s)
{
    score -= s;
    scoreTxt = (stringstream() << setw(3) << setfill('0') << to_string(score)).str();
}
