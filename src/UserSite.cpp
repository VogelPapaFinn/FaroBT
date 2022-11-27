#include "../include/UserSite.h"

UserSite::UserSite(QWidget* parent) :
    QWidget(parent),
    layout_(new QVBoxLayout()),
    spacer_(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding)),
    db_(nullptr),
    sql_model_(nullptr),
    tv_header_(nullptr),
    table_view_(nullptr)
{
    // Set Layout
    setLayout(layout_);

    // Set Margin
    layout_->setContentsMargins(25, 25, 25, 25);

    // User Site
    QUiLoader ui_loader;
    QFile file(":Sites/forms/UsersSiteBody.ui");
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



    // Establish SQL Connection
    db_ = fbt::SqlConnection::getInstance();

    // Create Table Model
    sql_model_ = new QSqlTableModel();
    sql_model_->setTable("account");
    sql_model_->setEditStrategy(QSqlTableModel::OnFieldChange);     // Edits the database when a cell is edited by the user
    sql_model_->select();
    sql_model_->removeColumn(0);    // Removes account_id
    sql_model_->removeColumn(3);    // Removes password
    sql_model_->removeColumn(3);    // Removes location
    sql_model_->removeColumn(3);    // Removes birth
    sql_model_->removeColumn(5);    // Removes created

    // Temporary saved font to use in the header
    QFont font("Segoe UI", 8, -1, false);
    font.setBold(true);

    // Create Table View
    table_view_ = findChild<QTableView*>("table_view");
    table_view_->setModel(sql_model_);
    if (!db_->isOpen()) table_view_->setModel(new fbt::DefaultTableModel());
    table_view_->verticalHeader()->hide();
    table_view_->show();

    // Style header of the Table View
    tv_header_ = table_view_->horizontalHeader();
    tv_header_->setSectionResizeMode(QHeaderView::Interactive);     // Let the user resize the columns
    tv_header_->setDefaultAlignment(Qt::AlignVCenter);              // Aligns the header text to the left
    tv_header_->setStyleSheet("QHeaderView::section{background-color: #D9D9D9; border: none; border-top: 1px solid #999997; border-bottom: 1px solid #999997; border-right: 1px dashed #999997; padding-left: 3px;}");
    tv_header_->setFont(font);
}


void UserSite::resizeEvent(QResizeEvent* event)
{
    // Resize columns manually - this is to keep the columns stretched but resizable for the user
    for (int i = 0; i < tv_header_->model()->columnCount(); i++) tv_header_->resizeSection(i, table_view_->width() / tv_header_->model()->columnCount());     // This resizes every column to the same size

    // Sets the ResizeMode of the last column to stretched so that the user can resize it. Otherwise the user can move it out of the max width and the scrollbar appears.
    tv_header_->setSectionResizeMode(tv_header_->model()->columnCount() - 1, QHeaderView::Stretch);

    // Handle everything else
    QWidget::resizeEvent(event);
}