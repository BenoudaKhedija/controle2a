#include "Offredemploi.h"

Offredemploi::Offredemploi()
{
    nbHeure=0;
    idO=0;
    secteur="";
    poste="";
    remuneration=0.0;
    presentiel=1;
}

Offredemploi::Offredemploi(QString secteur,QString poste,int idO,int nbHeure,float remuneration, bool presentiel )
{
    this ->secteur=secteur;
    this ->poste=poste;
    this ->idO=idO;
    this ->nbHeure=nbHeure;
    this ->remuneration=remuneration;
    this ->presentiel=presentiel;
}

bool Offredemploi::ajouter()
{
    QSqlQuery query;
    QString res = QString::number (remuneration);
    QString res1 = QString::number (idO);
    QString res2 = QString::number (nbHeure);
    QString res3 = QString::number (presentiel);

    query.prepare("insert into Offredemploi (idO,poste,nbHeure,secteur,remuneration,presentiel)""values (:idO,:poste,:nbHeure,:secteur,:remuneration,:presentiel)");

    query.bindValue(":remuneration",res);
    query.bindValue(":idO",res1);
    query.bindValue(":nbHeure",res2);
    query.bindValue(":presentiel",res3);
    query.bindValue(":poste",poste);
    query.bindValue(":secteur",secteur);
    return query.exec();
}

QSqlQueryModel * Offredemploi::afficher ()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("Select * from Offredemploi");
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("idO"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nbHeure"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("secteur"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("poste"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("presentiel"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("remuneration"));
    return model;
}

bool Offredemploi::supprimer (int idO)
{
    QSqlQuery query;
    query.prepare("Delete from Offredemploi where idO=:idO ");
    query.bindValue(":idO",idO);
    return query.exec();
}

bool Offredemploi::modifier()
{
    QSqlQuery query;
    QString res = QString::number (remuneration);
    QString res1 = QString::number (idO);
    QString res2 = QString::number (nbHeure);
    QString res3 = QString::number (presentiel);

    query.prepare(" UPDATE Offredemploi set remuneration= :remuneration, nbHeure= :nbHeure, poste=:poste ,secteur=:secteur, presentiel= :presentiel where idO= :idO");

    query.bindValue(":remuneration",res);
    query.bindValue(":idO",res1);
    query.bindValue(":nbHeure",res2);
    query.bindValue(":presentiel",res3);
    query.bindValue(":poste",poste);
    query.bindValue(":secteur",secteur);
    return query.exec();
}
