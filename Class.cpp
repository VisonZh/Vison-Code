#include <iostream>
using namespace std;


class Base
{
	public:
		int m_a1;

	protected:
		int m_a2;
	private:
		int m_a3;
	public:
		virtual void SetValue(){}
};

 
class PublicClass:public Base
{
	public:
		void SetValue()
		{
			m_a1 = 1;
			m_a2 = 2;
			//m_a3 = 3;
		}

};

class ProtectClass:protected Base
{
	public:
		void SetValue()
		{
			m_a1 = 1;
			m_a2 = 2;
			//m_a3 = 3;
		}

};
class PrivateClass:private Base
{
	public:
		void SetValue()
		{
			m_a1 = 1;
			m_a2 = 2;
			//m_a3 = 3;
		}

};

int main(void)
{
	PublicClass Pub;
	Pub.m_a1 = 1;//共有继承只能访问public成员
	//Pub.m_a2 = 2;//公有继承不能访问protected成员
	//Pub.m_a3 = 3;//共有继承不能访问private成员
	
	ProtectClass Prote;
	//Prote.m_a1 = 1;//保护继承不能访问所有属性的成员
	//Prote.m_a2 = 2;//保护继承不能访问所有属性的成员
	//Prote.m_a3 = 3;//保护继承不能访问所有属性的成员
	
	PrivateClass Pri;
	//Pri.m_a1 = 1;//私有继承不能访问所有属性的成员
	//Pri.m_a2 = 2;//私有继承不能访问所有属性的成员
	//Pri.m_a3 = 3;//私有继承不能访问所有属性的成员

	return 0;
	
}



