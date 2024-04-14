#include <wx/wxprec.h>
#include "MyFrame.h"
#include "Animals.h"
class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};



wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	SetProcessDPIAware();
	MyFrame* frame = new MyFrame();
	frame->Show(true);
	return true;
}



