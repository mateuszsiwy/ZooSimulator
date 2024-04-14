#pragma once
#include <wx/wxprec.h>
#include <vector>
#include "Animals.h"
#include "Zookeeper.h"
class MyFrame : public wxFrame
{
public:
	MyFrame();
private:
	//void Form_Paint(wxPaintEvent& e);
	wxPanel* zoo_panel; // panel that holds the whole zoo
	wxPanel* control_panel; // panel that holds the control buttons and sliders
	wxBitmap zoo_board; // bitmap holding the zoo board graphic
	wxImage MyImage; // temporary image holder
	wxChoice* animal_selection; // button that lets the user choose which animal to add

	wxButton* add_animal; // button that adds selected animal
	int selected_animal=4;
	std::vector<std::unique_ptr<Animal>> animals;
	Zookeeper* zookeeper;
	bool shop_open = false;
	bool messagebox_displayed = false;

	void Form_Paint(wxPaintEvent& event);
	void On_Choice(wxCommandEvent& event);
	void Add_Button(wxCommandEvent& event);
	void OnKeyDown(wxKeyEvent& event);
};


