#pragma once
const int STARTLIFE = 3;	//‰ŠúHP
namespace My3dApp
{
	class Life final
	{
	public:
		static void Initialize();
		static void LifeAdd();
		static void LifeSub();
		static int  GetLife();

	private:
		Life();
		~Life();
		static Life* mpInstance;
		static int mLife;
	};
}
	