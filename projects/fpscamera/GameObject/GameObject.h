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
					  GameObject(ObjectTag tag, VECTOR pos);                                 // �Q�[���I�u�W�F�N�g�R���X�g���N�^

					  virtual      ~GameObject();
		

		const         VECTOR& GetPosition() const { return mPosition; }                  // �ʒu�擾 
		void          SetPosition(const VECTOR set) { mPosition = set; }                 // �ʒu�Z�b�g

		const         VECTOR& GetDir() const { return mDir; }                  // �����擾
		void          SetDir(const VECTOR dir) { mDir = dir; }                 // �����Z�b�g
		
		bool          GetVisible() const { return mVisible; }                  // ����Ԃ̎擾 
		void          SetVisible(bool visible) { mVisible = visible; }         // ����Ԃ̃Z�b�g

		bool          GetAlive() { return mAlive; }
		void          SetAlive(bool alive) { mAlive = alive; }                 // �Q�[���I�u�W�F�N�g�����Z�b�g

		float         GetYaw(){ return mYaw; }                  // �����擾
		void          SetYaw(const float Yaw) { mYaw = Yaw; }                 // �����Z�b�g
		
		float         GetPitch(){ return mPitch; }                  // �����擾
		void          SetPitch(const float Pitch) { mPitch = Pitch; }                 // �����Z�b�g

		void          SetAnimTypeId(int a) { mAnimTypeId = a; }
		int           GetAnimTypeID() { return mAnimTypeId; }

		ObjectTag     GetTag()const { return mTag; }                                // �^�O��ނ�Ԃ�


		virtual void  Update(float deltaTime) = 0;
		virtual void  Draw();

		// �����蔻��֘A												        
		virtual void  OnCollisionEnter(GameObject * other) {}              // ���̃I�u�W�F�N�g�ƂԂ������Ƃ��̃��A�N�V�����i����΁j
		virtual void  Collision(GameObject* other) {};                         // ���̃I�u�W�F�N�g�Ƃ̓����蔻��

		//�f�o�b�O�p���W�\��
		virtual void  Coordinate();

		CollisionType GetCollisionType() const { return mCollisionType; }    // ���̃I�u�W�F�N�g�������Ă��铖���蔻�����擾
		Sphere        GetCollisionSphere() const { return mCollisionSphere; }  // �����蔻�苅��ԋp�i�����Ă���΁j
		int           GetCollisionModel() const { return mCollisionModel; }   // �����蔻�胂�f����ԋp�i�����Ă����)

	protected:
		ObjectTag mTag         ; // �I�u�W�F�N�g���
		VECTOR    mPosition    ; // ���[���h�ʒu
		VECTOR    mDir         ; // ���[���h����   
		int       mModelHandle ; // ���f��ID
		float	  mYaw         ; // ����������]�p
		float     mPitch       ; // ����������]�p
		float     mCoolTime    ;
		char      mCoord[256]  ; // ���W�m�F�p������
		int       mAnimTypeId  ; // �A�j���[�V����ID
		bool	  mVisible     ; // �����
		bool      mAlive       ; // �������

		// �����蔻��֘A
		CollisionType mCollisionType;                              // �����蔻��^�C�v
		Sphere        mCollisionSphere;                            // �����蔻�苅
		int           mCollisionModel;                             // �����蔻��p���f���i�\�����f���ƕʂɊȈՓ����蔻�胂�f�����Z�b�g�j

		void		  CollisionUpdate();						   //�����蔻��̍X�V
	};
}


