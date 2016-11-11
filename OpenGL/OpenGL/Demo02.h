#pragma once

class Demo02
{
public:
	Demo02();
	~Demo02();
	void init(void);
	void Sleep(int ms);
	void showEffectView(int argc, char** argv);
	static Demo02* getInstance();

private:
	static Demo02* _shareInstance;
};