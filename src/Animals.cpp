#include "Animals.h"
#include "DrawFunctions.h"



Elephant::Elephant(): x(100), y(70){}

Giraffe::Giraffe(): x(450), y(280){}

Parrot::Parrot(): x(450), y(530){}

void Elephant::Draw(wxDC& dc, int x, int y) {
	drawImage(dc, "elephant.png", x, y, true);
}

void Giraffe::Draw(wxDC& dc, int x, int y) {
	drawImage(dc, "giraffe.png", x, y, true);
}

void Parrot::Draw(wxDC& dc, int x, int y) {
	drawImage(dc, "parrot.png", x, y, true);
}

void Elephant::Feed() {
	isHungry = false;
}

void Giraffe::Feed() {
	isHungry = false;
}

void Parrot::Feed() {
	isHungry = false;
}

std::string Elephant::GetFoodName() {
	return "elephant food";
}

std::string Giraffe::GetFoodName() {
	return "giraffe food";
}

std::string Parrot::GetFoodName() {
	return "parrot food";
}