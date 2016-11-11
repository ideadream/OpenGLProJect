#pragma once

class Demo03
{
public:
	Demo03();
	~Demo03();
	static Demo03* getInstance();

	void ChangeSize(GLsizei w, GLsizei h);
	void showEffectView(int argc, char** argv);

private:
	static Demo03* _shareInstance;
};