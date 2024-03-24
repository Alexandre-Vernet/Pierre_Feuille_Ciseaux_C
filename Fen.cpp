#include <wx/wx.h>
#include <cstdlib>
#include <ctime>
#include "windows.h"

#include "Fen.h"

Fenetre::Fenetre() : wxFrame(NULL, wxID_ANY, "Pierre - Feuille - Ciseaux ",
        wxDefaultPosition, wxSize(400,600), wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN | wxMINIMIZE_BOX )
{
  Fenetre::SetBackgroundColour( wxColour(185, 185, 185) );

  this->Center();
  this->CreateStatusBar();
  this->SetStatusText("Pierre - Feuille - Ciseaux");

  // Police

  policeBouton = wxFont( wxFontInfo(12).FaceName("comic sans ms ") );

  couleurVictoire = ( wxColour (0, 0, 255) );
  couleurDefaite  = ( wxColour (255, 0, 0) );
  couleurEgalite =  ( wxColour (0, 0, 0) );

  // Texte

  nomJeu.Create( this, wxID_ANY, "Jeu du Pierre Feuille Ciseaux",
                       wxPoint(15, 15), wxSize(200, 5) );
  nomJeu.SetFont( wxFont( wxFontInfo(20).FaceName("forte").Bold() ) );


  afficherScoreJ1.Create( this, wxID_ANY, afficherScoreJoueur1,
                       wxPoint(125, 85), wxSize(50, 25), wxBORDER_SIMPLE | wxALIGN_CENTER );
  afficherScoreJ1.SetFont( wxFont( wxFontInfo(15).FaceName("calibri") ) );
  afficherScoreJ1.SetForegroundColour( couleurVictoire );

  afficherTiret.Create( this, wxID_ANY, " - ",
                       wxPoint(175, 85), wxSize(50, 25), wxALIGN_CENTER );
  afficherTiret.SetFont( wxFont( wxFontInfo(15).FaceName("calibri") ) );

  afficherScoreJ2.Create( this, wxID_ANY, afficherScoreJoueur2,
                       wxPoint(225, 85), wxSize(50, 25), wxBORDER_SIMPLE | wxALIGN_CENTER );
  afficherScoreJ2.SetFont( wxFont( wxFontInfo(15).FaceName("calibri") ) );
  afficherScoreJ2.SetForegroundColour( couleurDefaite );


  afficherInfo.Create( this, wxID_ANY, "",
                       wxPoint(75, 150), wxSize(250, 215), wxBORDER_SIMPLE | wxALIGN_CENTER );
  afficherInfo.SetFont( wxFont( wxFontInfo(15).FaceName("calibri") ) );


  btPierre.Create( this, wxID_ANY, "Pierre",
                  wxPoint(25, 400), wxSize(100, 100) );
  btPierre.Bind( wxEVT_BUTTON, appuiBtPierreJ1, this );
  btPierre.SetFont( policeBouton );

  btFeuille.Create( this, wxID_ANY, "Feuille",
                  wxPoint(150, 400), wxSize(100, 100) );
  btFeuille.Bind( wxEVT_BUTTON, appuiBtFeuilleJ1, this );
  btFeuille.SetFont( policeBouton );

  btCiseaux.Create( this, wxID_ANY, "Ciseaux",
                  wxPoint(275, 400), wxSize(100, 100) );
  btCiseaux.Bind( wxEVT_BUTTON, appuiBtCiseauxJ1, this );
  btCiseaux.SetFont( policeBouton );
}

// Initialisation

void Fenetre::init()
{
  scoreJoueur1 = 0;
  scoreJoueur2 = 0;
  afficherInfo.SetLabel("");
  score();
  nbManche = -1;
  reinit();
}
void Fenetre::reinit()
{
  pierreJ1 = false;    pierreJ2 = false;
  feuilleJ1 = false;   feuilleJ2 = false;
  ciseauxJ1 = false;   ciseauxJ2 = false;
  nbManche++;

  switch ( nbManche )
  {
    case 0:  manche = "Nombre de manche : 0"; break;
    case 1:  manche = "Nombre de manche : 1"; break;
    case 2:  manche = "Nombre de manche : 2"; break;
    case 3:  manche = "Nombre de manche : 3"; break;
    case 4:  manche = "Nombre de manche : 4"; break;
    case 5:  manche = "Nombre de manche : 5"; break;
    case 6:  manche = "Nombre de manche : 6"; break;
    case 7:  manche = "Nombre de manche : 7"; break;
    case 8:  manche = "Nombre de manche : 8"; break;
    case 9:  manche = "Nombre de manche : 9"; break;
    case 10: manche = "Nombre de manche : 10"; break;
    case 11: manche = "Nombre de manche : 11"; break;
    case 12: manche = "Nombre de manche : 12"; break;
    case 13: manche = "Nombre de manche : 13"; break;
    case 14: manche = "Nombre de manche : 14"; break;
    case 15: manche = "Nombre de manche : 15"; break;
    case 16: manche = "Nombre de manche : 16"; break;
    case 17: manche = "Nombre de manche : 17"; break;
    case 18: manche = "Nombre de manche : 18"; break;
    case 19: manche = "Nombre de manche : 19"; break;
    case 20: manche = "Nombre de manche : 20"; break;
    case 21: manche = "Nombre de manche : 21"; break;
    case 22: manche = "Nombre de manche : 22"; break;
    case 23: manche = "Nombre de manche : 23"; break;
    case 24: manche = "Nombre de manche : 24"; break;
    case 25: manche = "Nombre de manche : 25"; break;
    case 26: manche = "Nombre de manche : 26"; break;
    case 27: manche = "Nombre de manche : 27"; break;
    case 28: manche = "Nombre de manche : 28"; break;
    case 29: manche = "Nombre de manche : 29"; break;
    case 30: manche = "Nombre de manche : 30"; break;
    default: manche = "Nombre de manche : ..."; break;
  }
  this->SetStatusText( manche );
}

// Joueur 1

void Fenetre::choixPionJ2()
{
  // Choix pion joueur 2

  srand((unsigned int)time(0));
  int choixJoueur2 = rand()%3;

  switch ( choixJoueur2 )
  {
  case 0:  appuiBtPierreJ2();     break; // Pierre
  case 1:  appuiBtFeuilleJ2();    break; // Feuille
  case 2:  appuiBtCiseauxJ2();    break; // Ciseaux
  default: wxMessageBox("Erreur, l'ordi a choisit un nombre impossible !"); break;
  }
  Stats();
  score();
}

// Choix joueur 1

// J1 choisit pierre

void Fenetre::appuiBtPierreJ1( wxCommandEvent& evt )
{
  pierreJ1 = true;
  choixPionJ2();
}

// J1 choisit feuille

void Fenetre::appuiBtFeuilleJ1( wxCommandEvent& evt )
{
  feuilleJ1 = true;
  choixPionJ2();
}

// J1 choisit ciseaux

void Fenetre::appuiBtCiseauxJ1( wxCommandEvent& evt )
{
  ciseauxJ1 = true;
  choixPionJ2();
}

// Joueur 2

// J2 choisit pierre

void Fenetre::appuiBtPierreJ2()
{
  pierreJ2 = true;
}

// J2 choisit feuille

void Fenetre::appuiBtFeuilleJ2()
{
  feuilleJ2 = true;
}

// J2 choisit ciseaux

void Fenetre::appuiBtCiseauxJ2()
{
  ciseauxJ2 = true;
}

// Gestion des statistiques du jeu

void Fenetre::Stats()
{
  // Si J1 choisit Pierre

  if ( pierreJ1 == true && feuilleJ2 == true )
  {
    afficherInfo.SetLabel("Perdu ! \nL'ordi avait choisi Feuille !");
    afficherInfo.SetForegroundColour( couleurDefaite );
    scoreJoueur2++;
    reinit();
  }
  if ( pierreJ1 == true && ciseauxJ2 == true )
  {
    afficherInfo.SetLabel("Gagné ! \nL'ordi avait choisi Ciseaux !");
    afficherInfo.SetForegroundColour( couleurVictoire );
    scoreJoueur1++;
    reinit();
  }
  if ( pierreJ1 == true && pierreJ2 == true )
  {
    afficherInfo.SetLabel("Egalité ! \nL'ordi avait choisi Pierre !");
    afficherInfo.SetForegroundColour( couleurEgalite );
    reinit();
  }

  // Si J1 choisit Feuille

  if ( feuilleJ1 == true && ciseauxJ2 == true )
  {
    afficherInfo.SetLabel("Perdu ! \nL'ordi avait choisi Ciseaux !");
    afficherInfo.SetForegroundColour( couleurDefaite );
    scoreJoueur2++;
    reinit();
  }
  if ( feuilleJ1 == true && pierreJ2 == true )
  {
    afficherInfo.SetLabel("Gagné ! \nL'ordi avait choisi Pierre !");
    afficherInfo.SetForegroundColour( couleurVictoire );
    scoreJoueur1++;
    reinit();
  }
  if ( feuilleJ1 == true && feuilleJ2 == true )
  {
    afficherInfo.SetLabel("Egalité ! \nL'ordi avait choisi Feuille !");
    afficherInfo.SetForegroundColour( couleurEgalite );
    reinit();
  }

  // Si J1 choisit Ciseaux

  if ( ciseauxJ1 == true && pierreJ2 == true )
  {
    afficherInfo.SetLabel("Perdu ! \nL'ordi avait choisi Pierre !");
    afficherInfo.SetForegroundColour( couleurDefaite );
    scoreJoueur2++;
    reinit();
  }
  if ( ciseauxJ1 == true && feuilleJ2 == true )
  {
    afficherInfo.SetLabel("Gagné ! \nL'ordi avait choisi Feuille !");
    afficherInfo.SetForegroundColour( couleurVictoire );
    scoreJoueur1++;
    reinit();
  }
  if ( ciseauxJ1 == true && ciseauxJ2 == true )
  {
    afficherInfo.SetLabel("Egalité ! \nL'ordi avait choisi Ciseaux !");
    afficherInfo.SetForegroundColour( couleurEgalite );
    reinit();
  }
}
void Fenetre::score()
{
  // Gestion des scores de J1

  switch ( scoreJoueur1 )
  {
    case 0:  afficherScoreJ1.SetLabel("0"); break;
    case 1:  afficherScoreJ1.SetLabel("1"); break;
    case 2:  afficherScoreJ1.SetLabel("2"); break;
    case 3:  afficherScoreJ1.SetLabel("3"); break;
    case 4:  afficherScoreJ1.SetLabel("4"); break;
    case 5:  afficherScoreJ1.SetLabel("5"); break;
    default: afficherScoreJ1.SetLabel("Erreur lors de l'affichage du score !");
  }

  // Si J1 gagne

  if ( scoreJoueur1 == 5 )
  {
    this->SetStatusText("Bravo ! Vous avez gagné !");
    int reponse = wxMessageBox( "Vous avez gagné ! \nRejouer ?", "Félicitations !", wxYES_NO | wxCANCEL );
    if ( reponse == wxYES )          init();
    else if ( reponse == wxNO )      this->Close();
    else if ( reponse == wxCANCEL )  { /* Ne rien faire */ }
  }


  // Score Joueur 2

  switch ( scoreJoueur2 )
  {
    case 0:  afficherScoreJ2.SetLabel("0"); break;
    case 1:  afficherScoreJ2.SetLabel("1"); break;
    case 2:  afficherScoreJ2.SetLabel("2"); break;
    case 3:  afficherScoreJ2.SetLabel("3"); break;
    case 4:  afficherScoreJ2.SetLabel("4"); break;
    case 5:  afficherScoreJ2.SetLabel("5"); break;
    default: afficherScoreJ2.SetLabel("Erreur lors de l'affichage du score !");
  }

  // Si J2 gagne

  if ( scoreJoueur2 == 5 )
  {
    this->SetStatusText("Dommage ! Vous avez perdu !");
    int reponse = wxMessageBox( "Vous avez perdu ! \nRejouer ?", "Dommage ...", wxYES_NO | wxCANCEL );
    if ( reponse == wxYES )          init();
    else if ( reponse == wxNO )      this->Close();
    else if ( reponse == wxCANCEL )  { /* Ne rien faire */ }
  }
}
