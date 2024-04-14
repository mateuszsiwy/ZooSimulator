#pragma once
#include <wx/wxprec.h>


class Zookeeper {
public:
	Zookeeper(int x, int y): _x(x), _y(y){}
	void Draw(wxDC& dc, int x, int y);
	void Move(int x, int y);
	int GetX();
	int GetY();
	void UpdateFoodBag(std::string foodname);
	bool InFoodBag(std::string foodname);
private:
	int _x;
	int _y;
	std::vector<std::string> FoodBag;
};