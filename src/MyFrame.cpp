#include "MyFrame.h"
#include "DrawFunctions.h"
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/event.h>

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Demo 06")
{
	SetTitle(_("Zoo Simulator"));
	SetIcon(wxNullIcon);
	SetSize(8, 8, 394, 421);
	Center();

	zookeeper = new Zookeeper(200, 500);

	zoo_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(600, 600));
	control_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200,200));
	zoo_panel->SetDoubleBuffered(true);
	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

	//zoo_panel->SetBackgroundColour(wxColor(50, 160, 0));
	control_panel->SetBackgroundColour(wxColor(*wxLIGHT_GREY));
	sizer->Add(zoo_panel, 2, wxEXPAND);
	sizer->Add(control_panel, 1, wxEXPAND);
	zoo_panel->SetWindowStyle(wxWANTS_CHARS);
	SetSizerAndFit(sizer);

	zoo_panel->Bind(wxEVT_PAINT, &MyFrame::Form_Paint, this);

	wxString animals[] = { "elephant", "giraffe", "parrot" };
	animal_selection = new wxChoice(control_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, WXSIZEOF(animals), animals);
	animal_selection->Bind(wxEVT_CHOICE, &MyFrame::On_Choice, this);

	add_animal = new wxButton(control_panel, wxID_ANY, "Add Animal");
	add_animal->Bind(wxEVT_BUTTON, &MyFrame::Add_Button, this);

	wxBoxSizer* control_sizer = new wxBoxSizer(wxVERTICAL);
	control_sizer->Add(animal_selection, wxSizerFlags(1).Expand().Border(wxALL, 10));
	control_sizer->Add(add_animal, wxSizerFlags(1).Expand().Border(wxALL, 10));
	control_panel->SetSizer(control_sizer);
	
	zoo_panel->Bind(wxEVT_KEY_DOWN, &MyFrame::OnKeyDown, this);
}

void MyFrame::Form_Paint(wxPaintEvent& event) {
	
	wxPaintDC dc(zoo_panel);
	//wxImage image("images/zooBoard.png", wxBITMAP_TYPE_PNG);
	MyImage.AddHandler(new wxPNGHandler);
	drawImage(dc, "zooBoard.png", 0, 0, false);
	for (auto& animal : animals) {
		animal->Draw(dc, animal->GetX(), animal->GetY());
	}
	zookeeper->Draw(dc, zookeeper->GetX(), zookeeper->GetY());
	//wxImage imageElephant;

	drawImage(dc, "message.png", 0, 98, false);

	if (shop_open == true) {
		drawImage(dc, "shopwithitems.png", 20, 0, false);
		
		
	}
	
	int is_finished = -1;
	for (auto& animal : animals) {
		if (animal->hasEaten() == true) {
			is_finished += 1;
		}
		
	}
	
	if (is_finished >= 0 && is_finished == animals.size()-1 && !messagebox_displayed) {
		wxMessageBox("congrats, you fed all the animals!");
		messagebox_displayed = true; 
		
	}
}

void MyFrame::On_Choice(wxCommandEvent& event) {
	selected_animal = animal_selection->GetSelection();
	//Refresh();
}

void MyFrame::Add_Button(wxCommandEvent& event) {
	if (selected_animal == 0) {
		animals.push_back(std::make_unique<Elephant>());
	}
	else if (selected_animal == 1) {
		animals.push_back(std::make_unique<Giraffe>());
	}
	else if (selected_animal == 2) {
		animals.push_back(std::make_unique<Parrot>());
	}
	
	Refresh();
}

void MyFrame::OnKeyDown(wxKeyEvent& event) {
	switch (event.GetKeyCode()) {
	case WXK_UP:
		zookeeper->Move(0, -15); 
		break;
	case WXK_DOWN:
		zookeeper->Move(0, 15); 
		break;
	case WXK_LEFT:
		zookeeper->Move(-15, 0); 
		break;
	case WXK_RIGHT:
		zookeeper->Move(15, 0); 
		break;
	case WXK_SHIFT:
		if (abs(zookeeper->GetX() - 300) < 80 && abs(zookeeper->GetY() - 300) < 80) {
			shop_open = true;
		}
		
		
		break;
	case WXK_ESCAPE:
		shop_open = false;
		break;
	case '1':
		if (shop_open == true) {
			wxMessageBox("Bought elephant food!");
			zookeeper->UpdateFoodBag("elephant food");
		}
		
		break;
	case '2':
		if (shop_open == true) {
			wxMessageBox("Bought giraffe food!");
			zookeeper->UpdateFoodBag("giraffe food");
		}
		
		break;
	case '3':
		if (shop_open == true) {
			wxMessageBox("Bought parrot food!");
			zookeeper->UpdateFoodBag("parrot food");
		}

		break;
	case 'E':
		for (auto& animal : animals) {
			if (abs(zookeeper->GetX() - animal->GetX()) < 80 && abs(zookeeper->GetY() - animal->GetY()) < 80) {
				if (zookeeper->InFoodBag(animal->GetFoodName())) {
					wxMessageBox("fed the animal!");
					animal->Feed();
				}
				else {
					wxMessageBox("no correct food in the bag!");
				}
				
			}
		}
		break;
	default:
		event.Skip();
	}
	Refresh();
}