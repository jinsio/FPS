#include "PlayerBullet.h"


#pragma warning(disable:4996)

using namespace My3dApp;

// @brief PlayerBullet コンストラクタ プレイヤーの位置・方向から弾を作成・モデル読み込み
My3dApp::PlayerBullet::PlayerBullet(PlayerGun*playergun)
	:GameObject(ObjectTag::PlayerBullet)
	,mAnimControl(nullptr)
{
	// モデル読み込み
	mModelHandle = AssetManager::GetMesh("data/model/beam/beam.mv1");
	MV1SetScale(mModelHandle, VGet(0.1f, 0.1f, 0.1f));

	// プレイヤーの位置・方向を取得し初期化
	mSpeed = 5.0f;
	GameObject* Cameraptr = GameObjectManager::GetFirstGameObject(ObjectTag::Camera);
	GameObject* PlayerGunptr = GameObjectManager::GetFirstGameObject(ObjectTag::PlayerGun);
	mPosition = PlayerGunptr->GetPosition();
	//mPosition.y = 125;			//弾の高さ調節
	mDir = Cameraptr->GetDir();

	// プレイヤー弾の回転
	MV1SetRotationZYAxis(mModelHandle, mDir, VGet(0.0f, 1.0f, 0.0f), 0.0f);
	MV1SetPosition(mModelHandle, mPosition);

	// 当たり判定球を設定
	mCollisionSphere.mLocalCenter = VGet(0, 0, 0);
	mCollisionSphere.mRadius = 50.0f;
	mCollisionSphere.mWorldCenter = mPosition;
}

// @brief PlayerBulletデストラクタ。モデルの削除はベースクラスで行う
My3dApp::PlayerBullet::~PlayerBullet()
{
}

// @brief Update フレームごとの更新処理
void My3dApp::PlayerBullet::Update(float deltaTime)
{
	mPosition += mDir * deltaTime * mSpeed*1000;
	MV1SetPosition(mModelHandle, mPosition);

	CollisionUpdate();
}

// @brief 描画
void My3dApp::PlayerBullet::Draw()
{
	MV1DrawModel(mModelHandle);
	MV1SetScale(mModelHandle, VGet(0.1, 0.1, 0.1));

	// 当たり判定デバッグ描画（後で消す）
	//DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius,8, GetColor(0, 255, 0), 0, FALSE);
	
	//DrawString(100, 100, mCoord, GetColor(255, 255, 255));
}

void My3dApp::PlayerBullet::Coordinate()
{
	//sprintf(mCoord," X : %f, Y : %f, Z : %f",mPosition.x,mPosition.y,mPosition.z);
}

//-----------------------------------------------------------------------------
// @brief     プレイヤーが他のオブジェクトと当たった時の処理
// @other[in] GameObject* このクラスと他のゲームオブジェクト(other)が衝突したときの処理を行う
// @detail    プレイヤーのめり込み戻しなどのリアクション処理を記述する
//-----------------------------------------------------------------------------

void My3dApp::PlayerBullet::OnCollisionEnter( GameObject* other)
{
	ObjectTag tag = other->GetTag();

	//敵との衝突
	if (tag == ObjectTag::Enemy)
	{
		//プレイヤーの弾と敵の当たり判定
		if (CollisionPair(mCollisionSphere, other->GetCollisionSphere()))
		{
			mAlive = FALSE;
		}
	}
}


