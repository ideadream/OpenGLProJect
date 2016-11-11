#pragma once


class Demo01
{
public:
	Demo01();
	~Demo01();
	void Initial(void);
	void showEffectView(int argc, char *argv[]);
	static Demo01* getInstance();

private:
	static Demo01* _shareInstance;
};