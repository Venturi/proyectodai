/*
 * tablatextaligncenter.h
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

#ifndef TABLATEXTALIGNCENTER_H
#define TABLATEXTALIGNCENTER_H

#include <QtSql>

class TablaTextAlignCenter : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit TablaTextAlignCenter(QSqlQueryModel *parent = 0);
    
signals:
    
public slots:
    QVariant data(const QModelIndex&, int) const;
};

#endif // TABLATEXTALIGNCENTER_H
