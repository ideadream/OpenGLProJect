#pragma once
class Demo04
{
public:
	Demo04();
	~Demo04();
	void showEffectView(int argc, char** argv);
	void SetupRC();
	static Demo04* getInstance();

private:
	static Demo04* _shareInstance;
};

