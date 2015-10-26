/*
 * tablatextaligncenter.cpp
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

#include "tablatextaligncenter.h"

TablaTextAlignCenter::TablaTextAlignCenter(QSqlQueryModel *parent) :
    QSqlQueryModel(parent)
{
}

QVariant TablaTextAlignCenter::data ( const QModelIndex & index, int role ) const
{
    if (role == Qt::TextAlignmentRole)
        return Qt::AlignCenter;
    return QSqlQueryModel::data(index, role);
}
