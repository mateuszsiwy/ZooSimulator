#pragma once
#include <wx/wxprec.h>

class Animal {
public:
    virtual void Draw(wxDC& dc, int x, int y) = 0;
    virtual void Feed() = 0;
    virtual ~Animal() {}
    virtual int GetX() const = 0;
    virtual int GetY() const = 0;
    virtual void SetX(int x) = 0;
    virtual void SetY(int y) = 0;
    virtual std::string GetFoodName() = 0;
    virtual bool hasEaten() = 0;
};

class Elephant : public Animal {
public:
    Elephant();
    void Draw(wxDC& dc, int x, int y) override;

    int GetX() const override { return x; }
    int GetY() const override { return y; }
    void SetX(int x) override { this->x = x; }
    void SetY(int y) override { this->y = y; }
    void Feed();
    bool hasEaten() { return !isHungry; }
    std::string GetFoodName();
private:
    int x, y;
    bool isHungry = true;
};

class Giraffe : public Animal {
public:
    Giraffe();
    void Draw(wxDC& dc, int x, int y) override;

    int GetX() const override { return x; }
    int GetY() const override { return y; }
    void SetX(int x) override { this->x = x; }
    void SetY(int y) override { this->y = y; }
    void Feed();
    bool hasEaten() { return !isHungry; }
    std::string GetFoodName();
private:
    int x, y;
    bool isHungry = true;
};

class Parrot : public Animal {
public:
    Parrot();
    void Draw(wxDC& dc, int x, int y) override;

    int GetX() const override { return x; }
    int GetY() const override { return y; }
    void SetX(int x) override { this->x = x; }
    void SetY(int y) override { this->y = y; }
    void Feed();
    bool hasEaten() { return !isHungry; }
    std::string GetFoodName();
private:
    int x, y;
    bool isHungry = true;
};


