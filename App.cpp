#include <wx/wx.h>

#include "App.h"



bool Application::OnInit()
{
  objFenetre =  new Fenetre;
  objFenetre->Show();

  return true;
}

wxIMPLEMENT_APP( Application );
