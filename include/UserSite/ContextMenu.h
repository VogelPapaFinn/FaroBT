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
            if (!geometry().contains(QCursor::pos()))
            {
                QAction* tmp = actionAt(QCursor::pos());
                if(tmp != nullptr) if(!tmp->isSeparator()) tmp->trigger();
                evt->accept();
            }
            else
                evt->ignore();
        }

    private:
    };
}

