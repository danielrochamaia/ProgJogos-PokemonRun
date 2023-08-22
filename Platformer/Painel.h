#ifndef _PANEL_H_
#define _PANEL_H_

#include "Animation.h"
#include "Object.h"
#include <iomanip>
#include <sstream>
#include <string>
using std::setfill;
using std::setw;
using std::string;
using std::stringstream;
using std::to_string;

class Painel : public Object
{
private:

    TileSet* numbers = nullptr;
    Animation* anim = nullptr;
    float time = 0.0f;
    uint score = 300;
    string scoreTxt = "300";

public:
    Painel();
    ~Painel();

    void AddScore(uint s);
    uint Score();

    void Update();
    void Draw();
};

#endif
