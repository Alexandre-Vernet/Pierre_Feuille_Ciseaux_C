#pragma once

class Fenetre : public wxFrame
{
public:
  Fenetre();
  void reinit();
  void init();
  void Stats();
  void choixPionJ2();
  void appuiBtPierreJ2();
  void appuiBtFeuilleJ2();
  void appuiBtCiseauxJ2();
  void score();

private:

  // Gestion des polices & couleurs

  wxFont policeBouton;
  wxColour couleurVictoire, couleurDefaite, couleurEgalite;

  // Texte

  wxStaticText nomJeu;

  wxStaticText afficherScoreJ1;
  wxStaticText afficherTiret;
  wxStaticText afficherScoreJ2;
  wxStaticText afficherInfo;

  // Bouton

  wxButton     btPierre;        void appuiBtPierreJ1( wxCommandEvent& evt );
  wxButton     btFeuille;       void appuiBtFeuilleJ1( wxCommandEvent& evt );
  wxButton     btCiseaux;       void appuiBtCiseauxJ1( wxCommandEvent& evt );

  bool pierreJ1, feuilleJ1, ciseauxJ1;
  bool pierreJ2, feuilleJ2, ciseauxJ2;

  // Gestion des scores

  int scoreJoueur1 = 0;
  int scoreJoueur2 = 0;

  wxString afficherScoreJoueur1 = "0";
  wxString afficherScoreJoueur2 = "0";

  // Compteur nombre de manche

  wxString manche;  int nbManche = 0;
};

