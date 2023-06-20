#pragma once


namespace My3dApp
{
class Score final
{
public:
    static void Initialize();
    static void ScoreAdd();
    static int GetScore();
    static bool GetGameClearFlag();
    static void SetGameClearFlag(bool tmp);

private:  
    Score();
    ~Score();
    static Score* mpInstance;
    static int mScore;
    static bool GameClearFlag;
};
}
