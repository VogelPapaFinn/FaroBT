#pragma once

#include <vector>

#include <qevent.h>
#include <qmenu.h>

namespace fbt
{
    class ContextMenu : public QMenu
    {
        Q_OBJECT

    public:
        ContextMenu(QWidget* parent = nullptr) : QMenu(parent) {}
        void closeEvent(QCloseEvent* evt) override
        {
            close();
            evt->accept();
        }

    private:
    };
}

