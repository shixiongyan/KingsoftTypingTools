#include "Key.h"
#include <string>
Key::Key()
{
	this->time=0; //Ĭ��û���ӳ� 
	cout<<this->time;
}

Key::~Key()
{
	
}
void state()
{
	/*
	// �жϼ���CapsLock���Ƿ���״̬,����״̬��Ϊ��д,����ΪСд
     if (GetKeyState(VK_CAPITAL))
     {
         // �����ǰ����״̬Ϊ��д,Ҫ���Сд,��ģ�ⰴ��CapsLock�л�״̬
         if (!big)
         {
             keybd_event(VK_CAPITAL, NULL, KEYEVENTF_EXTENDEDKEY | 0, NULL);
             keybd_event(VK_CAPITAL, NULL, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, NULL);
        }
     }
     else
     {
         // �����ǰ����״̬ΪСд,Ҫ��Ĵ�д,��ģ�ⰴ��CapsLock�л�״̬He 
         if (big)
         {
             keybd_event(VK_CAPITAL, NULL, KEYEVENTF_EXTENDEDKEY | 0, NULL);
             keybd_event(VK_CAPITAL, NULL, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, NULL);
         }
     }*/
     //if(!GetKeyStaye(VK_CAPITAL))
    // {
     	//press(VK_CAPITAL); 
     	
	// }
	 //�����Сд�ĳɴ�д 
}

Key& Key::down(int vk_code)
{
	keybd_event(vk_code,0,0,0);

}
Key& Key::up(int vk_code)
{
	keybd_event(vk_code,0,KEYEVENTF_KEYUP,0);

}
Key& Key::press(int vk_code)
{
	if(this->time)
	{
		this->sleep(this->time);
	}
	
	if(islower(vk_code))//Сд��ĸ 
	{
		vk_code-=32; 
	}
	down(vk_code);
	up(vk_code);
	return *this; 
}
Key& Key::combination(int vk_code)
{
	press(vk_code);
	return *this;
}
Key& Key::combination(int vk_code_1,int vk_code_2)
{
	down(vk_code_1);
	press(vk_code_2);
	up(vk_code_1);
	return *this;
}
Key& Key::combination(int vk_code_1,int vk_code_2,int vk_code_3)
{
	down(vk_code_1);
	down(vk_code_2);
	press(vk_code_3);
	up(vk_code_2);
	up(vk_code_1);
	return *this;
}
Key& Key::combination(int vk_code_1,int vk_code_2,int vk_code_3,int vk_code_4)
{
	down(vk_code_1);
	down(vk_code_2);
	down(vk_code_3);
	press(vk_code_4);
	up(vk_code_3);
	up(vk_code_2);
	up(vk_code_1);
	return *this;
}
Key& Key::sleep(int _time)
{
	Sleep(_time);
	return *this;
}
Key& Key::caps()
{
	if (GetKeyState(VK_CAPITAL))
    {
         // �����ǰ����״̬Ϊ��д,Ҫ���Сд,��ģ�ⰴ��CapsLock�л�״̬

             keybd_event(VK_CAPITAL, 0, 0, 0);
             keybd_event(VK_CAPITAL, 0, KEYEVENTF_KEYUP, 0);
    }
    return *this;
}
Key& Key::Caps()
{
	if (!GetKeyState(VK_CAPITAL))
    {
         // �����ǰ����״̬ΪСд,Ҫ��Ĵ�д,��ģ�ⰴ��CapsLock�л�״̬

             keybd_event(VK_CAPITAL, 0, 0, 0);
             keybd_event(VK_CAPITAL, 0, KEYEVENTF_KEYUP, 0);
    }
    return *this;
}
Key& Key::setSleepTime(int _time)
{
	this->time=_time;
	return *this;
}
Key& Key::period()
{
	keybd_event(VK_DECIMAL, 0, 0, 0);
    keybd_event(VK_DECIMAL, 0, KEYEVENTF_KEYUP, 0);
}
Key& Key::comma()
{
	keybd_event(188, 0, 0, 0);
    keybd_event(188, 0, KEYEVENTF_KEYUP, 0);
}
int Key::getTime()
{
	return this->time;
}
Key& Key::bearStr(string str)
{
    for(int cout=0;cout<str.length();cout++)
    {
    	if(isupper(str[cout]))//����Ǵ�д��ĸ
		{
			this->Caps();
			press(str[cout]);
			this->caps(); 
		}
		else if(str[cout]=='.')
		{
			period();
		}
		else if(str[cout]==',')
		{
			comma();
		}
		else
		{
			press(str[cout]);
		}
	}
	return *this;
}

