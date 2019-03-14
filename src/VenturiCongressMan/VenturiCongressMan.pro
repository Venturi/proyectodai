#-------------------------------------------------
#
# Project created by QtCreator 2013-05-22T16:10:58
#
#-------------------------------------------------

#
# VenturiCongressMan.pro
#
# Copyright 2013 Manuel Porras Peralta <venturi.debian@gmail.com>
#
#  This file is part of Venturi Congress Manager.
#
#  Venturi Congress Manager is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  Venturi Congress Manager is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with Venturi Congress Manager.  If not, see <http://www.gnu.org/licenses/>.
#

QT  += core gui sql

TARGET = VenturiCongressMan
TEMPLATE = app

SOURCES += main.cpp\
    dbhelper.cpp \
    tablatextaligncenter.cpp \
    maincongressman.cpp

HEADERS  += \
    dbhelper.h \
    tablatextaligncenter.h \
    maincongressman.h

FORMS    += \
    maincongressman.ui

RESOURCES += \
    .resources/images.qrc \
    .resources/db.qrc
