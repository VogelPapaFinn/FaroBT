#pragma once

#include <spdlog/spdlog.h>

#include <qevent.h>
#include <QPainter>
#include <QStyledItemDelegate>

namespace fbt
{
    class TVDelegate : public QStyledItemDelegate
    {
    Q_OBJECT

    public:
        TVDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {};
        void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
        {
            QStyledItemDelegate::paint( painter, option, index );
            painter->setPen( QColor(153, 153, 151));
            painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
        }

    private:
    };
}