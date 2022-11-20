#include "FUserSite.h"

FUserSite::FUserSite(QWidget* parent) : 
	QWidget(parent), 
    layout_(new QVBoxLayout()),
    spacer_(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding))
{
    // Set Layout
    setLayout(layout_);

    // Set Margin
    layout_->setContentsMargins(25, 25, 25, 25);

    // User Site
    QUiLoader ui_loader;
    QFile file(":/Sites/UsersSiteBody.ui");
    file.open(QFile::ReadOnly);
    widget_ = ui_loader.load(&file, this);
    file.close();
    layout_->addWidget(widget_);                // Add to Layout

    // Add Dropshadow
    drop_shadow_effect_ = new QGraphicsDropShadowEffect();
    drop_shadow_effect_->setBlurRadius(15);
    drop_shadow_effect_->setXOffset(0);
    drop_shadow_effect_->setYOffset(0);
    QColor tmp;
    tmp.setRgb(153, 153, 151);
    tmp.setAlphaF(0.3f);
    drop_shadow_effect_->setColor(tmp);
    widget_->setGraphicsEffect(drop_shadow_effect_);
}

void FUserSite::addEntry()
{
    /*
    // Add to table
    QWidget* data_container = findChild<QWidget*>("scroll_area_data_container");

    // Load Row Widget
    std::vector<std::string> labels = {"First Name", "Last Name", "Account Name", "Mail", "Phone"};
    QFrame* tmp = new FScrollAreaRow(labels, nullptr);
    data_container->layout()->removeItem(spacer_);
    data_container->layout()->addWidget(tmp);
    data_container->layout()->addWidget(tmp);
    data_container->layout()->addWidget(tmp);
    data_container->layout()->addWidget(tmp);
    data_container->layout()->addItem(spacer_);*/

    // TESTING

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("bugtracker");
    db.setUserName("postgres");
    db.setPassword("postgres");
    db.open();
    QSqlTableModel* model = new QSqlTableModel;
    model->setTable("account");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();

    QFont font("Segoe UI", 8, -1, false);
    font.setBold(true);

    QTableView* view = findChild<QTableView*>("table_view");
    QHeaderView* header = new QHeaderView(Qt::Horizontal);
    header->setModel(model);
    header->setSectionResizeMode(QHeaderView::Interactive);
    for (int i = 0; i < model->columnCount(); i++) header->resizeSection(i, view->width() / model->columnCount());
    header->setStretchLastSection(true);
    header->setDefaultAlignment(Qt::AlignVCenter);
    header->setStyleSheet("QHeaderView::section{background-color: #D9D9D9; border: none; border-top: 1px solid #999997; border-bottom: 1px solid #999997; border-right: 1px dashed #999997; padding-left: 3px;}");
    header->setFont(font);

    view->setModel(model);
    view->verticalHeader()->hide();
    view->setHorizontalHeader(header);
    view->show();

    // TESTING
}
