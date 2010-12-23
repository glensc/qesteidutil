/*
 * QEstEidCommon
 *
 * Copyright (C) 2010 Jargo Kõster <jargo@innovaatik.ee>
 * Copyright (C) 2010 Raul Metsma <raul@innovaatik.ee>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#pragma once

#include <QMessageBox>

class QDialogButtonBox;

class DMessageBox: public QMessageBox
{
	Q_OBJECT
public:
    explicit DMessageBox( QWidget *parent = 0 );
    DMessageBox( Icon icon, const QString &title, const QString &text,
		StandardButtons buttons = NoButton, QWidget *parent = 0,
		Qt::WindowFlags flags = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint );

protected:
	bool event( QEvent *e );

private Q_SLOTS:
	void fixDetailsLabel();

private:
	QDialogButtonBox *b;
};
