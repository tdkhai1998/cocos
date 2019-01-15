#pragma once


class Maps {
public:
	static Maps *getInstance() {
		instance = new Maps();
		return instance;
	}



	~Maps() { delete instance; }
private:
	Maps() {}
	static Maps *instance;
};