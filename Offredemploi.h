#ifndef OFFREDEMPLOI_H
#define OFFREDEMPLOI_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QObject>

// lezem id offre d'emploi fel candidOt
class Offredemploi
{
    QString secteur, poste;
    int idO, nbHeure;
    float remuneration;
    bool presentiel;
public:

    //constructeurs
    Offredemploi();
    Offredemploi(QString,QString,int,int,float,bool);

    //accesseurs
    QString getSecteur() {return secteur;}
    QString getPoste() {return poste;}
    int getIdO() {return idO;}
    int getNbHeure() {return nbHeure;}
    float getRemuneration() {return remuneration;}
    bool getPresentiel() {return presentiel;}

    //Mutateurs
    void setSecteur(QString n) {secteur=n;}
    void setPoste(QString n) {poste=n;}
    void setidO(int n) {idO=n;}
    void setNbHeure(int n) {nbHeure=n;}
    void setRemuneration(float n) {remuneration=n;}
    void setPresentiel(bool n) {presentiel=n;}

    //Fonctions de base
    bool ajouter();
    QSqlQueryModel * afficher ();
    bool supprimer (int);
    bool modifier ();

};

#endif // OFFREDEMPLOI_H
