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
	Pub.m_a1 = 1;//���м̳�ֻ�ܷ���public��Ա
	//Pub.m_a2 = 2;//���м̳в��ܷ���protected��Ա
	//Pub.m_a3 = 3;//���м̳в��ܷ���private��Ա
	
	ProtectClass Prote;
	//Prote.m_a1 = 1;//�����̳в��ܷ����������Եĳ�Ա
	//Prote.m_a2 = 2;//�����̳в��ܷ����������Եĳ�Ա
	//Prote.m_a3 = 3;//�����̳в��ܷ����������Եĳ�Ա
	
	PrivateClass Pri;
	//Pri.m_a1 = 1;//˽�м̳в��ܷ����������Եĳ�Ա
	//Pri.m_a2 = 2;//˽�м̳в��ܷ����������Եĳ�Ա
	//Pri.m_a3 = 3;//˽�м̳в��ܷ����������Եĳ�Ա

	return 0;
	
}



