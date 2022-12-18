#include "UserSite/UserSite.h"

UserSite::UserSite(QWidget* parent) :
        QFrame(parent),
        db_(nullptr),
        drop_shadow_effect_(nullptr),
        sql_model_(nullptr),
        tv_header_(nullptr),
        table_view_(nullptr),
        row_counter_(nullptr),
        search_line_(nullptr),
        context_menu_(nullptr)
{
}



void UserSite::customEvent(QEvent* event)
{
    if (event->type() == GUIBuildEvent)
    {
        // Establish SQL Connection
        db_ = fbt::SqlConnection::getInstance();

        // Create Table Model
        sql_model_ = std::make_shared<QSqlTableModel>(new QSqlTableModel());
        sql_model_->setTable("account");
        sql_model_->setEditStrategy(QSqlTableModel::OnManualSubmit);     // Edits the database when a cell is edited by the user
        sql_model_->select();
        sql_model_->removeColumn(0);    // Removes account_id
        sql_model_->removeColumn(3);    // Removes password
        sql_model_->removeColumn(3);    // Removes location
        sql_model_->removeColumn(3);    // Removes birth
        sql_model_->removeColumn(5);    // Removes created
        sql_model_->setHeaderData(0, Qt::Horizontal, "First Name");
        sql_model_->setHeaderData(1, Qt::Horizontal, "Last Name");
        sql_model_->setHeaderData(2, Qt::Horizontal, "Account Name");
        sql_model_->setHeaderData(3, Qt::Horizontal, "Mail");
        sql_model_->setHeaderData(4, Qt::Horizontal, "Phone");

        // Temporarily saved font to use in the header & table
        QFont font("Segoe UI", 11, -1, false);

        // Create Table View
        table_view_ = findChild<QTableView*>("table_view");
        table_view_->setModel(sql_model_.get());
        if (!db_->isOpen()) table_view_->setModel(new fbt::DefaultTableModel());
        table_view_->verticalHeader()->setDefaultSectionSize(35);
        table_view_->verticalHeader()->hide();
        table_view_->setFont(font);
        table_view_->setSelectionBehavior(QAbstractItemView::SelectRows);
        table_view_->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_view_->setItemDelegate(new fbt::TVDelegate(this)); // Draws the grey row spacer-line
        table_view_->setContextMenuPolicy(Qt::CustomContextMenu);
        table_view_->show();

        // Creating context menu
        context_menu_ = new fbt::ContextMenu(table_view_);
        context_menu_->addAction(new QAction("Edit User"));
        context_menu_->addSeparator();
        QAction* del = new QAction("Delete User");
        context_menu_->addAction(del);
        context_menu_->setDefaultAction(del);
        context_menu_->setStyleSheet("QMenu::item:default{color: #760000;}");
        context_menu_->setWindowFlags(Qt::FramelessWindowHint);
        context_menu_->setAttribute(Qt::WA_TranslucentBackground);
        context_menu_->setStyleSheet("QMenu{"
                                     "background-color: white;"
                                     "border-radius: 5px;"
                                     "}"

                                     "QMenu::item{"
                                     "background-color: white;"
                                     "font-size: 14px;"
                                     "margin: 5px 0px 5px 0px;"
                                     "padding: 4px 4px 4px 4px;"
                                     "margin-bottom: 2px;"          // Separator is closer to the action above
                                     "}"

                                     "QMenu::item::selected{"
                                     "border: 0px;"
                                     "background-color: #add8e6;"
                                     "}"

                                     "QMenu::item:default{"
                                     "margin: 0px 0px 5px 0px;"
                                     "color: #760000;"
                                     "}");



        // Style header of the Table View
        tv_header_ = table_view_->horizontalHeader();
        font.setPointSize(8);
        font.setBold(true);
        tv_header_->setFont(font);
        tv_header_->setSectionResizeMode(QHeaderView::Interactive);        // Let the user resize the columns
        tv_header_->setDefaultAlignment(Qt::AlignVCenter);              // Aligns the header text to the left
        tv_header_->setHighlightSections(false);                         // Removes boldness on select
        tv_header_->setStyleSheet("QHeaderView::section{"
                                  "background-color: #D9D9D9;"
                                  "border: 0px;"
                                  "border-top: 1px solid #999997;"
                                  "border-bottom: 1px solid #999997;"
                                  "border-right: 1px dashed #999997;"
                                  "padding-left: 15px;"
                                  "padding-right: 0px;"
                                  "}");

        // Update row counter
        row_counter_ = findChild<QLabel*>("x_found");
        row_counter_->setText(QString::number(sql_model_->rowCount()) + " found");

        // Find search line
        search_line_ = findChild<QLineEdit *>("search_text");



        // Add drop shadow
        drop_shadow_effect_ = std::make_shared<QGraphicsDropShadowEffect>(new QGraphicsDropShadowEffect());
        drop_shadow_effect_->setBlurRadius(15);
        drop_shadow_effect_->setXOffset(0);
        drop_shadow_effect_->setYOffset(0);
        QColor tmp;
        tmp.setRgb(153, 153, 151);
        tmp.setAlphaF(0.3f);
        drop_shadow_effect_->setColor(tmp);
        setGraphicsEffect(drop_shadow_effect_.get());
        context_menu_->setGraphicsEffect(drop_shadow_effect_.get());


        // Connect context menu
        connect(table_view_, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customMenuRequested(QPoint)));

        // Connect refresh button
        QPushButton* refresh = findChild<QPushButton*>("refresh_button");
        connect(refresh, &QPushButton::clicked, this, &UserSite::refreshTableView);

        // Connect search (button)
        QPushButton* search = findChild<QPushButton*>("search_button");
        connect(search, &QPushButton::clicked, this, &UserSite::searchInTableView);

        // Connect search line edit
        QLineEdit *search_line = findChild<QLineEdit *>("search_text");
        connect(search_line, &QLineEdit::editingFinished, this, &UserSite::searchInTableView);

        SPDLOG_LOG_INFO("main", "Received event: GUIBuildEvent");
    }
}

void UserSite::resizeEvent(QResizeEvent* event)
{
    // Is everything ready?
    if (table_view_ == nullptr || sql_model_ == nullptr) return;

    // Resize columns manually - this is to keep the columns stretched but resizable for the user
    for (int i = 0; i < tv_header_->model()->columnCount(); i++) tv_header_->resizeSection(i, table_view_->width() / tv_header_->model()->columnCount());     // This resizes every column to the same size

    // Sets the ResizeMode of the last column to stretched so that the user can resize it. Otherwise, the user can move it out of the max width and the scrollbar appears.
    tv_header_->setSectionResizeMode(tv_header_->model()->columnCount() - 1, QHeaderView::Stretch);

    // Handle everything else
    QWidget::resizeEvent(event);
}



void UserSite::refreshTableView()
{
    // Update rows
    sql_model_->select();

    // Update row counter
    row_counter_->setText(QString::number(sql_model_->rowCount()) + " found");
};

void UserSite::searchInTableView()
{
    // Search for text in the db
    sql_model_->setFilter(QString("first_name LIKE '%") + search_line_->text() + QString("%' or ") +
                          QString("last_name LIKE '%") + search_line_->text() + QString("%' or ") +
                          QString("account_name LIKE '%") + search_line_->text() + QString("%' or ") +
                          QString("location LIKE '%") + search_line_->text() + QString("%' or ") +
                          QString("mail LIKE '%") + search_line_->text() + QString("%' or ") +
                          QString("phone LIKE '%") + search_line_->text() + QString("%'"));

    // Update row counter
    row_counter_->setText(QString::number(sql_model_->rowCount()) + " found");
}

void UserSite::customMenuRequested(QPoint pos)
{
    QModelIndex index = table_view_->indexAt(pos);

    if(index.isValid()) context_menu_->exec(pos);
}