#include "Map.h"
#include "../ObjectTag.h"
#include "../../Animation/AssetManager.h"

namespace My3dApp
{
	//----------------------------------------------------------------------
	// @brief BackGroundクラスコンストラクタ。モデルを読み込む
	//----------------------------------------------------------------------
	My3dApp::Map::Map()
		: GameObject(My3dApp::ObjectTag::Map)
	{
		ModelLoad();
	}
	//----------------------------------------------------------------------
	// @brief BackGroundクラスコンストラクタ。モデルを読み込む
	// @param[in] pos 背景のワールド配置位置
	//----------------------------------------------------------------------
	Map::Map(VECTOR pos)
		: GameObject(My3dApp::ObjectTag::Map, pos)
	{
		ModelLoad();
	}

	//----------------------------------------------------------------------
	// @brief BackGroundクラスデストラクタ
	//----------------------------------------------------------------------
	Map::~Map()
	{
		AssetManager::ReleaseMesh(mModelHandle);
	}

	//----------------------------------------------------------------------
	// @brief 背景モデル読み込み
	//----------------------------------------------------------------------
	void Map::ModelLoad()
	{
		// 表示モデル読み込み＆スケーリング＆位置セット
		mModelHandle = AssetManager::GetMesh("data/model/map/___map.mv1");
		MV1SetScale(mModelHandle, VGet(2.0f, 2.0f, 2.0f));
		mPosition.x = -450;
		MV1SetPosition(mModelHandle, mPosition);

		//// 当たり判定モデル読み込み＆スケーリング＆当たり判定情報構築
		//mCollisionModel = AssetManager::GetMesh("data/model/map/HitMesh2rot.mv1");
		//MV1SetScale(mCollisionModel, VGet(1.0f, 1.0f, 1.0f));
		//MV1SetOpacityRate(mCollisionModel, 0.3f);

		// 表示モデルと当たり判定モデルの位置を微調整
		MV1SetPosition(mCollisionModel, mPosition + VGet(-45, 200, -35));

		MV1SetupCollInfo(mCollisionModel);

	}
	//----------------------------------------------------------------------
	// @brief 背景のアップデート処理。背景は動かないので何もしない.
	// @param[in] deltaTime １フレームの経過時間.
	//----------------------------------------------------------------------
	void Map::Update(float deltaTime)
	{
	}

	//----------------------------------------------------------------------
	// @brief 背景の描画処理.
	//----------------------------------------------------------------------
	void Map::Draw()
	{
		MV1DrawModel(mModelHandle);
		//DrawCollider();
	}

}// namespace My3dApp