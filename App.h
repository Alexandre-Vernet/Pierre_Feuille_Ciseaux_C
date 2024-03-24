#pragma once

#include "Fen.h"

class Application : public wxApp
{
public:
  virtual bool OnInit();

private:
  Fenetre* objFenetre;
};
