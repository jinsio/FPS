//-----------------------------------------------------------------------------
// @brief  メイン処理.
//-----------------------------------------------------------------------------

#include "DxLib.h"
#include "Scene/SceneManager.h"
#include "UI/TimeManager.h"

#pragma warning(disable:4996)

//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(TRUE);

	// 画面モードのセット
	SetGraphMode(1920, 1080, 16);
	SetBackgroundColor(200, 255, 255);

	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(1.0f, 2000.0f);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;	// エラーが起きたら直ちに終了
	}

	My3dApp::SceneManager* sceneManager = new My3dApp::SceneManager();


		//シーンループ//
		while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)		//ウィンドウが閉じられるか、ESCキーが押されるまで実行
		{
			sceneManager->Update();			//更新処理
			ClearDrawScreen();				//画面を初期化

			sceneManager->Draw();			//描画処理
			ScreenFlip();					//裏画面の内容を表描画に反映
		}


	// ＤＸライブラリの後始末
	DxLib_End();
	// ソフトの終了
	return 0;
}