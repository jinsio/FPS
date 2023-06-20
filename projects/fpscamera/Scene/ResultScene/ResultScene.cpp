#include "DxLib.h"
#include "../TitleScene/TitleScene.h"
#include "ResultScene.h"
#include <stdlib.h>
using namespace My3dApp;

namespace My3dApp
{
    ResultScene::ResultScene()
    {
        MovieHandle = LoadGraph("data/Movie/hanahubuki.ogv");
        TextHandle = LoadGraph("data/Movie/gameclear.png");
        //MovieHandle = PlayMovie("data/Movie/hanahubuki.ogv", 1, DX_MOVIEPLAYTYPE_BCANCEL);
        graph = MakeScreen(1920,1080,TRUE);

        PlayMovieToGraph(MovieHandle, DX_PLAYTYPE_BACK);
    }
    ResultScene::~ResultScene()
    {
    }
    SceneBase* ResultScene::Update(float deltaTime)
    {
        GraphFilterBlt(MovieHandle, graph, DX_GRAPH_FILTER_REPLACEMENT, 0, 0, 0, 255, 0, 0, 0, 0);
        SetDrawScreen(DX_SCREEN_BACK);
        if (CheckHitKey(KEY_INPUT_T))
        {
            return new TitleScene();
        }
        return this;
    }
    void ResultScene::Draw()
    {
        DrawGraph(0, 0, TextHandle, TRUE);
        DrawGraph(0, 0, graph, TRUE);

        //printfDx("%d",MovieHandle,TRUE);
        //GetDrawScreenGraph(0, 0, 1920, 1080, graph);  // ゲーム画面を保存する（第三引数と第四引数はゲーム画面の大きさ）
        //DrawFormatString(0, 0, GetColor(255, 255, 255), "Result画面:TでTitleシーンへ移行");
        //DrawGraph(0, 0, graph, true);
    }
}