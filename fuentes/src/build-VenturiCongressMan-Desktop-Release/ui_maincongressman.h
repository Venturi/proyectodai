/********************************************************************************
** Form generated from reading UI file 'maincongressman.ui'
**
** Created: Thu Jun 13 22:02:18 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCONGRESSMAN_H
#define UI_MAINCONGRESSMAN_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainCongressMan
{
public:
    QWidget *centralWidget;
    QTabWidget *tabMain;
    QWidget *tabAsistentes;
    QLabel *lblNombreAsistente;
    QLineEdit *txtNombreAsistente;
    QLabel *lblDNIAsistente;
    QLineEdit *txtDNIAsistente;
    QLabel *lblEvento;
    QComboBox *cmbEventos;
    QPushButton *cmdBuscar;
    QTableView *tblAsistente;
    QLabel *lblApellido1;
    QLineEdit *txtApellido1;
    QLabel *lblApellido2;
    QLineEdit *txtApellido2;
    QPushButton *cmdLimpiar;
    QPushButton *cmdCheckin;
    QWidget *tabEventos;
    QLineEdit *txtNombreEvento;
    QLabel *lblNombreEvento;
    QComboBox *cmbOrganizador;
    QLabel *lblOrganizador;
    QLabel *lblLugar;
    QComboBox *cmbLugar;
    QTableView *tblEventos;
    QComboBox *cmbUbicacion;
    QLabel *lblUbicacion;
    QDateEdit *datFechaInicio;
    QDateEdit *datFechaFin;
    QLabel *lblFechaInicio;
    QLabel *lblFechaFin;
    QLabel *lblAforo;
    QSpinBox *txtAforo;
    QWidget *tabOrganizadores;
    QLabel *lblNombreOrganizador;
    QLineEdit *txtNombreOrganizador;
    QLabel *lblCIFNIF;
    QLineEdit *txtCIFNIF;
    QLabel *lblTelefono;
    QLineEdit *txtEmail;
    QLabel *lblEmail;
    QLineEdit *txtTelefono;
    QTableView *tblOrganizadores;
    QLineEdit *txtContacto;
    QLabel *lblContacto;
    QWidget *tabLugares;
    QGroupBox *grbLugares;
    QLabel *lblNombreLugar;
    QLineEdit *txtDireccion;
    QLineEdit *txtCiudad;
    QLineEdit *txtNombreLugar;
    QLabel *lblCiudad;
    QLabel *lblDireccion;
    QLabel *lblProvincia;
    QLineEdit *txtProvincia;
    QTableView *tblLugares;
    QGroupBox *grbUbicaciones;
    QLabel *lblNombreUbicacion;
    QLineEdit *txtNombreUbicacion;
    QTableView *tblUbicaciones;
    QSpinBox *txtMaxAforo;
    QLabel *lblMaxAforo;
    QPushButton *cmdAdd;
    QPushButton *cmdEdit;
    QPushButton *cmdRemove;
    QPushButton *cmdExit;
    QPushButton *cmdGuardar;
    QPushButton *cmdNuevo;
    QPushButton *cmdEliminar;
    QPushButton *cmdRefresh;

    void setupUi(QMainWindow *MainCongressMan)
    {
        if (MainCongressMan->objectName().isEmpty())
            MainCongressMan->setObjectName(QString::fromUtf8("MainCongressMan"));
        MainCongressMan->setWindowModality(Qt::ApplicationModal);
        MainCongressMan->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainCongressMan->sizePolicy().hasHeightForWidth());
        MainCongressMan->setSizePolicy(sizePolicy);
        MainCongressMan->setMinimumSize(QSize(800, 600));
        MainCongressMan->setMaximumSize(QSize(800, 600));
        MainCongressMan->setBaseSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/view-calendar-tasks.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainCongressMan->setWindowIcon(icon);
        MainCongressMan->setWindowOpacity(1);
        MainCongressMan->setIconSize(QSize(40, 40));
        MainCongressMan->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainCongressMan->setDocumentMode(false);
        MainCongressMan->setTabShape(QTabWidget::Rounded);
        MainCongressMan->setUnifiedTitleAndToolBarOnMac(true);
        centralWidget = new QWidget(MainCongressMan);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(800, 600));
        centralWidget->setMaximumSize(QSize(800, 600));
        tabMain = new QTabWidget(centralWidget);
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        tabMain->setGeometry(QRect(0, 0, 801, 561));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabMain->sizePolicy().hasHeightForWidth());
        tabMain->setSizePolicy(sizePolicy1);
        tabMain->setMaximumSize(QSize(801, 561));
        tabMain->setAutoFillBackground(false);
        tabMain->setTabPosition(QTabWidget::North);
        tabMain->setTabShape(QTabWidget::Rounded);
        tabMain->setIconSize(QSize(24, 24));
        tabMain->setDocumentMode(false);
        tabAsistentes = new QWidget();
        tabAsistentes->setObjectName(QString::fromUtf8("tabAsistentes"));
        lblNombreAsistente = new QLabel(tabAsistentes);
        lblNombreAsistente->setObjectName(QString::fromUtf8("lblNombreAsistente"));
        lblNombreAsistente->setGeometry(QRect(10, 90, 81, 19));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblNombreAsistente->sizePolicy().hasHeightForWidth());
        lblNombreAsistente->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(12);
        lblNombreAsistente->setFont(font);
        txtNombreAsistente = new QLineEdit(tabAsistentes);
        txtNombreAsistente->setObjectName(QString::fromUtf8("txtNombreAsistente"));
        txtNombreAsistente->setGeometry(QRect(90, 80, 261, 31));
        txtNombreAsistente->setFont(font);
        txtNombreAsistente->setMaxLength(40);
        lblDNIAsistente = new QLabel(tabAsistentes);
        lblDNIAsistente->setObjectName(QString::fromUtf8("lblDNIAsistente"));
        lblDNIAsistente->setGeometry(QRect(10, 130, 81, 19));
        sizePolicy2.setHeightForWidth(lblDNIAsistente->sizePolicy().hasHeightForWidth());
        lblDNIAsistente->setSizePolicy(sizePolicy2);
        lblDNIAsistente->setFont(font);
        txtDNIAsistente = new QLineEdit(tabAsistentes);
        txtDNIAsistente->setObjectName(QString::fromUtf8("txtDNIAsistente"));
        txtDNIAsistente->setGeometry(QRect(90, 120, 261, 31));
        txtDNIAsistente->setFont(font);
        txtDNIAsistente->setMaxLength(9);
        txtDNIAsistente->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblEvento = new QLabel(tabAsistentes);
        lblEvento->setObjectName(QString::fromUtf8("lblEvento"));
        lblEvento->setGeometry(QRect(10, 160, 81, 19));
        sizePolicy2.setHeightForWidth(lblEvento->sizePolicy().hasHeightForWidth());
        lblEvento->setSizePolicy(sizePolicy2);
        lblEvento->setFont(font);
        cmbEventos = new QComboBox(tabAsistentes);
        cmbEventos->setObjectName(QString::fromUtf8("cmbEventos"));
        cmbEventos->setGeometry(QRect(90, 160, 691, 31));
        cmbEventos->setFont(font);
        cmbEventos->setModelColumn(1);
        cmdBuscar = new QPushButton(tabAsistentes);
        cmdBuscar->setObjectName(QString::fromUtf8("cmdBuscar"));
        cmdBuscar->setGeometry(QRect(320, 200, 161, 31));
        cmdBuscar->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/system-search-4.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdBuscar->setIcon(icon1);
        cmdBuscar->setIconSize(QSize(22, 22));
        tblAsistente = new QTableView(tabAsistentes);
        tblAsistente->setObjectName(QString::fromUtf8("tblAsistente"));
        tblAsistente->setGeometry(QRect(9, 280, 771, 201));
        tblAsistente->setSelectionMode(QAbstractItemView::SingleSelection);
        tblAsistente->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblAsistente->verticalHeader()->setVisible(false);
        lblApellido1 = new QLabel(tabAsistentes);
        lblApellido1->setObjectName(QString::fromUtf8("lblApellido1"));
        lblApellido1->setGeometry(QRect(370, 90, 131, 19));
        sizePolicy2.setHeightForWidth(lblApellido1->sizePolicy().hasHeightForWidth());
        lblApellido1->setSizePolicy(sizePolicy2);
        lblApellido1->setFont(font);
        txtApellido1 = new QLineEdit(tabAsistentes);
        txtApellido1->setObjectName(QString::fromUtf8("txtApellido1"));
        txtApellido1->setGeometry(QRect(520, 80, 261, 31));
        txtApellido1->setFont(font);
        txtApellido1->setMaxLength(40);
        lblApellido2 = new QLabel(tabAsistentes);
        lblApellido2->setObjectName(QString::fromUtf8("lblApellido2"));
        lblApellido2->setGeometry(QRect(370, 130, 151, 19));
        sizePolicy2.setHeightForWidth(lblApellido2->sizePolicy().hasHeightForWidth());
        lblApellido2->setSizePolicy(sizePolicy2);
        lblApellido2->setFont(font);
        txtApellido2 = new QLineEdit(tabAsistentes);
        txtApellido2->setObjectName(QString::fromUtf8("txtApellido2"));
        txtApellido2->setGeometry(QRect(520, 120, 261, 31));
        txtApellido2->setFont(font);
        txtApellido2->setMaxLength(40);
        cmdLimpiar = new QPushButton(tabAsistentes);
        cmdLimpiar->setObjectName(QString::fromUtf8("cmdLimpiar"));
        cmdLimpiar->setGeometry(QRect(320, 240, 161, 31));
        cmdLimpiar->setFont(font);
        cmdCheckin = new QPushButton(tabAsistentes);
        cmdCheckin->setObjectName(QString::fromUtf8("cmdCheckin"));
        cmdCheckin->setEnabled(false);
        cmdCheckin->setGeometry(QRect(520, 200, 261, 71));
        cmdCheckin->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/document-close-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdCheckin->setIcon(icon2);
        cmdCheckin->setIconSize(QSize(32, 32));
        cmdCheckin->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/edit-find-user.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabMain->addTab(tabAsistentes, icon3, QString());
        tabEventos = new QWidget();
        tabEventos->setObjectName(QString::fromUtf8("tabEventos"));
        txtNombreEvento = new QLineEdit(tabEventos);
        txtNombreEvento->setObjectName(QString::fromUtf8("txtNombreEvento"));
        txtNombreEvento->setGeometry(QRect(90, 20, 691, 31));
        txtNombreEvento->setFont(font);
        txtNombreEvento->setMaxLength(100);
        lblNombreEvento = new QLabel(tabEventos);
        lblNombreEvento->setObjectName(QString::fromUtf8("lblNombreEvento"));
        lblNombreEvento->setGeometry(QRect(10, 30, 81, 19));
        sizePolicy2.setHeightForWidth(lblNombreEvento->sizePolicy().hasHeightForWidth());
        lblNombreEvento->setSizePolicy(sizePolicy2);
        lblNombreEvento->setFont(font);
        cmbOrganizador = new QComboBox(tabEventos);
        cmbOrganizador->setObjectName(QString::fromUtf8("cmbOrganizador"));
        cmbOrganizador->setGeometry(QRect(130, 60, 451, 31));
        cmbOrganizador->setFont(font);
        cmbOrganizador->setInsertPolicy(QComboBox::InsertAlphabetically);
        cmbOrganizador->setModelColumn(0);
        lblOrganizador = new QLabel(tabEventos);
        lblOrganizador->setObjectName(QString::fromUtf8("lblOrganizador"));
        lblOrganizador->setGeometry(QRect(10, 70, 121, 19));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lblOrganizador->sizePolicy().hasHeightForWidth());
        lblOrganizador->setSizePolicy(sizePolicy3);
        lblOrganizador->setFont(font);
        lblOrganizador->setScaledContents(false);
        lblOrganizador->setWordWrap(false);
        lblLugar = new QLabel(tabEventos);
        lblLugar->setObjectName(QString::fromUtf8("lblLugar"));
        lblLugar->setGeometry(QRect(10, 110, 71, 19));
        lblLugar->setFont(font);
        cmbLugar = new QComboBox(tabEventos);
        cmbLugar->setObjectName(QString::fromUtf8("cmbLugar"));
        cmbLugar->setGeometry(QRect(130, 100, 451, 31));
        cmbLugar->setFont(font);
        cmbLugar->setInsertPolicy(QComboBox::InsertAlphabetically);
        tblEventos = new QTableView(tabEventos);
        tblEventos->setObjectName(QString::fromUtf8("tblEventos"));
        tblEventos->setGeometry(QRect(10, 180, 771, 341));
        sizePolicy.setHeightForWidth(tblEventos->sizePolicy().hasHeightForWidth());
        tblEventos->setSizePolicy(sizePolicy);
        tblEventos->setProperty("showDropIndicator", QVariant(false));
        tblEventos->setAlternatingRowColors(true);
        tblEventos->setSelectionMode(QAbstractItemView::SingleSelection);
        tblEventos->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblEventos->setTextElideMode(Qt::ElideRight);
        tblEventos->setCornerButtonEnabled(false);
        tblEventos->horizontalHeader()->setCascadingSectionResizes(false);
        tblEventos->horizontalHeader()->setDefaultSectionSize(100);
        tblEventos->horizontalHeader()->setHighlightSections(false);
        tblEventos->horizontalHeader()->setMinimumSectionSize(100);
        tblEventos->horizontalHeader()->setStretchLastSection(false);
        tblEventos->verticalHeader()->setVisible(false);
        tblEventos->verticalHeader()->setHighlightSections(false);
        cmbUbicacion = new QComboBox(tabEventos);
        cmbUbicacion->setObjectName(QString::fromUtf8("cmbUbicacion"));
        cmbUbicacion->setGeometry(QRect(130, 140, 451, 31));
        cmbUbicacion->setFont(font);
        cmbUbicacion->setInsertPolicy(QComboBox::InsertAlphabetically);
        lblUbicacion = new QLabel(tabEventos);
        lblUbicacion->setObjectName(QString::fromUtf8("lblUbicacion"));
        lblUbicacion->setGeometry(QRect(10, 150, 91, 19));
        lblUbicacion->setFont(font);
        datFechaInicio = new QDateEdit(tabEventos);
        datFechaInicio->setObjectName(QString::fromUtf8("datFechaInicio"));
        datFechaInicio->setGeometry(QRect(670, 100, 110, 31));
        datFechaInicio->setFont(font);
        datFechaInicio->setDate(QDate(2013, 1, 1));
        datFechaInicio->setCalendarPopup(true);
        datFechaFin = new QDateEdit(tabEventos);
        datFechaFin->setObjectName(QString::fromUtf8("datFechaFin"));
        datFechaFin->setGeometry(QRect(670, 140, 110, 31));
        datFechaFin->setFont(font);
        datFechaFin->setDate(QDate(2013, 1, 1));
        datFechaFin->setMinimumDate(QDate(2013, 1, 1));
        datFechaFin->setCalendarPopup(true);
        lblFechaInicio = new QLabel(tabEventos);
        lblFechaInicio->setObjectName(QString::fromUtf8("lblFechaInicio"));
        lblFechaInicio->setGeometry(QRect(590, 110, 71, 19));
        sizePolicy3.setHeightForWidth(lblFechaInicio->sizePolicy().hasHeightForWidth());
        lblFechaInicio->setSizePolicy(sizePolicy3);
        lblFechaInicio->setFont(font);
        lblFechaInicio->setScaledContents(false);
        lblFechaInicio->setWordWrap(false);
        lblFechaFin = new QLabel(tabEventos);
        lblFechaFin->setObjectName(QString::fromUtf8("lblFechaFin"));
        lblFechaFin->setGeometry(QRect(590, 150, 71, 19));
        lblFechaFin->setFont(font);
        lblAforo = new QLabel(tabEventos);
        lblAforo->setObjectName(QString::fromUtf8("lblAforo"));
        lblAforo->setGeometry(QRect(590, 70, 81, 19));
        sizePolicy2.setHeightForWidth(lblAforo->sizePolicy().hasHeightForWidth());
        lblAforo->setSizePolicy(sizePolicy2);
        lblAforo->setFont(font);
        txtAforo = new QSpinBox(tabEventos);
        txtAforo->setObjectName(QString::fromUtf8("txtAforo"));
        txtAforo->setGeometry(QRect(670, 60, 111, 31));
        txtAforo->setFont(font);
        txtAforo->setWrapping(false);
        txtAforo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        txtAforo->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/view-calendar-list.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabMain->addTab(tabEventos, icon4, QString());
        tabOrganizadores = new QWidget();
        tabOrganizadores->setObjectName(QString::fromUtf8("tabOrganizadores"));
        lblNombreOrganizador = new QLabel(tabOrganizadores);
        lblNombreOrganizador->setObjectName(QString::fromUtf8("lblNombreOrganizador"));
        lblNombreOrganizador->setGeometry(QRect(10, 30, 111, 19));
        sizePolicy2.setHeightForWidth(lblNombreOrganizador->sizePolicy().hasHeightForWidth());
        lblNombreOrganizador->setSizePolicy(sizePolicy2);
        lblNombreOrganizador->setFont(font);
        txtNombreOrganizador = new QLineEdit(tabOrganizadores);
        txtNombreOrganizador->setObjectName(QString::fromUtf8("txtNombreOrganizador"));
        txtNombreOrganizador->setGeometry(QRect(130, 20, 651, 31));
        txtNombreOrganizador->setFont(font);
        txtNombreOrganizador->setMaxLength(100);
        lblCIFNIF = new QLabel(tabOrganizadores);
        lblCIFNIF->setObjectName(QString::fromUtf8("lblCIFNIF"));
        lblCIFNIF->setGeometry(QRect(10, 70, 81, 19));
        sizePolicy2.setHeightForWidth(lblCIFNIF->sizePolicy().hasHeightForWidth());
        lblCIFNIF->setSizePolicy(sizePolicy2);
        lblCIFNIF->setFont(font);
        txtCIFNIF = new QLineEdit(tabOrganizadores);
        txtCIFNIF->setObjectName(QString::fromUtf8("txtCIFNIF"));
        txtCIFNIF->setGeometry(QRect(130, 60, 261, 31));
        txtCIFNIF->setFont(font);
        txtCIFNIF->setMaxLength(9);
        txtCIFNIF->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblTelefono = new QLabel(tabOrganizadores);
        lblTelefono->setObjectName(QString::fromUtf8("lblTelefono"));
        lblTelefono->setGeometry(QRect(440, 70, 81, 19));
        sizePolicy2.setHeightForWidth(lblTelefono->sizePolicy().hasHeightForWidth());
        lblTelefono->setSizePolicy(sizePolicy2);
        lblTelefono->setFont(font);
        txtEmail = new QLineEdit(tabOrganizadores);
        txtEmail->setObjectName(QString::fromUtf8("txtEmail"));
        txtEmail->setGeometry(QRect(180, 100, 601, 31));
        txtEmail->setFont(font);
        txtEmail->setInputMethodHints(Qt::ImhEmailCharactersOnly);
        txtEmail->setMaxLength(100);
        txtEmail->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblEmail = new QLabel(tabOrganizadores);
        lblEmail->setObjectName(QString::fromUtf8("lblEmail"));
        lblEmail->setGeometry(QRect(10, 110, 161, 20));
        sizePolicy2.setHeightForWidth(lblEmail->sizePolicy().hasHeightForWidth());
        lblEmail->setSizePolicy(sizePolicy2);
        lblEmail->setFont(font);
        txtTelefono = new QLineEdit(tabOrganizadores);
        txtTelefono->setObjectName(QString::fromUtf8("txtTelefono"));
        txtTelefono->setGeometry(QRect(520, 60, 261, 31));
        txtTelefono->setFont(font);
        txtTelefono->setMaxLength(12);
        txtTelefono->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tblOrganizadores = new QTableView(tabOrganizadores);
        tblOrganizadores->setObjectName(QString::fromUtf8("tblOrganizadores"));
        tblOrganizadores->setGeometry(QRect(10, 180, 771, 341));
        tblOrganizadores->setAlternatingRowColors(true);
        tblOrganizadores->setSelectionMode(QAbstractItemView::SingleSelection);
        tblOrganizadores->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblOrganizadores->verticalHeader()->setVisible(false);
        txtContacto = new QLineEdit(tabOrganizadores);
        txtContacto->setObjectName(QString::fromUtf8("txtContacto"));
        txtContacto->setGeometry(QRect(130, 140, 651, 31));
        txtContacto->setFont(font);
        txtContacto->setMaxLength(120);
        txtContacto->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblContacto = new QLabel(tabOrganizadores);
        lblContacto->setObjectName(QString::fromUtf8("lblContacto"));
        lblContacto->setGeometry(QRect(10, 150, 161, 20));
        sizePolicy2.setHeightForWidth(lblContacto->sizePolicy().hasHeightForWidth());
        lblContacto->setSizePolicy(sizePolicy2);
        lblContacto->setFont(font);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/system-switch-user.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabMain->addTab(tabOrganizadores, icon5, QString());
        tabLugares = new QWidget();
        tabLugares->setObjectName(QString::fromUtf8("tabLugares"));
        grbLugares = new QGroupBox(tabLugares);
        grbLugares->setObjectName(QString::fromUtf8("grbLugares"));
        grbLugares->setGeometry(QRect(0, 0, 791, 291));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        grbLugares->setFont(font1);
        grbLugares->setAutoFillBackground(false);
        grbLugares->setAlignment(Qt::AlignCenter);
        grbLugares->setFlat(false);
        grbLugares->setCheckable(false);
        lblNombreLugar = new QLabel(grbLugares);
        lblNombreLugar->setObjectName(QString::fromUtf8("lblNombreLugar"));
        lblNombreLugar->setGeometry(QRect(10, 40, 91, 19));
        sizePolicy2.setHeightForWidth(lblNombreLugar->sizePolicy().hasHeightForWidth());
        lblNombreLugar->setSizePolicy(sizePolicy2);
        lblNombreLugar->setFont(font);
        txtDireccion = new QLineEdit(grbLugares);
        txtDireccion->setObjectName(QString::fromUtf8("txtDireccion"));
        txtDireccion->setGeometry(QRect(100, 70, 681, 31));
        txtDireccion->setFont(font);
        txtDireccion->setMaxLength(200);
        txtCiudad = new QLineEdit(grbLugares);
        txtCiudad->setObjectName(QString::fromUtf8("txtCiudad"));
        txtCiudad->setGeometry(QRect(100, 110, 291, 31));
        txtCiudad->setFont(font);
        txtCiudad->setMaxLength(100);
        txtNombreLugar = new QLineEdit(grbLugares);
        txtNombreLugar->setObjectName(QString::fromUtf8("txtNombreLugar"));
        txtNombreLugar->setGeometry(QRect(100, 30, 681, 31));
        txtNombreLugar->setFont(font);
        txtNombreLugar->setMaxLength(100);
        lblCiudad = new QLabel(grbLugares);
        lblCiudad->setObjectName(QString::fromUtf8("lblCiudad"));
        lblCiudad->setGeometry(QRect(10, 120, 91, 19));
        sizePolicy2.setHeightForWidth(lblCiudad->sizePolicy().hasHeightForWidth());
        lblCiudad->setSizePolicy(sizePolicy2);
        lblCiudad->setFont(font);
        lblDireccion = new QLabel(grbLugares);
        lblDireccion->setObjectName(QString::fromUtf8("lblDireccion"));
        lblDireccion->setGeometry(QRect(10, 80, 91, 19));
        sizePolicy2.setHeightForWidth(lblDireccion->sizePolicy().hasHeightForWidth());
        lblDireccion->setSizePolicy(sizePolicy2);
        lblDireccion->setFont(font);
        lblProvincia = new QLabel(grbLugares);
        lblProvincia->setObjectName(QString::fromUtf8("lblProvincia"));
        lblProvincia->setGeometry(QRect(400, 120, 91, 19));
        sizePolicy2.setHeightForWidth(lblProvincia->sizePolicy().hasHeightForWidth());
        lblProvincia->setSizePolicy(sizePolicy2);
        lblProvincia->setFont(font);
        txtProvincia = new QLineEdit(grbLugares);
        txtProvincia->setObjectName(QString::fromUtf8("txtProvincia"));
        txtProvincia->setGeometry(QRect(490, 110, 291, 31));
        txtProvincia->setFont(font);
        txtProvincia->setMaxLength(100);
        tblLugares = new QTableView(grbLugares);
        tblLugares->setObjectName(QString::fromUtf8("tblLugares"));
        tblLugares->setGeometry(QRect(10, 150, 771, 141));
        tblLugares->setSelectionMode(QAbstractItemView::SingleSelection);
        tblLugares->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblLugares->verticalHeader()->setVisible(false);
        grbUbicaciones = new QGroupBox(tabLugares);
        grbUbicaciones->setObjectName(QString::fromUtf8("grbUbicaciones"));
        grbUbicaciones->setGeometry(QRect(0, 300, 791, 291));
        grbUbicaciones->setFont(font1);
        grbUbicaciones->setAutoFillBackground(false);
        grbUbicaciones->setFlat(false);
        grbUbicaciones->setCheckable(false);
        lblNombreUbicacion = new QLabel(grbUbicaciones);
        lblNombreUbicacion->setObjectName(QString::fromUtf8("lblNombreUbicacion"));
        lblNombreUbicacion->setGeometry(QRect(10, 40, 91, 19));
        sizePolicy2.setHeightForWidth(lblNombreUbicacion->sizePolicy().hasHeightForWidth());
        lblNombreUbicacion->setSizePolicy(sizePolicy2);
        lblNombreUbicacion->setFont(font);
        txtNombreUbicacion = new QLineEdit(grbUbicaciones);
        txtNombreUbicacion->setObjectName(QString::fromUtf8("txtNombreUbicacion"));
        txtNombreUbicacion->setGeometry(QRect(100, 30, 541, 31));
        txtNombreUbicacion->setFont(font);
        txtNombreUbicacion->setMaxLength(100);
        tblUbicaciones = new QTableView(grbUbicaciones);
        tblUbicaciones->setObjectName(QString::fromUtf8("tblUbicaciones"));
        tblUbicaciones->setGeometry(QRect(10, 70, 631, 151));
        tblUbicaciones->setSelectionMode(QAbstractItemView::SingleSelection);
        tblUbicaciones->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblUbicaciones->verticalHeader()->setVisible(false);
        txtMaxAforo = new QSpinBox(grbUbicaciones);
        txtMaxAforo->setObjectName(QString::fromUtf8("txtMaxAforo"));
        txtMaxAforo->setGeometry(QRect(715, 30, 71, 31));
        txtMaxAforo->setFont(font);
        txtMaxAforo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        txtMaxAforo->setAccelerated(true);
        txtMaxAforo->setMaximum(99999);
        lblMaxAforo = new QLabel(grbUbicaciones);
        lblMaxAforo->setObjectName(QString::fromUtf8("lblMaxAforo"));
        lblMaxAforo->setGeometry(QRect(650, 40, 61, 19));
        sizePolicy2.setHeightForWidth(lblMaxAforo->sizePolicy().hasHeightForWidth());
        lblMaxAforo->setSizePolicy(sizePolicy2);
        lblMaxAforo->setFont(font);
        cmdAdd = new QPushButton(grbUbicaciones);
        cmdAdd->setObjectName(QString::fromUtf8("cmdAdd"));
        cmdAdd->setGeometry(QRect(649, 70, 131, 41));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/edit-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdAdd->setIcon(icon6);
        cmdAdd->setIconSize(QSize(32, 32));
        cmdEdit = new QPushButton(grbUbicaciones);
        cmdEdit->setObjectName(QString::fromUtf8("cmdEdit"));
        cmdEdit->setGeometry(QRect(650, 120, 131, 51));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/document-save-as-5.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdEdit->setIcon(icon7);
        cmdEdit->setIconSize(QSize(32, 32));
        cmdRemove = new QPushButton(grbUbicaciones);
        cmdRemove->setObjectName(QString::fromUtf8("cmdRemove"));
        cmdRemove->setGeometry(QRect(650, 180, 131, 41));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/edit-remove-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdRemove->setIcon(icon8);
        cmdRemove->setIconSize(QSize(32, 32));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/document-open-remote.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabMain->addTab(tabLugares, icon9, QString());
        cmdExit = new QPushButton(centralWidget);
        cmdExit->setObjectName(QString::fromUtf8("cmdExit"));
        cmdExit->setGeometry(QRect(690, 563, 100, 31));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/application-exit-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdExit->setIcon(icon10);
        cmdExit->setIconSize(QSize(22, 22));
        cmdGuardar = new QPushButton(centralWidget);
        cmdGuardar->setObjectName(QString::fromUtf8("cmdGuardar"));
        cmdGuardar->setGeometry(QRect(470, 563, 100, 31));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/document-save-as-6.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdGuardar->setIcon(icon11);
        cmdGuardar->setIconSize(QSize(22, 22));
        cmdNuevo = new QPushButton(centralWidget);
        cmdNuevo->setObjectName(QString::fromUtf8("cmdNuevo"));
        cmdNuevo->setGeometry(QRect(360, 563, 100, 31));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/document-new-6.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdNuevo->setIcon(icon12);
        cmdNuevo->setIconSize(QSize(22, 22));
        cmdEliminar = new QPushButton(centralWidget);
        cmdEliminar->setObjectName(QString::fromUtf8("cmdEliminar"));
        cmdEliminar->setGeometry(QRect(580, 563, 100, 31));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/edit-delete-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdEliminar->setIcon(icon13);
        cmdEliminar->setIconSize(QSize(22, 22));
        cmdRefresh = new QPushButton(centralWidget);
        cmdRefresh->setObjectName(QString::fromUtf8("cmdRefresh"));
        cmdRefresh->setGeometry(QRect(10, 563, 100, 31));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/view-refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        cmdRefresh->setIcon(icon14);
        cmdRefresh->setIconSize(QSize(22, 22));
        MainCongressMan->setCentralWidget(centralWidget);
        QWidget::setTabOrder(tabMain, txtNombreAsistente);
        QWidget::setTabOrder(txtNombreAsistente, txtApellido1);
        QWidget::setTabOrder(txtApellido1, txtApellido2);
        QWidget::setTabOrder(txtApellido2, txtDNIAsistente);
        QWidget::setTabOrder(txtDNIAsistente, cmbEventos);
        QWidget::setTabOrder(cmbEventos, cmdBuscar);
        QWidget::setTabOrder(cmdBuscar, cmdLimpiar);
        QWidget::setTabOrder(cmdLimpiar, cmdCheckin);
        QWidget::setTabOrder(cmdCheckin, tblAsistente);
        QWidget::setTabOrder(tblAsistente, txtNombreEvento);
        QWidget::setTabOrder(txtNombreEvento, cmbOrganizador);
        QWidget::setTabOrder(cmbOrganizador, cmbLugar);
        QWidget::setTabOrder(cmbLugar, cmbUbicacion);
        QWidget::setTabOrder(cmbUbicacion, txtAforo);
        QWidget::setTabOrder(txtAforo, datFechaInicio);
        QWidget::setTabOrder(datFechaInicio, datFechaFin);
        QWidget::setTabOrder(datFechaFin, tblEventos);
        QWidget::setTabOrder(tblEventos, txtNombreOrganizador);
        QWidget::setTabOrder(txtNombreOrganizador, txtCIFNIF);
        QWidget::setTabOrder(txtCIFNIF, txtTelefono);
        QWidget::setTabOrder(txtTelefono, txtEmail);
        QWidget::setTabOrder(txtEmail, txtContacto);
        QWidget::setTabOrder(txtContacto, tblOrganizadores);
        QWidget::setTabOrder(tblOrganizadores, txtNombreLugar);
        QWidget::setTabOrder(txtNombreLugar, txtDireccion);
        QWidget::setTabOrder(txtDireccion, txtCiudad);
        QWidget::setTabOrder(txtCiudad, txtProvincia);
        QWidget::setTabOrder(txtProvincia, tblLugares);
        QWidget::setTabOrder(tblLugares, txtNombreUbicacion);
        QWidget::setTabOrder(txtNombreUbicacion, txtMaxAforo);
        QWidget::setTabOrder(txtMaxAforo, tblUbicaciones);
        QWidget::setTabOrder(tblUbicaciones, cmdAdd);
        QWidget::setTabOrder(cmdAdd, cmdEdit);
        QWidget::setTabOrder(cmdEdit, cmdRemove);
        QWidget::setTabOrder(cmdRemove, cmdNuevo);
        QWidget::setTabOrder(cmdNuevo, cmdGuardar);
        QWidget::setTabOrder(cmdGuardar, cmdEliminar);
        QWidget::setTabOrder(cmdEliminar, cmdExit);

        retranslateUi(MainCongressMan);

        tabMain->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainCongressMan);
    } // setupUi

    void retranslateUi(QMainWindow *MainCongressMan)
    {
        MainCongressMan->setWindowTitle(QApplication::translate("MainCongressMan", "Venturi CongressMan", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabAsistentes->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Interfaz para hacer el check-in del asistente</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lblNombreAsistente->setText(QApplication::translate("MainCongressMan", "Nombre:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtNombreAsistente->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Nombre del asistente que desea buscar</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        txtNombreAsistente->setInputMask(QString());
        lblDNIAsistente->setText(QApplication::translate("MainCongressMan", "NIF:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtDNIAsistente->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>DNI con letra del asistente que desea buscar</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        txtDNIAsistente->setInputMask(QString());
        lblEvento->setText(QApplication::translate("MainCongressMan", "Evento:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cmbEventos->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Listado de eventos</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        cmdBuscar->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Busca al asistente en la base datos</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cmdBuscar->setText(QApplication::translate("MainCongressMan", "Buscar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tblAsistente->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Resultado de la b\303\272squeda del asistente</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lblApellido1->setText(QApplication::translate("MainCongressMan", "Primer Apellido:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtApellido1->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Primer apellido del asistente que desea buscar</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        txtApellido1->setInputMask(QString());
        lblApellido2->setText(QApplication::translate("MainCongressMan", "Segundo Apellido:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtApellido2->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Segundo apellido del asistente que desea buscar</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        txtApellido2->setInputMask(QString());
#ifndef QT_NO_TOOLTIP
        cmdLimpiar->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Limpia los campos del formulario para mayor comodidad a la hora de realizar una nueva b\303\272squeda</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cmdLimpiar->setText(QApplication::translate("MainCongressMan", "Nueva b\303\272squeda", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cmdCheckin->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Pulse aqu\303\255 para marcar/desmarcar al asistente como que ha realizado correctamente su check-in</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cmdCheckin->setText(QApplication::translate("MainCongressMan", "Check-in", 0, QApplication::UnicodeUTF8));
        tabMain->setTabText(tabMain->indexOf(tabAsistentes), QApplication::translate("MainCongressMan", "B\303\272squeda de Asistentes", 0, QApplication::UnicodeUTF8));
        tabMain->setTabToolTip(tabMain->indexOf(tabAsistentes), QApplication::translate("MainCongressMan", "<html><head/><body><p>Gesti\303\263n del Check-in de los Asistentes a los Eventos</p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabEventos->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Interfaz para gestionar los eventos en la base de datos</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        txtNombreEvento->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Nombre completo descriptivo del evento</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lblNombreEvento->setText(QApplication::translate("MainCongressMan", "Evento:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cmbOrganizador->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Lista de organizadores disponibles</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lblOrganizador->setText(QApplication::translate("MainCongressMan", "Organizador:", 0, QApplication::UnicodeUTF8));
        lblLugar->setText(QApplication::translate("MainCongressMan", "Lugar:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cmbLugar->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Lugares disponibles donde poder celebrar eventos</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        tblEventos->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Tabla de eventos registrados en la base de datos</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        cmbUbicacion->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Recinto dentro de un lugar seleccionado donde puede celebrarse el evento</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lblUbicacion->setText(QApplication::translate("MainCongressMan", "Ubicaci\303\263n:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        datFechaInicio->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Fecha de inicio del evento</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        datFechaFin->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Fecha de finalizaci\303\263n del evento</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lblFechaInicio->setText(QApplication::translate("MainCongressMan", "Inicio:", 0, QApplication::UnicodeUTF8));
        lblFechaFin->setText(QApplication::translate("MainCongressMan", "Fin:", 0, QApplication::UnicodeUTF8));
        lblAforo->setText(QApplication::translate("MainCongressMan", "Aforo:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtAforo->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Capacidad de la ubicaci\303\263n seleccionada donde se realizar\303\241 el evento (cada ubicaci\303\263n tiene un aforo m\303\241ximo)</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabMain->setTabText(tabMain->indexOf(tabEventos), QApplication::translate("MainCongressMan", "Eventos", 0, QApplication::UnicodeUTF8));
        tabMain->setTabToolTip(tabMain->indexOf(tabEventos), QApplication::translate("MainCongressMan", "Gesti\303\263n de Eventos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabOrganizadores->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Interfaz para gestionar los organizadores en la base de datos</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lblNombreOrganizador->setText(QApplication::translate("MainCongressMan", "Organizador:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtNombreOrganizador->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Nombre de la empresa, organismo o persona f\303\255sica que organiza eventos</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lblCIFNIF->setText(QApplication::translate("MainCongressMan", "CIF/NIF:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtCIFNIF->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>CIF/NIF del organizador del evento</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lblTelefono->setText(QApplication::translate("MainCongressMan", "Tel\303\251fono:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtEmail->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Direcci\303\263n de correo electr\303\263nico de contacto con el organizador del evento</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        txtEmail->setText(QString());
        lblEmail->setText(QApplication::translate("MainCongressMan", "Correo electr\303\263nico:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtTelefono->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Tel\303\251fono de contacto con el organizador. No incluye separadores, ejemplo:</p><p>+34902902902 -&gt; Correcto</p><p>902902902 -&gt; Correcto</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        tblOrganizadores->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Tabla de organizadores registrados en la base de datos</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        txtContacto->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Nombre completo o parcial de la persona a contactar relativa al organizador del evento</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        txtContacto->setText(QString());
        lblContacto->setText(QApplication::translate("MainCongressMan", "Contacto:", 0, QApplication::UnicodeUTF8));
        tabMain->setTabText(tabMain->indexOf(tabOrganizadores), QApplication::translate("MainCongressMan", "Organizadores", 0, QApplication::UnicodeUTF8));
        tabMain->setTabToolTip(tabMain->indexOf(tabOrganizadores), QApplication::translate("MainCongressMan", "<html><head/><body><p>Gesti\303\263n de Organizadores de los Eventos</p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabLugares->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Interfaz para gestionar los lugares disponibles para la realizaci\303\263n de los eventos</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        grbLugares->setTitle(QApplication::translate("MainCongressMan", "Gesti\303\263n de Lugares", 0, QApplication::UnicodeUTF8));
        lblNombreLugar->setText(QApplication::translate("MainCongressMan", "Lugar:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtDireccion->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Direcci\303\263n donde est\303\241 situado el lugar</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        txtCiudad->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Direcci\303\263n donde est\303\241 situado el lugar</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        txtNombreLugar->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Lugar donde se puede celebrar un evento</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lblCiudad->setText(QApplication::translate("MainCongressMan", "Ciudad:", 0, QApplication::UnicodeUTF8));
        lblDireccion->setText(QApplication::translate("MainCongressMan", "Direcci\303\263n:", 0, QApplication::UnicodeUTF8));
        lblProvincia->setText(QApplication::translate("MainCongressMan", "Provincia:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtProvincia->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Direcci\303\263n donde est\303\241 situado el lugar</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        grbUbicaciones->setTitle(QApplication::translate("MainCongressMan", "Gesti\303\263n de Ubicaciones del Lugar", 0, QApplication::UnicodeUTF8));
        lblNombreUbicacion->setText(QApplication::translate("MainCongressMan", "Ubicaci\303\263n:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        txtNombreUbicacion->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Nombre de la ubicaci\303\263n perteneciente al Lugar seleccionado</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        tblUbicaciones->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Tabla de ubicaciones para el Lugar seleccionado</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        txtMaxAforo->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Aforo m\303\241ximo de la ubicaci\303\263n</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lblMaxAforo->setText(QApplication::translate("MainCongressMan", "Aforo:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cmdAdd->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>A\303\261ade una ubicaci\303\263n al Lugar seleccionado</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cmdAdd->setText(QString());
#ifndef QT_NO_TOOLTIP
        cmdEdit->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Guarda la ubicaci\303\263n actual</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cmdEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        cmdRemove->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Elimina la ubicaci\303\263n actual del Lugar seleccionado</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cmdRemove->setText(QString());
        tabMain->setTabText(tabMain->indexOf(tabLugares), QApplication::translate("MainCongressMan", "Lugares", 0, QApplication::UnicodeUTF8));
        tabMain->setTabToolTip(tabMain->indexOf(tabLugares), QApplication::translate("MainCongressMan", "<html><head/><body><p>Gesti\303\263n de los Lugares disponibles para la celebraci\303\263n de los Eventos</p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cmdExit->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Cierra la aplicaci\303\263n</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cmdExit->setText(QApplication::translate("MainCongressMan", "&Salir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cmdGuardar->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Guarda los cambios hechos en el registro actual</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cmdGuardar->setText(QApplication::translate("MainCongressMan", "&Guardar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cmdNuevo->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Inicializa el formulario para que pueda crear un registro nuevo</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cmdNuevo->setText(QApplication::translate("MainCongressMan", "&Nuevo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cmdEliminar->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Elimina el registro seleccionado</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cmdEliminar->setText(QApplication::translate("MainCongressMan", "&Eliminar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cmdRefresh->setToolTip(QApplication::translate("MainCongressMan", "<html><head/><body><p>Sincroniza la base de datos actual de la secci\303\263n que est\303\251 utilizando del programa con la base de datos del servidor. \302\241Tambi\303\251n se inicializar\303\241 el formulario que est\303\251 editando, as\303\255 que sincronice una vez haya terminado cualquier edici\303\263n!</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cmdRefresh->setText(QApplication::translate("MainCongressMan", "&Actualizar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainCongressMan: public Ui_MainCongressMan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCONGRESSMAN_H
