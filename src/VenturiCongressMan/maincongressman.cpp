/*
 * maincongressman.cpp
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

#include "maincongressman.h"
#include "ui_maincongressman.h"

//Declaración de dos variables para controlar si se ha pulsado en algún registro de alguna pestaña
int indice = -1;
int idxubi = -1;

/********************************************************/
/*          Declaración del interfaz principal          */
/********************************************************/

MainCongressMan::MainCongressMan(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainCongressMan),dbConnection(new dbHelper)
{
    //Conecta a la base de datos y la deja abierta para todas las transacciones durante la ejecución del programa
    if(dbConnection->connect()){
        ui->setupUi(this);
        initUI();
    }
    else {
        customBox("No se encontró dbconf.ini o bien hay algún error de configuración. No se puede acceder a la base de datos. La aplicación se cerrará.",2);
        ui->cmdExit->click();
    }
}

//Destructor de MainCongressMan
MainCongressMan::~MainCongressMan()
{
    delete ui;
}

/********************************************************/
/*                  Pestaña Asistentes                  */
/********************************************************/

//Registra o desregistra la asistencia del visitante que realiza el check-in
void MainCongressMan::on_cmdCheckin_clicked()
{
    QFont f = ui->cmdCheckin->font();
    QSqlQueryModel* model = dynamic_cast<QSqlQueryModel*>(ui->tblAsistente->model());
    QSqlQueryModel* eventoModel = dynamic_cast<QSqlQueryModel*>(ui->cmbEventos->model());
    QString idA = model->record(0).value(0).toString();
    QString idE = eventoModel->record(ui->cmbEventos->currentIndex()).value(0).toString();
    QString checked;
    QStringList cambioCheckin,actualizaAsistente;
    QString nombre = ui->txtNombreAsistente->text();
    QString apellido1 = ui->txtApellido1->text();
    QString apellido2 = ui->txtApellido2->text();
    QString dni = ui->txtDNIAsistente->text();

    if(ui->cmdCheckin->isChecked()){
        f.setBold(true);
        ui->cmdCheckin->setIcon(QIcon(":/icons/dialog-ok-5.png"));
        checked = "1";
    }
    else {
        f.setBold(false);
        ui->cmdCheckin->setIcon(QIcon(":/icons/document-close-2.png"));
        checked = "0";
    }
    cambioCheckin << idE << idA << checked;
    actualizaAsistente << nombre << apellido1 << apellido2 << idE << dni;
    dbConnection->query(18,cambioCheckin);
    ui->tblAsistente->setModel(dbConnection->query(14,actualizaAsistente));
    ui->cmdCheckin->setFont(f);
}

//Busca al asistente por nombre y apellidos o bien por el dni proporcionado, además del evento en el que supuestamente está apuntado
void MainCongressMan::on_cmdBuscar_clicked()
{
    QFont f = ui->cmdCheckin->font();
    int currentIndex = ui->cmbEventos->currentIndex();
    ui->cmbEventos->setModel(dynamic_cast<QAbstractItemModel*>(dbConnection->query(3)));
    ui->cmbEventos->setCurrentIndex(currentIndex);
    ui->cmdCheckin->setChecked(false);
    ui->cmdCheckin->setEnabled(false);
    ui->tblAsistente->setModel(NULL);
    QString nombre = ui->txtNombreAsistente->text();
    QString apellido1 = ui->txtApellido1->text();
    QString apellido2 = ui->txtApellido2->text();
    QString dni = ui->txtDNIAsistente->text();
    int index = ui->cmbEventos->currentIndex();
    if((nombre.isEmpty() || apellido1.isEmpty() || apellido2.isEmpty()) && dni.isEmpty() && index==-1)
        customBox("¡Debe introducir algún criterio de búsqueda!",3);
    else {
        if(ui->cmbEventos->currentIndex()>-1){
            QSqlQueryModel* modelEvento = dynamic_cast<QSqlQueryModel*>(ui->cmbEventos->model());
            QString evento = modelEvento->record(index).value(0).toString();
            if(!(nombre.isEmpty() || apellido1.isEmpty())){
                QStringList fullname;
                fullname << nombre << apellido1 << apellido2 << evento << dni;
                QSqlQueryModel* query = dbConnection->query(14,fullname);
                if(query->rowCount()==1){
                    ui->tblAsistente->setModel(dynamic_cast<QAbstractTableModel*>(query));
                    ui->cmdCheckin->setEnabled(true);
                    if(query->record(0).value(9).toInt()==1)
                    {
                        ui->cmdCheckin->setChecked(true);
                        ui->cmdCheckin->setIcon(QIcon(":/icons/dialog-ok-5.png"));
                    }
                    else
                    {
                        ui->cmdCheckin->setChecked(false);
                        ui->cmdCheckin->setIcon(QIcon(":/icons/document-close-2.png"));
                    }
                    ui->cmbEventos->setEnabled(false);
                }
                else
                    customBox("¡No existe ningún visitante registrado con ese nombre y apellidos en el evento seleccionado o bien el visitante no ha confirmado su registro! Compruebe los datos.",3);
            }
            else if(!dni.isEmpty()){
                QSqlQueryModel* query = dbConnection->query(15,dni,evento);
                if(query->rowCount()==1){
                    ui->tblAsistente->setModel(dynamic_cast<QAbstractTableModel*>(query));
                    ui->cmdCheckin->setEnabled(true);
                    if(query->record(0).value(9).toInt()==1)
                    {
                        ui->cmdCheckin->setChecked(true);
                        ui->cmdCheckin->setIcon(QIcon(":/icons/dialog-ok-5.png"));
                    }
                    else
                    {
                        ui->cmdCheckin->setChecked(false);
                        ui->cmdCheckin->setIcon(QIcon(":/icons/document-close-2.png"));
                    }
                    ui->cmbEventos->setEnabled(false);
                }
                else
                    customBox("¡No existe ningún visitante registrado con ese DNI en el evento seleccionado o bien el visitante no ha confirmado su registro! Compruebe los datos.",3);
            }
            else
                customBox("¡Debe introducir al menos un criterio de búsqueda además del evento (Nombre y primer apellido o bien el DNI del asistente)!",3);
        }
        else
            customBox("¡Debe seleccionar un evento donde buscar!",3);
    }
    if(ui->cmdCheckin->isChecked())
        f.setBold(true);
    else
        f.setBold(false);
    ui->cmdCheckin->setFont(f);
    ui->tblAsistente->setColumnWidth(1,150);
    ui->tblAsistente->setColumnWidth(2,150);
    ui->tblAsistente->setColumnWidth(3,150);
    ui->tblAsistente->setColumnWidth(4,100);
    ui->tblAsistente->setColumnWidth(5,500);
    ui->tblAsistente->hideColumn(0);
    ui->tblAsistente->hideColumn(6);
    ui->tblAsistente->hideColumn(7);
}

/********************************************************/
/*                    Pestaña Eventos                   */
/********************************************************/

//Cambia las ubicaciones dependiendo de qué Lugar se ha elegido en la lista
void MainCongressMan::on_cmbLugar_currentIndexChanged()
{
    ui->cmbUbicacion->setModel(dynamic_cast<QAbstractItemModel*>(dbConnection->query(4,ui->cmbLugar->currentIndex()+1)));
    ui->cmbUbicacion->setModelColumn(1);
}

//Cambia el texto de Aforo según la ubicación seleccionada en QCombobox cmbUbicacion
void MainCongressMan::on_cmbUbicacion_currentIndexChanged()
{
    QSqlQueryModel* model = dynamic_cast<QSqlQueryModel*>(ui->cmbUbicacion->model());
    int aforo = model->record(ui->cmbUbicacion->currentIndex()).value(2).toInt();
    ui->txtAforo->setMaximum(aforo);
    ui->txtAforo->setValue(ui->txtAforo->maximum());
}

//Configura la fecha mínima de finalización del evento en base a la fecha inicial elegida
void MainCongressMan::on_datFechaInicio_dateChanged()
{
    ui->datFechaFin->setMinimumDate(ui->datFechaInicio->date());
}

//Controla a qué evento se le ha hecho click en la tabla QTableView tblEventos
void MainCongressMan::on_tblEventos_clicked()
{
    QSqlQueryModel* organizador = dynamic_cast<QSqlQueryModel*>(ui->cmbOrganizador->model());
    QSqlQueryModel* lugar = dynamic_cast<QSqlQueryModel*>(ui->cmbLugar->model());
    int realIndex = -1;
    QSqlQueryModel* temp = dynamic_cast<QSqlQueryModel*>(ui->tblEventos->model());
    int index = ui->tblEventos->currentIndex().row();
    indice=temp->record(index).value(0).toInt();
    ui->txtNombreEvento->setText(temp->record(index).value(1).toString());
    realIndex = busca(temp->record(index).value(2).toInt(),ui->cmbOrganizador->count(),organizador);
    ui->cmbOrganizador->setCurrentIndex(realIndex);
    realIndex = busca(temp->record(index).value(3).toInt(),ui->cmbLugar->count(),lugar);
    ui->cmbLugar->setCurrentIndex(realIndex);

    //Debí declarar ubicacion aquí porque al depender de que cambie el Lugar seleccionado,
    //me cambiaba el valor del modelo del componente ui->cmbUbicacion almacenado
    QSqlQueryModel* ubicacion = dynamic_cast<QSqlQueryModel*>(ui->cmbUbicacion->model());
    realIndex = busca(temp->record(index).value(4).toInt(),ui->cmbUbicacion->count(),ubicacion);
    ui->cmbUbicacion->setCurrentIndex(realIndex);

    ui->datFechaInicio->setDate(temp->record(index).value(5).toDate());
    ui->datFechaFin->setDate(temp->record(index).value(6).toDate());
    ui->txtAforo->setValue(temp->record(index).value(7).toInt());
    ui->txtNombreEvento->setFocus();
}

/********************************************************/
/*                 Pestaña Organizadores                */
/********************************************************/

//Click en tabla Organizadores
void MainCongressMan::on_tblOrganizadores_clicked()
{
    QSqlQueryModel* temp = dynamic_cast<QSqlQueryModel*>(ui->tblOrganizadores->model());
    int index = ui->tblOrganizadores->currentIndex().row();
    indice=temp->record(index).value(0).toInt();
    ui->txtCIFNIF->setText(temp->record(index).value(1).toString());
    ui->txtNombreOrganizador->setText(temp->record(index).value(2).toString());
    ui->txtContacto->setText(temp->record(index).value(3).toString());
    ui->txtTelefono->setText(temp->record(index).value(4).toString());
    ui->txtEmail->setText(temp->record(index).value(5).toString());
    ui->txtNombreOrganizador->setFocus();
}

/********************************************************/
/*                    Pestaña Lugares                   */
/********************************************************/

//Click en tabla Lugares
void MainCongressMan::on_tblLugares_clicked()
{
    ui->tblUbicaciones->setEnabled(true);
    ui->cmdAdd->setEnabled(true);
    ui->cmdRemove->setEnabled(false);
    ui->cmdEdit->setEnabled(false);
    QSqlQueryModel* temp = dynamic_cast<QSqlQueryModel*>(ui->tblLugares->model());
    int index = ui->tblLugares->currentIndex().row();
    indice=temp->record(index).value(0).toInt();
    ui->txtNombreLugar->setText(temp->record(index).value(1).toString());
    ui->txtDireccion->setText(temp->record(index).value(2).toString());
    ui->txtCiudad->setText(temp->record(index).value(3).toString());
    ui->txtProvincia->setText(temp->record(index).value(4).toString());
    ui->txtMaxAforo->setEnabled(true);
    ui->txtMaxAforo->setValue(0);
    ui->txtNombreUbicacion->clear();
    ui->txtNombreUbicacion->setEnabled(true);
    ui->tblUbicaciones->setModel(dynamic_cast<QAbstractItemModel*>(dbConnection->query(24,indice)));
    ui->tblUbicaciones->setColumnWidth(1,500);
    ui->tblUbicaciones->hideColumn(0);
    ui->tblUbicaciones->hideColumn(3);
    if(dbConnection->query(24,indice)->rowCount()==0)
        ui->txtNombreUbicacion->setFocus();
    else
        ui->txtNombreLugar->setFocus();
}

//Click en tabla Ubicaciones
void MainCongressMan::on_tblUbicaciones_clicked()
{
    ui->cmdAdd->setEnabled(false);
    ui->cmdRemove->setEnabled(true);
    ui->cmdEdit->setEnabled(true);
    QSqlQueryModel* temp = dynamic_cast<QSqlQueryModel*>(ui->tblUbicaciones->model());
    int index = ui->tblUbicaciones->currentIndex().row();
    idxubi=temp->record(index).value(0).toInt();
    ui->txtNombreUbicacion->setText(temp->record(index).value(1).toString());
    ui->txtMaxAforo->setValue(temp->record(index).value(2).toInt());
    ui->txtNombreUbicacion->setFocus();
}

/********************************************************/
/*                   Reset Formularios                  */
/********************************************************/

//Pregunta si desea guardar los cambios o datos, comprueba que lo pueda hacer y finalmente resetea los campos para una nueva entrada
void MainCongressMan::on_cmdNuevo_clicked()
{
    if(ui->tabEventos->isVisible()) { //Si estamos en tabEventos
        resetEventos();
    }
    if(ui->tabOrganizadores->isVisible()){ //Si estamos en Organizadores
        resetOrganizadores();
    }
    if(ui->tabLugares->isVisible()){ //Si estamos en Lugares
        resetLugares();
    }
}

void MainCongressMan::on_cmdLimpiar_clicked()
{
    resetAsistentes();
}

//Limpia el formulario de Eventos
void MainCongressMan::resetEventos()
{
    indice = -1;
    ui->txtNombreEvento->clear();
    ui->txtAforo->setValue(0);
    ui->cmbOrganizador->setCurrentIndex(-1);
    ui->cmbLugar->setCurrentIndex(-1);
    ui->cmbUbicacion->setCurrentIndex(-1);
    ui->txtNombreEvento->setFocus();
    ui->tblEventos->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(3)));
    ui->datFechaInicio->setDate(QDate::currentDate());
    ui->datFechaFin->setDate(QDate::currentDate());
}

//Limpia el formulario de Lugares
void MainCongressMan::resetLugares()
{
    indice = -1;
    ui->tblLugares->setModel(dynamic_cast<QAbstractItemModel*>(dbConnection->query(23)));
    ui->txtNombreLugar->clear();
    ui->txtDireccion->clear();
    ui->txtCiudad->clear();
    ui->txtProvincia->clear();
    ui->tblUbicaciones->setModel(NULL);
    resetUbicaciones();
    ui->txtNombreLugar->setFocus();
}

//Reinicializa el formulario Ubicaciones
void MainCongressMan::resetUbicaciones()
{
    idxubi=-1;
    ui->txtNombreUbicacion->clear();
    ui->txtMaxAforo->setValue(0);
    ui->txtNombreUbicacion->setEnabled(false);
    ui->txtMaxAforo->setEnabled(false);
    ui->cmdAdd->setEnabled(false);
    ui->cmdRemove->setEnabled(false);
    ui->cmdEdit->setEnabled(false);
    ui->txtNombreUbicacion->setFocus();
    ui->tblUbicaciones->setColumnWidth(1,500);
    ui->tblUbicaciones->hideColumn(0);
    ui->tblUbicaciones->hideColumn(3);
}

//Limpia el formulario de Organizadores
void MainCongressMan::resetOrganizadores()
{
    indice = -1;
    ui->txtNombreOrganizador->clear();
    ui->txtCIFNIF->clear();
    ui->txtContacto->clear();
    ui->txtEmail->clear();
    ui->txtTelefono->clear();
    ui->tblOrganizadores->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(16)));
    ui->txtNombreOrganizador->setFocus();
}

//Limpia el formulario de Asistentes
void MainCongressMan::resetAsistentes()
{
    indice = -1;
    ui->txtNombreAsistente->clear();
    ui->txtApellido1->clear();
    ui->txtApellido2->clear();
    ui->txtDNIAsistente->clear();
    ui->cmbEventos->setModel(dynamic_cast<QAbstractItemModel*>(dbConnection->query(3)));
    ui->cmbEventos->setModelColumn(1);
    ui->cmbEventos->setCurrentIndex(-1);
    ui->tblAsistente->setModel(NULL);
    ui->cmdCheckin->setChecked(false);
    ui->cmdCheckin->setEnabled(false);
    ui->cmbEventos->setEnabled(true);
    ui->txtNombreAsistente->setFocus();
}

/********************************************************/
/*                  Funciones Generales                 */
/*                           Y                          */
/*               Funciones de los Botones               */
/********************************************************/

//Inicializa el interfaz de usuario
void MainCongressMan::initUI(){
    //Inicializamos los validadores para los distintos campos de los formularios
    QString strNIF ="\\d{8,8}[a-zA-Z]{1,1}";
    QString strCIFNIF=strNIF+"|[a-zA-Z]{1,1}\\d{8,8}";
    QString strEmail="^[_a-z0-9-]+(.[_a-z0-9-]+)*@[a-z0-9-]+(.[a-z0-9-]+)*(.[a-z]{2,3})$";
    QString strNames=QString::fromUtf8("^([À-Ÿà-ÿa-zA-Z-]{3,40})|([À-Ÿà-ÿa-zA-Z-]{3,20}\\s{1,1}[À-Ÿà-ÿa-zA-Z-]{3,20})$");
    QString strString=QString::fromUtf8("^[À-Ÿà-ÿa-zA-Z0-9 ºª#&()]{3,100}$");
    QString strOtherNames = QString::fromUtf8("^[À-Ÿà-ÿa-zA-Z ]{3,100}$");
    QString strAddress=QString::fromUtf8("^[À-Ÿà-ÿa-zA-Z0-9 ºª#\\-\\/&()\\\\,]{3,200}$");
    QString strTelefono="^([+]{1,1}[0-9]{11,11})|([0-9]{9,9})";
    QRegExp rxNIF(strNIF);
    QRegExp rxCIFNIF(strCIFNIF);
    QRegExp rxEmail(strEmail);
    QRegExp rxString(strNames);
    QRegExp rxExtendedString(strString);
    QRegExp rxAddress(strAddress);
    QRegExp rxTelefono(strTelefono);
    QRegExp rxOtherNames(strOtherNames);
    QRegExpValidator *valNIF = new QRegExpValidator(rxNIF,NULL);
    QRegExpValidator *valCIFNIF = new QRegExpValidator(rxCIFNIF,NULL);
    QRegExpValidator *valEmail = new QRegExpValidator(rxEmail,NULL);
    QRegExpValidator *valString = new QRegExpValidator(rxString,NULL);
    QRegExpValidator *valExtendedString = new QRegExpValidator(rxExtendedString,NULL);
    QRegExpValidator *valAddress = new QRegExpValidator(rxAddress,NULL);
    QRegExpValidator *valTelefono = new QRegExpValidator(rxTelefono,NULL);
    QRegExpValidator *valOtherNames = new QRegExpValidator(rxOtherNames,NULL);
    ui->txtDNIAsistente->setValidator(valNIF);
    ui->txtCIFNIF->setValidator(valCIFNIF);
    ui->txtEmail->setValidator(valEmail);
    ui->txtApellido1->setValidator(valString);
    ui->txtApellido2->setValidator(valString);
    ui->txtContacto->setValidator(valOtherNames);
    ui->txtNombreAsistente->setValidator(valString);
    ui->txtNombreOrganizador->setValidator(valExtendedString);
    ui->txtNombreEvento->setValidator(valExtendedString);
    ui->txtTelefono->setValidator(valTelefono);
    ui->txtDireccion->setValidator(valAddress);
    ui->txtCiudad->setValidator(valOtherNames);
    ui->txtProvincia->setValidator(valOtherNames);
    ui->txtNombreLugar->setValidator(valExtendedString);

    //Inicializamos los componentes de las pestañas de tabMain y el propio tabMain
    ui->tabMain->setCurrentIndex(0);
    ui->cmbOrganizador->setModel(dynamic_cast<QAbstractItemModel*>(dbConnection->query(1)));
    ui->cmbOrganizador->setModelColumn(1);
    ui->cmbOrganizador->setCurrentIndex(-1);
    ui->cmbLugar->setModel(dynamic_cast<QAbstractItemModel*>(dbConnection->query(2)));
    ui->cmbLugar->setModelColumn(1);
    ui->cmbLugar->setCurrentIndex(-1);
    ui->tblEventos->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->tblEventos->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(3)));
    ui->tblEventos->setColumnWidth(1,465);
    ui->tblEventos->setColumnWidth(5,100);
    ui->tblEventos->setColumnWidth(6,100);
    ui->tblEventos->setColumnWidth(7,100);
    ui->tblEventos->hideColumn(0);
    ui->tblEventos->hideColumn(2);
    ui->tblEventos->hideColumn(3);
    ui->tblEventos->hideColumn(4);
    ui->tblAsistente->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->datFechaInicio->setDate(QDate::currentDate());
    ui->datFechaInicio->setMinimumDate(QDate::currentDate());
    ui->datFechaFin->setDate(QDate::currentDate());
    ui->datFechaFin->setMinimumDate(QDate::currentDate());
    ui->cmbEventos->setModel(dynamic_cast<QAbstractItemModel*>(dbConnection->query(3)));
    ui->cmbEventos->setModelColumn(1);
    ui->cmbEventos->setCurrentIndex(-1);
    ui->tblOrganizadores->setModel(dynamic_cast<QAbstractItemModel*>(dbConnection->query(16)));
    ui->tblOrganizadores->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->tblOrganizadores->setColumnWidth(1,100);
    ui->tblOrganizadores->setColumnWidth(2,250);
    ui->tblOrganizadores->setColumnWidth(3,250);
    ui->tblOrganizadores->setColumnWidth(4,140);
    ui->tblOrganizadores->setColumnWidth(5,500);
    ui->tblOrganizadores->hideColumn(0);
    ui->tblLugares->setModel(dynamic_cast<QAbstractItemModel*>(dbConnection->query(23)));
    ui->tblLugares->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->tblLugares->setColumnWidth(1,200);
    ui->tblLugares->setColumnWidth(2,500);
    ui->tblLugares->setColumnWidth(3,200);
    ui->tblLugares->setColumnWidth(4,200);
    ui->tblLugares->hideColumn(0);
    ui->tblUbicaciones->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    ui->tblUbicaciones->setEnabled(false);
    ui->txtNombreUbicacion->setEnabled(false);
    ui->txtMaxAforo->setEnabled(false);
    ui->cmdAdd->setEnabled(false);
    ui->cmdRemove->setEnabled(false);
    ui->cmdEdit->setEnabled(false);

    //Ponemos los botones disabled por estar en la primera pestaña
    ui->cmdEliminar->setEnabled(false);
    ui->cmdGuardar->setEnabled(false);
    ui->cmdNuevo->setEnabled(false);
}

//Controla la salida de la aplicación al pulsar en el botón cmdExit
void MainCongressMan::on_cmdExit_clicked()
{
    dbConnection->close(); //Cerramos la base de datos
    qApp->exit(); //Salimos de la aplicación
}

//Elimina de la base de datos el Evento seleccionado en tblEventos
void MainCongressMan::on_cmdEliminar_clicked()
{
    if(ui->tabEventos->isVisible()){ //Si estamos en tabEventos
        if(ui->tblEventos->currentIndex().row()>-1){
            QSqlQueryModel* temp = dynamic_cast<QSqlQueryModel*>(ui->tblEventos->model());
            QString evento="¿Está seguro de que desea eliminar "+
                    temp->record(ui->tblEventos->currentIndex().row()).value(1).toString().toUtf8()+" de la lista de eventos?";
            if(customBox(evento.toStdString().c_str(),1)){
                int index = ui->tblEventos->currentIndex().row();
                int realIndex = temp->record(index).value(0).toInt();
                dbConnection->query(7,realIndex);
                resetEventos();
                ui->tblEventos->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(3)));
            }
        }
        else
            customBox("Debe elegir primero un evento para eliminarlo",2);
    }
    if(ui->tabOrganizadores->isVisible()){ //Si estamos en tabOrganizadores
        if(ui->tblOrganizadores->currentIndex().row()>-1){
            QSqlQueryModel* temp = dynamic_cast<QSqlQueryModel*>(ui->tblOrganizadores->model());
            QString organizador = "¿Está seguro de que desea eliminar "+
                    temp->record(ui->tblOrganizadores->currentIndex().row()).value(1).toString().toUtf8()+" de la lista de organizadores?";
            if(customBox(organizador.toStdString().c_str(),1)){
                int index = ui->tblOrganizadores->currentIndex().row();
                int realIndex = temp->record(index).value(0).toInt();
                dbConnection->query(17,realIndex);
                resetOrganizadores();
                ui->tblOrganizadores->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(16)));
            }
        }
        else
            customBox("Debe elegir primero un organizador para eliminarlo",2);
    }
    if(ui->tabLugares->isVisible()){ //Si estamos en tabLugares
        if(ui->tblLugares->currentIndex().row()>-1){
            QSqlQueryModel* temp = dynamic_cast<QSqlQueryModel*>(ui->tblLugares->model());
            QString lugares = "¿Está seguro de que desea eliminar "+
                    temp->record(ui->tblLugares->currentIndex().row()).value(1).toString().toUtf8()+
                    " de la lista de lugares disponibles?";
            if(customBox(lugares.toStdString().c_str(),1)){
                int index = ui->tblLugares->currentIndex().row();
                int realIndex = temp->record(index).value(0).toInt();
                dbConnection->query(25,realIndex);
                resetLugares();
                ui->tblLugares->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(23)));
            }
        }
        else
            customBox("Debe elegir primero un organizador para eliminarlo",2);
    }
}

//Limpia los campos de Ubicaciones para poder crear una nueva
void MainCongressMan::on_cmdAdd_clicked()
{
    if(ui->txtNombreUbicacion->text().isEmpty() || ui->txtMaxAforo->value()<1)
        customBox("¡La nueva ubicación debe tener un nombre y un valor para el aforo máximo!",3);
    else
    {
        doInsert(3);
    }
    ui->txtNombreUbicacion->setFocus();
}

//Elimina la ubicación seleccionada
void MainCongressMan::on_cmdRemove_clicked()
{
    if(ui->tblUbicaciones->currentIndex().row()>-1){
        QSqlQueryModel* temp = dynamic_cast<QSqlQueryModel*>(ui->tblUbicaciones->model());
        QString ubicacion = "¿Está seguro de que desea eliminar "+
                temp->record(ui->tblUbicaciones->currentIndex().row()).value(1).toString().toUtf8()+
                " de la lista de ubicaciones?";
        if(customBox(ubicacion.toStdString().c_str(),1)){
            int index = ui->tblUbicaciones->currentIndex().row();
            int realIndex = temp->record(index).value(0).toInt();
            dbConnection->query(33,realIndex);
            ui->txtNombreUbicacion->clear();
            ui->txtMaxAforo->setValue(0);
            ui->txtNombreUbicacion->setEnabled(true);
            ui->txtMaxAforo->setEnabled(true);
            ui->cmdEdit->setEnabled(false);
            ui->cmdRemove->setEnabled(false);
            ui->cmdAdd->setEnabled(true);
            ui->txtNombreUbicacion->setFocus();
            ui->tblUbicaciones->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(24,indice)));
        }
    }
    else
        customBox("Debe elegir primero una ubicación para eliminarla",2);
}

//Guarda el nuevo registro o bien la edición efectuada
void MainCongressMan::on_cmdGuardar_clicked()
{
    if(ui->tabEventos->isVisible()){ //Si estamos en tabEventos
        //Comprobar nombre del evento, si hay dos iguales, comprobar organizador,
        //si coinciden, comprobar lugar, si coinciden, comprobar ubicacion,
        //si coinciden, comprobar fechas
        if(indice>0){
            doUpdate(0);
        }
        else {
            //Insertamos nuevo registro en la tabla Evento
            doInsert(0);
        }
    }
    if(ui->tabOrganizadores->isVisible()){ //Si estamos en tabOrganizadores
        if(indice>0){
            doUpdate(1);
        }
        else {
            //Insertamos nuevo registro en la tabla Organizador
            doInsert(1);
        }
    }
    if(ui->tabLugares->isVisible()){ //Si estamos en tabLugares
        if(indice>0){
            doUpdate(2);
        }
        else {
            //Insertamos nuevo registro en la tabla Lugar
            doInsert(2);
        }
    }
    resetLugares();
    resetUbicaciones();
    ui->txtNombreLugar->setFocus();
}

//Guarda la nueva ubicación o bien la edición efectuada sobre una ya existente
void MainCongressMan::on_cmdEdit_clicked()
{
    doUpdate(3);
}

//Actualiza el registro editado
void MainCongressMan::doUpdate(int op)
{
    QStringList update;
    QSqlQueryModel* fila;
    int index;
    QString indiceUpdate;
    QString nombreUpdate;
    //Campos Evento
    QSqlQueryModel* modelOrganizador;
    QString idorganizadorUpdate;
    QSqlQueryModel* modelLugar;
    QString idlugarUpdate;
    QSqlQueryModel* modelUbicacion;
    QString idubicacionUpdate;
    QString fechainicioUpdate;
    QString fechafinUpdate;
    QString aforoUpdate;
    //Campos Organizador
    QString cifnifUpdate;
    QString telefonoUpdate;
    QString emailUpdate;
    QString contactoUpdate;
    //Campos Lugares
    QString direccionUpdate;
    QString ciudadUpdate;
    QString provinciaUpdate;
    //Campos Ubicación
    QString lugarUpdate;
    QString maxaforoUpdate;

    switch(op)
    {
        case 0:
        fila = dynamic_cast<QSqlQueryModel*>(ui->tblEventos->model());
        index = ui->tblEventos->currentIndex().row();
        indiceUpdate=fila->record(index).value(0).toString();
        nombreUpdate=ui->txtNombreEvento->text();
        modelOrganizador = dynamic_cast<QSqlQueryModel*>(ui->cmbOrganizador->model());
        idorganizadorUpdate = modelOrganizador->record(ui->cmbOrganizador->currentIndex()).value(0).toString();
        modelLugar = dynamic_cast<QSqlQueryModel*>(ui->cmbLugar->model());
        idlugarUpdate = modelLugar->record(ui->cmbLugar->currentIndex()).value(0).toString();
        modelUbicacion = dynamic_cast<QSqlQueryModel*>(ui->cmbUbicacion->model());
        idubicacionUpdate = modelUbicacion->record(ui->cmbUbicacion->currentIndex()).value(0).toString();
        fechainicioUpdate=ui->datFechaInicio->date().toString("yyyy-MM-dd");
        fechafinUpdate=ui->datFechaFin->date().toString("yyyy-MM-dd");
        aforoUpdate=ui->txtAforo->text();
        if(nombreUpdate.isEmpty() || nombreUpdate.isNull() ||
                idorganizadorUpdate.isEmpty() || idorganizadorUpdate.toInt() < 1 ||
                idlugarUpdate.isEmpty() || idlugarUpdate.toInt() < 1||
                idubicacionUpdate.isEmpty() || idubicacionUpdate.toInt() < 1 ||
                fechainicioUpdate.isEmpty() || fechainicioUpdate.isNull() ||
                fechafinUpdate.isEmpty() || fechafinUpdate.isNull() ||
                aforoUpdate.isEmpty() || aforoUpdate.isNull())
        {
            customBox("¡No puede dejar ningún campo sin rellenar!",3);
        }
        else
        {
            update << indiceUpdate << nombreUpdate << idorganizadorUpdate << idlugarUpdate << idubicacionUpdate << fechainicioUpdate << fechafinUpdate << aforoUpdate;
            //Comprueba si el evento completo ya existe en la base de datos pero con otro ID
            if(dbConnection->query(9,update)->rowCount()>0)
               customBox("¡Ya existe un evento con estas características en la base de datos, pero con diferente ID! Compruebe los datos de nuevo.",3);
            else {
                //Comprueba si está intentando guardar un evento con las mismas fechas, aforo, organizador, lugar y ubicación
                if(dbConnection->query(10,update)->rowCount()>0){
                    customBox("¡Ya existe un evento idéntico pero con distinto nombre e ID en la base de datos! El lugar y la ubicación están ocupados en la fecha seleccionada.",3);
                }
                else {
                    dbConnection->query(8,update);
                    ui->tblEventos->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(3)));
                }
            }
        }
        break;
    case 1:
        fila = dynamic_cast<QSqlQueryModel*>(ui->tblOrganizadores->model());
        index = ui->tblOrganizadores->currentIndex().row();
        indiceUpdate=fila->record(index).value(0).toString();
        cifnifUpdate=ui->txtCIFNIF->text();
        nombreUpdate=ui->txtNombreOrganizador->text();
        telefonoUpdate=ui->txtTelefono->text();
        emailUpdate=ui->txtEmail->text();
        contactoUpdate=ui->txtContacto->text();
        if(nombreUpdate.isEmpty() || nombreUpdate.isNull() ||
                cifnifUpdate.isEmpty() || cifnifUpdate.isNull() ||
                telefonoUpdate.isEmpty() || telefonoUpdate.isNull() ||
                emailUpdate.isEmpty() || emailUpdate.isNull() ||
                contactoUpdate.isEmpty() || contactoUpdate.isNull())
        {
            customBox("¡No puede dejar ningún campo sin rellenar!",3);
        }
        else
        {
            update << indiceUpdate << cifnifUpdate << nombreUpdate << contactoUpdate << telefonoUpdate << emailUpdate;
            if(nombreUpdate.isEmpty() || cifnifUpdate.isEmpty() || contactoUpdate.isEmpty() ||
                    nombreUpdate.isNull() || cifnifUpdate.isNull() || contactoUpdate.isNull())
                customBox("Debe rellenar el nombre, el CIF/NIF y el nombre del contacto correctamente, no se admiten campos vacíos. Revíselos.",3);
            else
            {
                //Comprueba si el organizador completo ya existe en la base de datos pero con otro ID
                if(dbConnection->query(20,update)->rowCount()>0)
                   customBox("¡Ya existe un organizador con ese CIF/NIF pero con diferente ID! Compruebe los datos de nuevo.",3);
                else
                {
                    dbConnection->query(19,update);
                    ui->tblOrganizadores->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(16)));
                }
            }
        }
        break;
    case 2:
        fila = dynamic_cast<QSqlQueryModel*>(ui->tblLugares->model());
        index = ui->tblLugares->currentIndex().row();
        indiceUpdate=fila->record(index).value(0).toString();
        nombreUpdate=ui->txtNombreLugar->text();
        direccionUpdate=ui->txtDireccion->text();
        ciudadUpdate=ui->txtCiudad->text();
        provinciaUpdate=ui->txtProvincia->text();
        if(nombreUpdate.isEmpty() || nombreUpdate.isNull() ||
                direccionUpdate.isEmpty() || direccionUpdate.isNull() ||
                ciudadUpdate.isEmpty() || ciudadUpdate.isNull() ||
                provinciaUpdate.isEmpty() || provinciaUpdate.isNull())
        {
            customBox("¡No puede dejar ningún campo sin rellenar!",3);
        }
        else
        {
            update << indiceUpdate << nombreUpdate << direccionUpdate << ciudadUpdate << provinciaUpdate;
            if(nombreUpdate.isEmpty() || direccionUpdate.isEmpty() || ciudadUpdate.isEmpty() || provinciaUpdate.isEmpty() ||
                    nombreUpdate.isNull() || direccionUpdate.isNull() || ciudadUpdate.isNull() || provinciaUpdate.isNull())
                customBox("Ninguno de los campos puede estar vacío. Revíselos.",3);
            else
            {
                //Comprueba si el lugar completo ya existe en la base de datos pero con otro ID
                if(dbConnection->query(28,update)->rowCount()>0)
                   customBox("¡Ya existe un lugar con esas características! Compruebe los datos de nuevo.",3);
                else
                {
                    dbConnection->query(26,update);
                    ui->tblLugares->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(23)));
                }
            }
        }
        break;
    case 3:
        fila = dynamic_cast<QSqlQueryModel*>(ui->tblUbicaciones->model());
        index = ui->tblUbicaciones->currentIndex().row();
        indiceUpdate=fila->record(index).value(0).toString();
        nombreUpdate=ui->txtNombreUbicacion->text();
        maxaforoUpdate=ui->txtMaxAforo->text();
        lugarUpdate=fila->record(index).value(3).toString();
        update << indiceUpdate << nombreUpdate << maxaforoUpdate << lugarUpdate;
        if(nombreUpdate.isEmpty() || maxaforoUpdate.isEmpty() ||
                nombreUpdate.isNull() || maxaforoUpdate.isNull())
            customBox("Ninguno de los dos campos puede estar vacío. Revíselos.",3);
        else
        {
            //Comprueba si la ubicación ya existe en la base de datos por ese mismo nombre
            if(dbConnection->query(32,update)->rowCount()>0)
               customBox("¡Ya existe una ubicación con ese nombre! Compruebe los datos de nuevo.",3);
            else
            {
                dbConnection->query(31,update);
                ui->tblUbicaciones->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(24,lugarUpdate.toInt())));
                ui->cmdRemove->setEnabled(false);
                ui->cmdEdit->setEnabled(false);
                ui->txtNombreUbicacion->clear();
                ui->txtMaxAforo->setValue(0);
                ui->cmdAdd->setEnabled(true);
                ui->txtNombreUbicacion->setFocus();
            }
        }
        break;
    }
}

//Inserta un nuevo registro
void MainCongressMan::doInsert(int op)
{
    QStringList insert;
    QString nombreInsert;
    //Campos Evento
    QSqlQueryModel* modelOrganizador;
    QString idorganizadorInsert;
    QSqlQueryModel* modelLugar;
    QString idlugarInsert;
    QSqlQueryModel* modelUbicacion;
    QString idubicacionInsert;
    QString fechainicioInsert;
    QString fechafinInsert;
    QString aforoInsert;
    //Campos Organizador
    QString cifnifInsert;
    QString telefonoInsert;
    QString emailInsert;
    QString contactoInsert;
    //Campos Lugares
    QString direccionInsert;
    QString ciudadInsert;
    QString provinciaInsert;
    //Campos Ubicación
    QString maxaforoInsert;
    QString lugarInsert;

    switch(op)
    {
    case 0:
        nombreInsert=ui->txtNombreEvento->text();
        modelOrganizador = dynamic_cast<QSqlQueryModel*>(ui->cmbOrganizador->model());
        idorganizadorInsert = modelOrganizador->record(ui->cmbOrganizador->currentIndex()).value(0).toString();
        modelLugar = dynamic_cast<QSqlQueryModel*>(ui->cmbLugar->model());
        idlugarInsert = modelLugar->record(ui->cmbLugar->currentIndex()).value(0).toString();
        modelUbicacion = dynamic_cast<QSqlQueryModel*>(ui->cmbUbicacion->model());
        idubicacionInsert = modelUbicacion->record(ui->cmbUbicacion->currentIndex()).value(0).toString();
        fechainicioInsert=ui->datFechaInicio->date().toString("yyyy-MM-dd");
        fechafinInsert=ui->datFechaFin->date().toString("yyyy-MM-dd");
        aforoInsert=ui->txtAforo->text();
        if(nombreInsert.isEmpty() || nombreInsert.isNull() ||
                idorganizadorInsert.isEmpty() || idorganizadorInsert.toInt() < 1 ||
                idlugarInsert.isEmpty() || idlugarInsert.toInt() < 1 ||
                idubicacionInsert.isEmpty() || idubicacionInsert.toInt() < 1 ||
                fechainicioInsert.isEmpty() || fechainicioInsert.isNull() ||
                fechafinInsert.isEmpty() || fechafinInsert.isNull() ||
                aforoInsert.isEmpty() || aforoInsert.isNull())
        {
            customBox("¡No puede dejar ningún campo sin rellenar!",3);
        }
        else
        {
            insert << nombreInsert << idorganizadorInsert << idlugarInsert << idubicacionInsert << fechainicioInsert << fechafinInsert << aforoInsert;
            //Comprueba si el evento completo ya existe en la base de datos pero con otro ID
            if(dbConnection->query(12,insert)->rowCount()>0)
               customBox("¡Ya existe un evento con estas características en la base de datos, pero con diferente ID! Compruebe los datos de nuevo.",3);
            else {
                //Comprueba si está intentando guardar un evento con las mismas fechas, aforo, organizador, lugar y ubicación
                if(dbConnection->query(13,insert)->rowCount()>0){
                    customBox("¡Ya existe un evento idéntico pero con distinto nombre e ID en la base de datos! El lugar y la ubicación están ocupados en la fecha seleccionada.",3);
                }
                else {
                    dbConnection->query(11,insert);
                    resetEventos();
                    ui->txtNombreEvento->setFocus();
                }
            }
        }
        break;
    case 1:
        cifnifInsert=ui->txtCIFNIF->text();
        nombreInsert=ui->txtNombreOrganizador->text();
        contactoInsert=ui->txtContacto->text();
        telefonoInsert=ui->txtTelefono->text();
        emailInsert=ui->txtEmail->text();
        if(nombreInsert.isEmpty() || nombreInsert.isNull() ||
                cifnifInsert.isEmpty() || cifnifInsert.isNull() ||
                contactoInsert.isEmpty() || contactoInsert.isNull() ||
                telefonoInsert.isEmpty() || telefonoInsert.isNull() ||
                emailInsert.isEmpty() || emailInsert.isNull())
        {
            customBox("¡No puede dejar ningún campo sin rellenar!",3);
        }
        else
        {
            insert << cifnifInsert << nombreInsert << contactoInsert << telefonoInsert << emailInsert;
            //Comprueba si el organizador ya existe en la base de datos pero con otro ID
            if(dbConnection->query(22,insert)->rowCount()>0)
               customBox("¡Ya existe un organizador con ese CIF/NIF en la base de datos! Compruebe los datos de nuevo.",3);
            else {
                dbConnection->query(21,insert);
                ui->tblOrganizadores->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(16)));
            }
        }
        break;
    case 2:
        nombreInsert=ui->txtNombreLugar->text();
        direccionInsert=ui->txtDireccion->text();
        ciudadInsert=ui->txtCiudad->text();
        provinciaInsert=ui->txtProvincia->text();
        if(nombreInsert.isEmpty() || nombreInsert.isNull() ||
                direccionInsert.isEmpty() || direccionInsert.isNull() ||
                ciudadInsert.isEmpty() || ciudadInsert.isNull() ||
                provinciaInsert.isEmpty() || provinciaInsert.isNull())
        {
            customBox("¡No puede dejar ningún campo sin rellenar!",3);
        }
        else
        {
                insert << nombreInsert << direccionInsert << ciudadInsert << provinciaInsert;
            //Comprueba si el organizador ya existe en la base de datos pero con otro ID
            if(dbConnection->query(29,insert)->rowCount()>0)
               customBox("¡Ya existe un lugar con esas características! Compruebe los datos de nuevo.",3);
            else {
                if(dbConnection->query(30,insert)->rowCount()>0)
                   customBox("¡Ya existe un lugar con la misma situación pero con diferente nombre! Compruebe los datos de nuevo.",3);
                else {
                    dbConnection->query(27,insert);
                    ui->tblLugares->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(23)));
                }
            }
        }
        break;
    case 3:
        nombreInsert=ui->txtNombreUbicacion->text();
        maxaforoInsert=ui->txtMaxAforo->text();
        lugarInsert=QString::number(indice);
        if(nombreInsert.isEmpty() || nombreInsert.isNull() ||
                maxaforoInsert.isEmpty() || maxaforoInsert.isNull() ||
                lugarInsert.isEmpty() || lugarInsert.toInt() < 1)
        {
            customBox("¡No puede dejar ningún campo sin rellenar!",3);
        }
        else
        {
            insert << nombreInsert << maxaforoInsert << lugarInsert;
            if(nombreInsert.isEmpty() || maxaforoInsert.isEmpty() || nombreInsert.isNull() || maxaforoInsert.isNull())
                customBox("Ninguno de los dos campos puede estar vacío. Revíselos.",3);
            else
            {
                //Comprueba si la ubicación ya existe en la base de datos pero con otro ID
                if(dbConnection->query(34,insert)->rowCount()>0)
                   customBox("¡Ya existe una ubicación con ese nombre! Compruebe los datos de nuevo.",3);
                else {
                        idxubi=-1;
                        dbConnection->query(35,insert);
                        ui->tblUbicaciones->setModel(dynamic_cast<QAbstractTableModel*>(dbConnection->query(24,lugarInsert.toInt())));
                        ui->tblUbicaciones->setEnabled(true);
                        ui->cmdEdit->setEnabled(false);
                        ui->cmdAdd->setEnabled(true);
                        ui->txtNombreUbicacion->clear();
                        ui->txtMaxAforo->setValue(0);
                        ui->txtNombreUbicacion->setFocus();
                }
            }
        }
        break;
    }
}

void MainCongressMan::on_tabMain_currentChanged(){
    bool activo=true;
    if(ui->tabMain->currentIndex()==0)
        activo=false;
    ui->cmdEliminar->setEnabled(activo);
    ui->cmdGuardar->setEnabled(activo);
    ui->cmdNuevo->setEnabled(activo);
}

//Creamos un MessageBox personalizado para cada información o confirmación que se necesite dar al usuario
bool MainCongressMan::customBox(const char* message, int op)
{
    QMessageBox box;
    QAbstractButton *myYesButton;
    box.setText(trUtf8(message));
    switch (op){
        case 1: //Confirmación
            box.setWindowTitle(trUtf8("Confirmación"));
            myYesButton = box.addButton(trUtf8("Sí"), QMessageBox::YesRole);
            box.addButton(trUtf8("No"), QMessageBox::NoRole);
            box.setIcon(QMessageBox::Critical);
            box.exec();
            if(box.clickedButton()==myYesButton)
                return true;
            break;
        case 2: //Información
            box.setWindowTitle(trUtf8("Información"));
            box.addButton("OK",QMessageBox::AcceptRole);
            box.setIcon(QMessageBox::Information);
            box.exec();
            return true;
            break;
        case 3: //Alerta
            box.setWindowTitle(trUtf8("¡Error!"));
            box.addButton("OK",QMessageBox::AcceptRole);
            box.setIcon(QMessageBox::Critical);
            box.exec();
            return true;
            break;
    }
    return false;
}

//Localiza la posición real de la celda a buscar (what) en las tablas de la base de datos (where)
int MainCongressMan::busca(int what,int lim, QSqlQueryModel* where){
    int i = 0;
    bool found = false;
    while(!found && i<lim){
        if(where->record(i).value(0).toInt()==what)
            found = true;
        else
            i++;
    }
    return i;
}

void MainCongressMan::on_cmdRefresh_clicked(){
  if(customBox("Si continúa, se limpiará el formulario además de actualizar las bases de datos. ¿Desea continuar?",1)){
      if(ui->tabAsistentes->isVisible()){
          resetAsistentes();
        }
      if(ui->tabEventos->isVisible()) { //Si estamos en tabEventos
          resetEventos();
      }
      if(ui->tabOrganizadores->isVisible()){ //Si estamos en Organizadores
          resetOrganizadores();
      }
      if(ui->tabLugares->isVisible()){ //Si estamos en Lugares
          resetLugares();
      }
  }
}
