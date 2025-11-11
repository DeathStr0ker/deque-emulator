/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *list_widget;
    QGridLayout *gridLayout_2;
    QPushButton *btn_sort;
    QPushButton *btn_erase;
    QPushButton *btn_inc_iterator;
    QPushButton *btn_push_back;
    QPushButton *btn_unique;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *txt_elem_content;
    QPushButton *btn_edit;
    QPushButton *btn_find;
    QPushButton *pb_pop_front;
    QLabel *label;
    QPushButton *btn_min_element;
    QPushButton *btn_begin;
    QPushButton *pb_push_front;
    QPushButton *btn_insert;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *le_count;
    QPushButton *btn_count;
    QLabel *lbl_count;
    QLabel *label_4;
    QPushButton *btn_dec_iterator;
    QSpacerItem *verticalSpacer;
    QPushButton *btn_pop_back;
    QPushButton *btn_end;
    QPushButton *btn_months;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *txt_size;
    QPushButton *btn_resize;
    QPushButton *btn_reverse;
    QPushButton *btn_clear;
    QLabel *label_7;
    QPushButton *btn_sort_case_insensitive;
    QPushButton *btn_weekdays;
    QPushButton *btn_max_element;
    QPushButton *btn_shuffle;
    QPushButton *pb_lower_bound;
    QPushButton *pb_upper_bound;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 647);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        list_widget = new QListWidget(centralwidget);
        list_widget->setObjectName("list_widget");

        horizontalLayout_2->addWidget(list_widget);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        btn_sort = new QPushButton(centralwidget);
        btn_sort->setObjectName("btn_sort");

        gridLayout_2->addWidget(btn_sort, 10, 1, 1, 1);

        btn_erase = new QPushButton(centralwidget);
        btn_erase->setObjectName("btn_erase");

        gridLayout_2->addWidget(btn_erase, 6, 1, 1, 1);

        btn_inc_iterator = new QPushButton(centralwidget);
        btn_inc_iterator->setObjectName("btn_inc_iterator");

        gridLayout_2->addWidget(btn_inc_iterator, 15, 1, 1, 1);

        btn_push_back = new QPushButton(centralwidget);
        btn_push_back->setObjectName("btn_push_back");

        gridLayout_2->addWidget(btn_push_back, 5, 1, 1, 1);

        btn_unique = new QPushButton(centralwidget);
        btn_unique->setObjectName("btn_unique");

        gridLayout_2->addWidget(btn_unique, 11, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        txt_elem_content = new QLineEdit(centralwidget);
        txt_elem_content->setObjectName("txt_elem_content");

        horizontalLayout_8->addWidget(txt_elem_content);

        btn_edit = new QPushButton(centralwidget);
        btn_edit->setObjectName("btn_edit");

        horizontalLayout_8->addWidget(btn_edit);

        btn_find = new QPushButton(centralwidget);
        btn_find->setObjectName("btn_find");

        horizontalLayout_8->addWidget(btn_find);


        gridLayout_2->addLayout(horizontalLayout_8, 0, 0, 1, 2);

        pb_pop_front = new QPushButton(centralwidget);
        pb_pop_front->setObjectName("pb_pop_front");

        gridLayout_2->addWidget(pb_pop_front, 4, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 3, 0, 1, 2);

        btn_min_element = new QPushButton(centralwidget);
        btn_min_element->setObjectName("btn_min_element");

        gridLayout_2->addWidget(btn_min_element, 9, 0, 1, 1);

        btn_begin = new QPushButton(centralwidget);
        btn_begin->setObjectName("btn_begin");

        gridLayout_2->addWidget(btn_begin, 16, 0, 1, 1);

        pb_push_front = new QPushButton(centralwidget);
        pb_push_front->setObjectName("pb_push_front");

        gridLayout_2->addWidget(pb_push_front, 4, 1, 1, 1);

        btn_insert = new QPushButton(centralwidget);
        btn_insert->setObjectName("btn_insert");

        gridLayout_2->addWidget(btn_insert, 6, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        le_count = new QLineEdit(centralwidget);
        le_count->setObjectName("le_count");

        horizontalLayout_9->addWidget(le_count);

        btn_count = new QPushButton(centralwidget);
        btn_count->setObjectName("btn_count");

        horizontalLayout_9->addWidget(btn_count);

        lbl_count = new QLabel(centralwidget);
        lbl_count->setObjectName("lbl_count");

        horizontalLayout_9->addWidget(lbl_count);


        gridLayout_2->addLayout(horizontalLayout_9, 2, 0, 1, 2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 14, 0, 1, 2);

        btn_dec_iterator = new QPushButton(centralwidget);
        btn_dec_iterator->setObjectName("btn_dec_iterator");

        gridLayout_2->addWidget(btn_dec_iterator, 15, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 19, 0, 1, 2);

        btn_pop_back = new QPushButton(centralwidget);
        btn_pop_back->setObjectName("btn_pop_back");

        gridLayout_2->addWidget(btn_pop_back, 5, 0, 1, 1);

        btn_end = new QPushButton(centralwidget);
        btn_end->setObjectName("btn_end");

        gridLayout_2->addWidget(btn_end, 16, 1, 1, 1);

        btn_months = new QPushButton(centralwidget);
        btn_months->setObjectName("btn_months");

        gridLayout_2->addWidget(btn_months, 18, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout_6->addWidget(label_3);

        txt_size = new QLineEdit(centralwidget);
        txt_size->setObjectName("txt_size");

        horizontalLayout_6->addWidget(txt_size);

        btn_resize = new QPushButton(centralwidget);
        btn_resize->setObjectName("btn_resize");

        horizontalLayout_6->addWidget(btn_resize);


        gridLayout_2->addLayout(horizontalLayout_6, 24, 0, 1, 2);

        btn_reverse = new QPushButton(centralwidget);
        btn_reverse->setObjectName("btn_reverse");

        gridLayout_2->addWidget(btn_reverse, 11, 1, 1, 1);

        btn_clear = new QPushButton(centralwidget);
        btn_clear->setObjectName("btn_clear");

        gridLayout_2->addWidget(btn_clear, 7, 0, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 8, 0, 1, 2);

        btn_sort_case_insensitive = new QPushButton(centralwidget);
        btn_sort_case_insensitive->setObjectName("btn_sort_case_insensitive");

        gridLayout_2->addWidget(btn_sort_case_insensitive, 10, 0, 1, 1);

        btn_weekdays = new QPushButton(centralwidget);
        btn_weekdays->setObjectName("btn_weekdays");

        gridLayout_2->addWidget(btn_weekdays, 18, 0, 1, 1);

        btn_max_element = new QPushButton(centralwidget);
        btn_max_element->setObjectName("btn_max_element");

        gridLayout_2->addWidget(btn_max_element, 9, 1, 1, 1);

        btn_shuffle = new QPushButton(centralwidget);
        btn_shuffle->setObjectName("btn_shuffle");

        gridLayout_2->addWidget(btn_shuffle, 12, 0, 1, 1);

        pb_lower_bound = new QPushButton(centralwidget);
        pb_lower_bound->setObjectName("pb_lower_bound");

        gridLayout_2->addWidget(pb_lower_bound, 13, 0, 1, 1);

        pb_upper_bound = new QPushButton(centralwidget);
        pb_upper_bound->setObjectName("pb_upper_bound");

        gridLayout_2->addWidget(pb_upper_bound, 13, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 17, 0, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);

        horizontalLayout_2->addLayout(gridLayout_2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        horizontalLayout_3->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "std::vector demo", nullptr));
        btn_sort->setText(QCoreApplication::translate("MainWindow", "merge sOrT", nullptr));
        btn_erase->setText(QCoreApplication::translate("MainWindow", "erase", nullptr));
        btn_inc_iterator->setText(QCoreApplication::translate("MainWindow", "++", nullptr));
        btn_push_back->setText(QCoreApplication::translate("MainWindow", "push_back", nullptr));
        btn_unique->setText(QCoreApplication::translate("MainWindow", "unique", nullptr));
        btn_edit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        btn_find->setText(QCoreApplication::translate("MainWindow", "find", nullptr));
        pb_pop_front->setText(QCoreApplication::translate("MainWindow", "pop_front", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264\321\213", nullptr));
        btn_min_element->setText(QCoreApplication::translate("MainWindow", "min_element", nullptr));
        btn_begin->setText(QCoreApplication::translate("MainWindow", "begin", nullptr));
        pb_push_front->setText(QCoreApplication::translate("MainWindow", "push_front", nullptr));
        btn_insert->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        btn_count->setText(QCoreApplication::translate("MainWindow", "count", nullptr));
        lbl_count->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\230\321\202\320\265\321\200\320\260\321\202\320\276\321\200", nullptr));
        btn_dec_iterator->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        btn_pop_back->setText(QCoreApplication::translate("MainWindow", "pop_back", nullptr));
        btn_end->setText(QCoreApplication::translate("MainWindow", "end", nullptr));
        btn_months->setText(QCoreApplication::translate("MainWindow", "= \321\202\320\276\321\200\321\202\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "size()", nullptr));
        btn_resize->setText(QCoreApplication::translate("MainWindow", "resize", nullptr));
        btn_reverse->setText(QCoreApplication::translate("MainWindow", "reverse", nullptr));
        btn_clear->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274\321\213", nullptr));
        btn_sort_case_insensitive->setText(QCoreApplication::translate("MainWindow", "merge sort", nullptr));
        btn_weekdays->setText(QCoreApplication::translate("MainWindow", "= \321\207\320\260\320\271", nullptr));
        btn_max_element->setText(QCoreApplication::translate("MainWindow", "max_element", nullptr));
        btn_shuffle->setText(QCoreApplication::translate("MainWindow", "shuffle", nullptr));
        pb_lower_bound->setText(QCoreApplication::translate("MainWindow", "lower_bound", nullptr));
        pb_upper_bound->setText(QCoreApplication::translate("MainWindow", "upper_bound", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\320\276\321\202\320\276\320\262\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
