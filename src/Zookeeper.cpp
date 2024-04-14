#include "Zookeeper.h"
#include "DrawFunctions.h"

void Zookeeper::Draw(wxDC& dc, int x, int y) {
	drawImage(dc, "zookeeper.png", x, y, true);
}

void Zookeeper::Move(int x, int y) {
	_x += x;
	_y += y;
}

int Zookeeper::GetX() {
	return _x;
}
int Zookeeper::GetY() {
	return _y;
}

void Zookeeper::UpdateFoodBag(std::string foodname) {
	FoodBag.push_back(foodname);
}

bool Zookeeper::InFoodBag(std::string foodname) {
	for (auto& food : FoodBag) {
		if (food == foodname) {
			return true;
		}
	}
	return false;
}