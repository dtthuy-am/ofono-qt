/*
 * This file is part of ofono-qt
 *
 * Copyright (C) 2010-2011 Nokia Corporation and/or its subsidiary(-ies).
 *
 * Contact: Alexander Kanavin <alex.kanavin@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#ifndef OFONOCALLSETTINGS_H
#define OFONOCALLSETTINGS_H

#include <QtCore/QObject>
#include "ofonomodeminterface.h"
#include "libofono-qt_global.h"

//! This class is used to access oFono call settings API
/*!
 * The API is documented in
 * http://git.kernel.org/?p=network/ofono/ofono.git;a=blob_plain;f=doc/call-settings-api.txt
 */
class OFONO_QT_EXPORT OfonoCallSettings : public OfonoModemInterface
{
    Q_OBJECT

public:
    OfonoCallSettings(OfonoModem::SelectionSetting modemSetting, const QString &modemPath, QObject *parent=0);
    ~OfonoCallSettings();

public Q_SLOTS:
    /* Properties */
    void requestCallingLinePresentation();
    void requestCalledLinePresentation();
    void requestCallingNamePresentation();
    void requestConnectedLinePresentation();
    void requestConnectedLineRestriction();
    void requestCallingLineRestriction();
    void requestHideCallerId();
    void setHideCallerId(const QString &setting);
    void requestVoiceCallWaiting();
    void setVoiceCallWaiting(const QString &setting);
    
Q_SIGNALS:
    void callingLinePresentationComplete(bool success, const QString &setting);
    void calledLinePresentationComplete(bool success, const QString &setting);
    void callingNamePresentationComplete(bool success, const QString &setting);
    void connectedLinePresentationComplete(bool success, const QString &setting);
    void connectedLineRestrictionComplete(bool success, const QString &setting);
    void callingLineRestrictionComplete(bool success, const QString &setting);
    void hideCallerIdComplete(bool success, const QString &setting);
    void voiceCallWaitingComplete(bool success, const QString &setting);

    void callingLinePresentationChanged(const QString &setting);
    void calledLinePresentationChanged(const QString &setting);
    void callingNamePresentationChanged(const QString &setting);
    void connectedLinePresentationChanged(const QString &setting);
    void connectedLineRestrictionChanged(const QString &setting);
    void callingLineRestrictionChanged(const QString &setting);
    void hideCallerIdChanged(const QString &setting);
    void voiceCallWaitingChanged(const QString &setting);

    void setHideCallerIdFailed();
    void setVoiceCallWaitingFailed();

private Q_SLOTS:
    void propertyChanged(const QString& property, const QVariant& value);
    void setPropertyFailed(const QString& property);
    void requestPropertyComplete(bool success, const QString& property, const QVariant& value);      
};

#endif  /* !OFONOCALLSETTINGS_H */
