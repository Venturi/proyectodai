/*
 * maincongressman.h
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

#ifndef MAINCONGRESSMAN_H
#define MAINCONGRESSMAN_H

#include <QMainWindow>
#include "dbhelper.h"
#include <QMessageBox>

namespace Ui {
class MainCongressMan;
}

class MainCongressMan : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainCongressMan(QWidget *parent = 0);
    ~MainCongressMan();

private slots:
    void initUI(); //Inicializa el UI (Interfaz de Usuario)
    void resetEventos(); //Reset del formulario de Eventos
    void resetOrganizadores(); //Reset del formulario de Organizadores
    void resetAsistentes(); //Reset del formulario de Asistentes
    void resetLugares(); //Reset del formulario Lugares y, en consecuencia, del de Ubicaciones
    void resetUbicaciones(); //Reset del formulario Ubicaciones
    int busca(int, int, QSqlQueryModel *model);
    void on_tabMain_currentChanged();
    void on_cmdExit_clicked();
    void on_cmbLugar_currentIndexChanged();
    void on_cmbUbicacion_currentIndexChanged();
    void on_tblEventos_clicked();
    void on_tblOrganizadores_clicked();
    void on_cmdCheckin_clicked();
    void on_cmdLimpiar_clicked();
    void on_cmdNuevo_clicked();
    void on_cmdEliminar_clicked();
    void on_cmdGuardar_clicked();
    void on_datFechaInicio_dateChanged();
    bool customBox(const char *message, int op);
    void doUpdate(int op);
    void doInsert(int op);
    void on_cmdBuscar_clicked();
    void on_tblLugares_clicked();
    void on_tblUbicaciones_clicked();
    void on_cmdEdit_clicked();
    void on_cmdAdd_clicked();
    void on_cmdRemove_clicked();
    void on_cmdRefresh_clicked();

private:
    Ui::MainCongressMan *ui;
    dbHelper *dbConnection;
};

#endif // MAINCONGRESSMAN_H
