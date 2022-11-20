#pragma once

#include <qevent.h>

// Definde Event Number
const QEvent::Type GUIBuildEvent = static_cast<QEvent::Type>(QEvent::User + 1);

class FGUIBuild : public QEvent
{
public:
	FGUIBuild();
};

