/*
 * dbhelper.cpp
 *
 * Copyright 2013 Manuel Porras Peralta <venturi.debian@gmail.com>
 *
 *  This file is part of Venturi Congress Manager.
 *
 *  Venturi Congress Manager is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Venturi Congress Manager is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Venturi Congress Manager.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 */

#include "dbhelper.h"

dbHelper::dbHelper()
{
}

QSqlDatabase db;

bool dbHelper::connect()
{
    QStringList cData;
    QFile config(":/db/dbconf.ini");
    if (config.open(QIODevice::ReadOnly))
    {
       QTextStream content(&config);
       while (!content.atEnd())
       {
           content.readLine(); //saltamos la línea de sección
           cData.append(content.readLine());
       }
       config.close();
       db = QSqlDatabase::addDatabase(cData.at(0));
       db.setHostName(cData.at(1));
       db.setDatabaseName(cData.at(2));
       db.setUserName(cData.at(3));
       db.setPassword(cData.at(4));
       if(db.open())
        return true;
    }
    return false;
}

//Select simples
TablaTextAlignCenter* dbHelper::query(int op){
    QString queryString;
    switch (op) {
        //Selecciona solo el Nombre de Organizador
        case 1: queryString = "select IDOrganizador,Nombre from Organizador;";
                break;
        //Selecciona solo el Nombre del Lugar
        case 2: queryString = "select IDLugar,Nombre from Lugar;";
                break;
        //Selecciona
        case 3: queryString = "select * from Evento;";
                break;
        case 16: queryString = "select * from Organizador;";
                break;
        case 23: queryString = "select * from Lugar;";
                break;
    }
    return doQuery(queryString,op);
}
//Búsqueda de coincidencia con fk
TablaTextAlignCenter* dbHelper::query(int op, int fk){
    QString queryString;
    switch (op) {
        case 4: queryString = "select IDUbicacion,Nombre,MaxAforo from Ubicaciones where IDLugar="+QString::number(fk)+";";
                break;
        //Selecciona el MaxAforo de la ubicación recibida en fk
        case 5: queryString = "select IDUbicacion,MaxAforo from Ubicaciones where IDUbicacion="+QString::number(fk)+";";
                break;
        //Selecciona la tabla completa del Evento clicked
        case 6: queryString = "select * from Evento where IDEvento="+QString::number(fk)+";";
                break;
        case 7: queryString = "delete from Evento where IDEvento="+QString::number(fk)+";";
                break;
        case 17: queryString = "delete from Organizador where IDOrganizador="+QString::number(fk)+";";
                break;
        case 24: queryString = "select * from Ubicaciones where IDLugar="+QString::number(fk)+";";
                break;
        case 25: queryString = "delete from Lugares where IDLugar="+QString::number(fk)+";";
                break;
        case 33: queryString = "delete from Ubicaciones where IDUbicacion="+QString::number(fk)+";";
                break;
    }
    return doQuery(queryString,op);
}

//Operaciones insert update y select "complejos"
TablaTextAlignCenter* dbHelper::query(int op, QStringList what){
    QString queryString;
    switch (op) {
        case 8: queryString = "update Evento set Nombre='"+what.at(1)+
                "', IDOrganizador='"+what.at(2)+
                "', IDLugar='"+what.at(3)+
                "', IDUbicacion='"+what.at(4)+
                "', FechaInicio='"+what.at(5)+
                "', FechaFin='"+what.at(6)+
                "', Aforo='"+what.at(7)+"' where IDEvento='"+what.at(0)+"';";
                break;
        case 9: queryString = "select * from Evento where Nombre like '"+what.at(1)+
                "' and IDOrganizador like '"+what.at(2)+
                "' and IDLugar like '"+what.at(3)+
                "' and IDUbicacion like '"+what.at(4)+
                "' and FechaInicio like '"+what.at(5)+
                "' and FechaFin like '"+what.at(6)+
                "' and IDEvento not like '"+what.at(0)+"';";
                break;
        case 10: queryString = "select * from Evento where Nombre not like '"+what.at(1)+
                "' and IDOrganizador not like '"+what.at(2)+
                "' and IDLugar like '"+what.at(3)+
                "' and IDUbicacion like '"+what.at(4)+
                "' and FechaInicio like '"+what.at(5)+
                "' and FechaFin like '"+what.at(6)+
                "' and IDEvento not like '"+what.at(0)+"';";
                break;
        case 11: queryString = "INSERT INTO Evento (Nombre,IDOrganizador,IDLugar,IDUbicacion,FechaInicio,FechaFin,Aforo) VALUES('"+
                what.at(0)+
                "','"+what.at(1)+
                "','"+what.at(2)+
                "','"+what.at(3)+
                "','"+what.at(4)+
                "','"+what.at(5)+
                "','"+what.at(6)+"');";
                break;
        case 12: queryString = "select * from Evento where Nombre like '"+what.at(0)+
                "' and IDOrganizador like '"+what.at(1)+
                "' and IDLugar like '"+what.at(2)+
                "' and IDUbicacion like '"+what.at(3)+
                "' and FechaInicio like '"+what.at(4)+
                "' and FechaFin like '"+what.at(5)+"';";
                break;
        case 13: queryString = "select * from Evento where Nombre not like '"+what.at(0)+
                "' and IDOrganizador not like '"+what.at(1)+
                "' and IDLugar like '"+what.at(2)+
                "' and IDUbicacion like '"+what.at(3)+
                "' and FechaInicio like '"+what.at(4)+
                "' and FechaFin like '"+what.at(5)+"';";
                break;
        case 14: queryString = "select * from Visitante,ListaVisitantes where ";
                if(!(what.at(0).isEmpty() && what.at(1).isEmpty()))
                    queryString+="Nombre like '"+what.at(0)+
                            "' and Apellido1 like '"+what.at(1)+"' and ";
                if(!what.at(2).isEmpty())
                    queryString+="Apellido2 like '"+what.at(2)+"' and ";
                if(!what.at(4).isEmpty())
                    queryString+="DNI like '"+what.at(4)+"' and ";
                queryString+="Activo='1' and Visitante.IDVisitante=ListaVisitantes.IDVisitante and ListaVisitantes.IDEvento='"+what.at(3);
                queryString+="';";
                break;
        case 18: queryString = "update ListaVisitantes set Checked='"+what.at(2)+
                "' where IDEvento='"+what.at(0)+
                "' and IDVisitante='"+what.at(1)+"';";
                break;
        case 19: queryString = "update Organizador set CIFNIF='"+what.at(1)+
                "', Nombre='"+what.at(2)+
                "', NombreContacto='"+what.at(3)+
                "', Telefono='"+what.at(4)+
                "', Email='"+what.at(5)+
                "' where IDOrganizador='"+what.at(0)+"';";
                break;
        case 20: queryString = "select * from Organizador where CIFNIF like '"+what.at(1)+
                "' and IDOrganizador not like '"+what.at(0)+"';";
                break;
        case 21: queryString = "insert into Organizador (CIFNIF,Nombre,NombreContacto,Telefono,Email) values('"+
                what.at(0)+
                "','"+what.at(1)+
                "','"+what.at(2)+
                "','"+what.at(3)+
                "','"+what.at(4)+"');";
                break;
        case 22: queryString = "select * from Organizador where CIFNIF like '"+what.at(0)+"';";
                break;
        case 26: queryString = "update Lugar set Nombre='"+what.at(1)+
                "', Direccion='"+what.at(2)+
                "', Ciudad='"+what.at(3)+
                "', Provincia='"+what.at(4)+
                "' where IDLugar='"+what.at(0)+"';";
                break;
        case 27: queryString = "insert into Lugar (Nombre,Direccion,Ciudad,Provincia) values('"+
                what.at(0)+
                "','"+what.at(1)+
                "','"+what.at(2)+
                "','"+what.at(3)+"');";
                break;
        case 28: queryString = "select * from Lugar where Nombre like '"+what.at(1)+
                "' and Direccion like '"+what.at(2)+
                "' and Ciudad like '"+what.at(3)+
                "' and Provincia like '"+what.at(4)+
                "' and IDLugar not like '"+what.at(0)+"';";
                break;
        case 29: queryString = "select * from Lugar where Nombre like '"+what.at(0)+
                "' and Direccion like '"+what.at(1)+
                "' and Ciudad like '"+what.at(2)+
                "' and Provincia like '"+what.at(3)+"';";
                break;
        case 30: queryString = "select * from Lugar where Nombre not like '"+what.at(0)+
                "' and Direccion like '"+what.at(1)+
                "' and Ciudad like '"+what.at(2)+
                "' and Provincia like '"+what.at(3)+"';";
                break;
        case 31: queryString = "update Ubicaciones set Nombre='"+what.at(1)+
                "', MaxAforo='"+what.at(2)+
                "', IDLugar='"+what.at(3)+
                "' where IDUbicacion='"+what.at(0)+"';";
                break;
        case 32: queryString = "select * from Ubicaciones where Nombre like '"+what.at(1)+
                "' and IDUbicacion not like '"+what.at(0)+
                "' and IDLugar like '"+what.at(3)+"';";
                break;
        case 34: queryString = "select * from Ubicaciones where Nombre like '"+what.at(0)+
                "' and IDLugar like '"+what.at(2)+
                +"';";
                break;
        case 35: queryString = "insert into Ubicaciones (Nombre,MaxAforo,IDLugar) values('"+
                what.at(0)+
                "','"+what.at(1)+
                "','"+what.at(2)+"');";
                break;
    }
    return doQuery(queryString,op);
}

TablaTextAlignCenter* dbHelper::query(int op, QString what, QString where){
    QString queryString;
    switch (op) {
        case 15: queryString = "select * from Visitante, ListaVisitantes where DNI like '"+what+
                "' and Visitante.IDVisitante=ListaVisitantes.IDVisitante and Activo='1' and ListaVisitantes.IDEvento='"+where+
                "';";
                break;
    }
    return doQuery(queryString,op);
}

TablaTextAlignCenter* dbHelper::doQuery(QString queryString, int op){
    QSqlQuery query;
    if(query.exec(queryString)){
        TablaTextAlignCenter *model = new TablaTextAlignCenter;
        model->setQuery(query);
        switch (op){
        case 3:
            model->setHeaderData(0, Qt::Horizontal, QObject::trUtf8("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::trUtf8("Nombre del Evento"));
            model->setHeaderData(2, Qt::Horizontal, QObject::trUtf8("ID Organizador"));
            model->setHeaderData(3, Qt::Horizontal, QObject::trUtf8("ID Lugar"));
            model->setHeaderData(4, Qt::Horizontal, QObject::trUtf8("Ubicación"));
            model->setHeaderData(5, Qt::Horizontal, QObject::trUtf8("Fecha Inicio"));
            model->setHeaderData(6, Qt::Horizontal, QObject::trUtf8("Fecha Fin"));
            model->setHeaderData(7, Qt::Horizontal, QObject::trUtf8("Aforo"));
            break;
        case 14:
        case 15:
            model->setHeaderData(0, Qt::Horizontal, QObject::trUtf8("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::trUtf8("Nombre"));
            model->setHeaderData(2, Qt::Horizontal, QObject::trUtf8("Primer Apellido"));
            model->setHeaderData(3, Qt::Horizontal, QObject::trUtf8("Segundo Apellido"));
            model->setHeaderData(4, Qt::Horizontal, QObject::trUtf8("DNI"));
            model->setHeaderData(5, Qt::Horizontal, QObject::trUtf8("E-Mail"));
            break;
        case 16:
            model->setHeaderData(1,Qt::Horizontal, QObject::trUtf8("CIF/NIF"));
            model->setHeaderData(2, Qt::Horizontal, QObject::trUtf8("Organizador"));
            model->setHeaderData(3, Qt::Horizontal, QObject::trUtf8("Contacto"));
            break;
        case 23:
            model->setHeaderData(1,Qt::Horizontal, QObject::trUtf8("Lugar"));
            model->setHeaderData(2, Qt::Horizontal, QObject::trUtf8("Dirección"));
            model->setHeaderData(3, Qt::Horizontal, QObject::trUtf8("Ciudad"));
            model->setHeaderData(4, Qt::Horizontal, QObject::trUtf8("Provincia"));
            break;
        case 24:
            model->setHeaderData(1,Qt::Horizontal, QObject::trUtf8("Nombre"));
            model->setHeaderData(2, Qt::Horizontal, QObject::trUtf8("Aforo máximo"));
            break;
        }
        return model;
    }
    else
        qDebug() << "No se pudo ejecutar la consulta en la base de datos...";
    return NULL;
}

void dbHelper::close(){
    db.close();
}
