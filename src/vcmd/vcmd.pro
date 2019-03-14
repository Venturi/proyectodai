TEMPLATE = app
CONFIG += console cppconn
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -L/usr/lib64/mysql -lmysqlcppconn
SOURCES += main.cpp

