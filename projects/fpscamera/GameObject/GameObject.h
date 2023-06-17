#pragma once
#include "DxLib.h"
#include "ObjectTag.h"
#include "../math/math3D.h"
#include "../Collision/Collision.h"
#include "../Collision/CollisionType.h"
#include "../Animation/AssetManager.h"

namespace My3dApp
{
	class GameObject
	{
	public:
		              GameObject(ObjectTag tag);
					  GameObject(ObjectTag tag, VECTOR pos);                                 // ゲームオブジェクトコンストラクタ

					  virtual      ~GameObject();
		

		const         VECTOR& GetPosition() const { return mPosition; }                  // 位置取得 
		void          SetPosition(const VECTOR set) { mPosition = set; }                 // 位置セット

		const         VECTOR& GetDir() const { return mDir; }                  // 向き取得
		void          SetDir(const VECTOR dir) { mDir = dir; }                 // 向きセット
		
		bool          GetVisible() const { return mVisible; }                  // 可視状態の取得 
		void          SetVisible(bool visible) { mVisible = visible; }         // 可視状態のセット

		bool          GetAlive() { return mAlive; }
		void          SetAlive(bool alive) { mAlive = alive; }                 // ゲームオブジェクト生死セット

		float         GetYaw(){ return mYaw; }                  // 向き取得
		void          SetYaw(const float Yaw) { mYaw = Yaw; }                 // 向きセット
		
		float         GetPitch(){ return mPitch; }                  // 向き取得
		void          SetPitch(const float Pitch) { mPitch = Pitch; }                 // 向きセット

		void          SetAnimTypeId(int a) { mAnimTypeId = a; }
		int           GetAnimTypeID() { return mAnimTypeId; }

		ObjectTag     GetTag()const { return mTag; }                                // タグ種類を返す


		virtual void  Update(float deltaTime) = 0;
		virtual void  Draw();

		// 当たり判定関連												        
		virtual void  OnCollisionEnter(GameObject * other) {}              // 他のオブジェクトとぶつかったときのリアクション（あれば）
		virtual void  Collision(GameObject* other) {};                         // このオブジェクトとの当たり判定

		//デバッグ用座標表示
		virtual void  Coordinate();

		CollisionType GetCollisionType() const { return mCollisionType; }    // このオブジェクトが持っている当たり判定種を取得
		Sphere        GetCollisionSphere() const { return mCollisionSphere; }  // 当たり判定球を返却（持っていれば）
		int           GetCollisionModel() const { return mCollisionModel; }   // 当たり判定モデルを返却（持っていれば)

	protected:
		ObjectTag mTag         ; // オブジェクト種類
		VECTOR    mPosition    ; // ワールド位置
		VECTOR    mDir         ; // ワールド向き   
		int       mModelHandle ; // モデルID
		float	  mYaw         ; // 水平方向回転角
		float     mPitch       ; // 垂直方向回転角
		float     mCoolTime    ;
		char      mCoord[256]  ; // 座標確認用文字列
		int       mAnimTypeId  ; // アニメーションID
		bool	  mVisible     ; // 可視状態
		bool      mAlive       ; // 生死状態

		// 当たり判定関連
		CollisionType mCollisionType;                              // 当たり判定タイプ
		Sphere        mCollisionSphere;                            // 当たり判定球
		int           mCollisionModel;                             // 当たり判定用モデル（表示モデルと別に簡易当たり判定モデルをセット）

		void		  CollisionUpdate();						   //当たり判定の更新
	};
}


