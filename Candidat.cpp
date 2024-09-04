#include "Candidat.h"
#include <QObject>

Candidat::Candidat()
{
    CIN=0;
    nom="";
    nationalite="";
    sexe="";
    poste="";
    exp=0;
    age=0;
    salaire=0.0;
    idO=0;
}

Candidat::Candidat(int CIN, QString nom,QString nationalite,QString poste,QString sexe,float salaire,int age,int exp, int idO)
{
    this ->CIN=CIN;
    this ->nom=nom;
    this ->nationalite=nationalite;
    this ->poste=poste;
    this ->sexe=sexe;
    this ->exp=exp;
    this ->age=age;
    this ->salaire=salaire;
    this ->idO=idO;

}


bool Candidat::ajouter()
{
    QSqlQuery query;
    QString res = QString::number (CIN);
    QString res1 = QString::number (salaire);
    QString res2 = QString::number (age);
    QString res3 = QString::number (idO);

    query.prepare("insert into candidat (CIN,nom,age,nationalite,poste,salaire,sexe,exp,idO)""values (:CIN,:nom,:age,:nationalite,:poste,:salaire,:regime,:sexe,:exp,:idO)");

    query.bindValue(":CIN",res);
    query.bindValue(":salaire",res1);
    query.bindValue(":age",res2);
    query.bindValue(":idO",res3);
    query.bindValue(":nom",nom);
    query.bindValue(":nationalite",nationalite);
    query.bindValue(":poste",poste);
    query.bindValue(":sexe",sexe);
    query.bindValue(":exp",exp);
    return query.exec();
}

QSqlQueryModel * Candidat::afficher ()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("Select * from candidat");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nationalite"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("poste"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("exp"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("sexe"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("idO"));


    return model;
}

bool Candidat::supprimer (int CIN)
{
    QSqlQuery query;
    query.prepare("Delete from candidat where CIN=:CIN ");
    query.bindValue(":CIN",CIN);
    return query.exec();
}

bool Candidat::modifier()
{
    QSqlQuery query;
    QString res = QString::number (CIN);
    QString res1 = QString::number (salaire);
    QString res2 = QString::number (age);
    QString res3 = QString::number (idO);

    query.prepare(" UPDATE candidat set nom= :nom, salaire= :salaire, age=:age ,nationalite=:nationalite ,poste=:poste ,sexe=:sexe, exp=:exp, idO=:idO where CIN= :CIN");

    query.bindValue(":CIN",res);
    query.bindValue(":salaire",res1);
    query.bindValue(":age",res2);
    query.bindValue(":idO",res3);
    query.bindValue(":nom",nom);
    query.bindValue(":nationalite",nationalite);
    query.bindValue(":poste",poste);
    query.bindValue(":sexe",sexe);
    query.bindValue(":exp",exp);
    return query.exec();
}

QSqlQueryModel *Candidat::recherche(int CIN)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     QString res = QString::number(CIN);

     model->setQuery("select * from candidat where CIN like '" +res+ "'");

     model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("salaire"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("age"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationalite"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("poste"));
     model->setHeaderData(6,Qt::Horizontal,QObject::tr("sexe"));
     model->setHeaderData(7,Qt::Horizontal,QObject::tr("exp"));
     model->setHeaderData(8,Qt::Horizontal,QObject::tr("idO"));

 return model;
 }

QSqlQueryModel *Candidat::trier() //de A à Z
 {
     QSqlQuery * q = new  QSqlQuery ();
            QSqlQueryModel * model = new  QSqlQueryModel ();
            q->prepare("SELECT * FROM candidat order by nom ASC");
            q->exec();
            model->setQuery(*q);
            return model;
 }

QSqlQueryModel *Candidat::trierdec() //de Z à A
{
     QSqlQuery * q = new  QSqlQuery ();
            QSqlQueryModel * model = new  QSqlQueryModel ();
            q->prepare("SELECT * from candidat order by nom DESC");
            q->exec();
            model->setQuery(*q);
            return model;
}

QSqlQueryModel * Candidat::trierEXPAsc()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM candidat order by exp ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationalite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("poste"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("sexe"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("exp"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("idO"));

    return  model;
}

QSqlQueryModel * Candidat::trierEXPDesc()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM candidat order by exp DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("nationalite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("poste"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("sexe"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("exp"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("idO"));

    return  model;
}
