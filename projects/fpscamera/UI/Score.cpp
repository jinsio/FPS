#include "Score.h"
using namespace My3dApp;

namespace My3dApp{

    int Score::mScore=0;
    bool Score::GameClearFlag = false;
    Score* Score::mpInstance = nullptr;
   
    Score::Score()
    {

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

    bool Score::GetGameClearFlag()
    {
        return GameClearFlag;
    }

    void Score::SetGameClearFlag(bool tmp)
    {
        GameClearFlag=tmp;
    }

}