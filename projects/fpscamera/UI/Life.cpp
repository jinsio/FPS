#include "Life.h"
using namespace My3dApp;

namespace My3dApp
{
	int Life::mLife = STARTLIFE;
	Life* Life::mpInstance = nullptr;

	Life::Life() 
	{
		mpInstance = nullptr;
	}

	Life::~Life()
	{
		delete mpInstance;
	}

	void Life::Initialize()
	{
		mpInstance = new Life;
	}

	void Life::LifeAdd()
	{
		mLife++;
	}

	void Life::LifeSub()
	{
		mLife--;
	}

	int Life::GetLife()
	{
		return mLife;
	}
}