#ifndef CANDIDAT_H
#define CANDIDAT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QObject>

class Candidat
{
    QString nom, nationalite, sexe, poste;
    int CIN,age, exp, idO;
    float salaire;

public:

    //constructeurs
    Candidat();
    Candidat(int,QString,QString,QString,QString,float,int,int,int);

    //accesseurs
    QString getNom() {return nom;}
    QString getNationalite() {return nationalite;}
    QString getPoste() {return poste;}
    QString getSexe() {return sexe;}
    int getCIN() {return CIN;}
    int getAge() {return age;}
    int getExp() {return exp;}
    int getIdO() {return idO;}
    int getSalaire() {return salaire;}


    //Mutateurs
    void setNom(QString n) {nom=n;}
    void setNationalite(QString n) {nationalite=n;}
    void setPoste(QString n) { poste=n;}
    void setSexe(QString n) { sexe=n;}
    void setCIN(int n) {CIN=n;}
    void setIdO(int n) {idO=n;}
    void setAge(int n ) {age=n;}
    void setExp(int n) { exp=n; }

    //Fonctions de base

    bool ajouter();
    QSqlQueryModel * afficher ();
    bool supprimer (int);
    bool modifier ();
    QSqlQueryModel * recherche(int);
    QSqlQueryModel * trier();
    QSqlQueryModel * trierdec();
    QSqlQueryModel * trierEXPAsc();
    QSqlQueryModel * trierEXPDesc();



    /*void statistique(QVector<int>* CIN,QVector<float> *salaire);*/

};

#endif // CANDIDAT_H
