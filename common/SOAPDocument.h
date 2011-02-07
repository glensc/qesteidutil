/*
 * QEstEidCommon
 *
 * Copyright (C) 2009,2010 Jargo Kõster <jargo@innovaatik.ee>
 * Copyright (C) 2009,2010 Raul Metsma <raul@innovaatik.ee>
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

#include <QXmlStreamWriter>

#define SOAP_ENV			"http://schemas.xmlsoap.org/soap/envelope/"
#define SOAP_ENC			"http://schemas.xmlsoap.org/soap/encoding/"
#define XML_SCHEMA			"http://www.w3.org/2001/XMLSchema"
#define XML_SCHEMA_INSTANCE	"http://www.w3.org/2001/XMLSchema-instance"
#define DIGIDOCSERVICE		"http://www.sk.ee/DigiDocService/DigiDocService_2_3.wsdl"

class QBuffer;

class SOAPDocument: public QXmlStreamWriter
{
public:
	SOAPDocument( const QString &action, const QString &namespaceUri );
	~SOAPDocument();

	QByteArray document() const;
	void finalize();
	void writeParameter( const QString &name, const QVariant &value );

private:
	QBuffer *data;
};
