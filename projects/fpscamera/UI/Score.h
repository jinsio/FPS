#pragma once


namespace My3dApp
{
class Score final
{
public:
    static void Initialize();
    static void ScoreAdd();
    static int GetScore();

private:  
    Score();
    ~Score();
    static Score* mpInstance;
    static int mScore;
};
}
