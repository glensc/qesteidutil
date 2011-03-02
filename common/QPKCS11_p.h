/*
 * QDigiDocCommon
 *
 * Copyright (C) 2010-2011 Jargo Kõster <jargo@innovaatik.ee>
 * Copyright (C) 2010-2011 Raul Metsma <raul@innovaatik.ee>
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

#include "QPKCS11.h"

#include "pkcs11.h"

#include <QEventLoop>
#include <QLibrary>
#include <QThread>

class QPKCS11Private
{
public:
	QPKCS11Private()
	: f(0)
	, pslot(0)
	, pslots(0)
	, session(0)
	, nslots(0)
	, err(CKR_OK)
	{}

	bool attribute( CK_OBJECT_HANDLE obj, CK_ATTRIBUTE_TYPE type, void *value, unsigned long &size );
	QSslCertificate readCert( CK_SLOT_ID slot );
	bool findObject( CK_OBJECT_CLASS cls, CK_OBJECT_HANDLE *ret );
	void freeSlotIds();
	bool getSlotsIds();

	QLibrary		lib;
	CK_FUNCTION_LIST *f;
	CK_SLOT_ID		*pslot, *pslots;
	CK_SESSION_HANDLE session;
	unsigned long	nslots, err;
};

class QPKCS11Thread: public QThread
{
	Q_OBJECT
public:
	explicit QPKCS11Thread( QPKCS11Private *p, QObject *parent = 0 )
	: QThread(parent), d(p), result(CKR_OK) {}

	unsigned long waitForDone()
	{
		QEventLoop e;
		connect( this, SIGNAL(finished()), &e, SLOT(quit()) );
		start();
		e.exec();
		return result;
	}

private:
	void run() { result = d->f->C_Login( d->session, CKU_USER, 0, 0 ); }

	QPKCS11Private *d;
	unsigned long result;
};
