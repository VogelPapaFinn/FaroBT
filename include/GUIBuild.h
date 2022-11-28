#pragma once

#include <QtGui/qevent.h>

// Definde Event Number
const QEvent::Type GUIBuildEvent = static_cast<QEvent::Type>(QEvent::User + 1);

class GUIBuild : public QEvent
{
public:
	GUIBuild();
};

