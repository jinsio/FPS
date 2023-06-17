#include "Score.h"
using namespace My3dApp;

namespace My3dApp{

    int Score::mScore=0;
    Score* Score::mpInstance = nullptr;
   
    Score::Score()
    {
        mpInstance = nullptr;
    }
    Score::~Score()
    {
        delete mpInstance;
    }

    void Score::Initialize()
    {
        mpInstance = new Score;
    }
    void Score::ScoreAdd()
    {
        mScore++;
    }

    int Score::GetScore()
    {
        return mScore;
    }

}