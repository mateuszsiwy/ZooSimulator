#include "DrawFunctions.h"


void drawImage(wxDC& dc, std::string route, int x, int y, bool rescale) {
	wxImage image;
	image.LoadFile(route, wxBITMAP_TYPE_PNG);
	if (rescale == true) {
		image.Rescale(51, 38);
	}
	
	wxBitmap bitmap = wxBitmap(image);
	dc.DrawBitmap(bitmap, x, y);
	//Refresh();
}