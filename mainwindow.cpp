#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QSignalBlocker>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

#include <algorithm>
#include <iterator>
#include <random>
#include <cctype>


static const std::vector<std::string> kTea = {
    "Чай Лунцзин","Эрл Грей","Сенча","Пуэр","Дарджилинг",
    "Ассам","Матча","Ганпаудер","Оолонг","Лапсанг Сушонг"
};
static const std::vector<std::string> kCakes = {
    "Красный бархат","Наполеон","Медовик","Тирамису","Прага",
    "Чизкейк","Захер","Эстерхази","Морковный торт","Чёрный лес",
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // стартовое состояние
    vector_model_.items.clear();
    vector_model_.iterator = vector_model_.items.begin();

    ApplyModel();
    ApplyIterator();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::SetRandomGen(const std::mt19937& random_gen)
{
    random_gen_ = random_gen;
}

// Элемент/поиск

void MainWindow::on_btn_edit_clicked()
{
    if (vector_model_.iterator != vector_model_.items.end() && !vector_model_.items.empty()) {
        *vector_model_.iterator = ui->txt_elem_content->text().toStdString();
        ApplyModel();
        ApplyIterator();
    }
}

void MainWindow::on_btn_find_clicked()
{
    const QString search = ui->txt_elem_content->text();
    if (search.isEmpty()) return;

    const std::string target = search.toStdString();
    vector_model_.iterator = std::find(vector_model_.items.begin(), vector_model_.items.end(), target);
    ApplyIterator();
}

void MainWindow::on_btn_count_clicked()
{
    const QString search = ui->le_count->text();
    if (search.isEmpty()) return;

    const std::string target = search.toStdString();
    const int count = int(std::count(vector_model_.items.begin(), vector_model_.items.end(), target));
    ui->lbl_count->setText(QString::number(count));
}

// -------------------------------------------------------

void MainWindow::on_pb_pop_front_clicked()
{
    if (!vector_model_.items.empty()) {
        vector_model_.items.erase(vector_model_.items.begin());
        vector_model_.iterator = vector_model_.items.begin();
        ApplyModel();
        ApplyIterator();
    }
}

void MainWindow::on_pb_push_front_clicked()
{
    const QString text = ui->txt_elem_content->text();
    if (text.isEmpty()) return;

    vector_model_.items.insert(vector_model_.items.begin(), text.toStdString());
    vector_model_.iterator = vector_model_.items.begin();
    ApplyModel();
    ApplyIterator();
}

void MainWindow::on_btn_pop_back_clicked()
{
    if (!vector_model_.items.empty()) {
        vector_model_.items.pop_back();
        vector_model_.iterator = vector_model_.items.begin();
        ApplyModel();
        ApplyIterator();
    }
}

void MainWindow::on_btn_push_back_clicked()
{
    const QString text = ui->txt_elem_content->text();
    if (text.isEmpty()) return;

    vector_model_.items.push_back(text.toStdString());
    vector_model_.iterator = vector_model_.items.begin();
    ApplyModel();
    ApplyIterator();
}

void MainWindow::on_btn_clear_clicked()
{
    vector_model_.items.clear();
    vector_model_.iterator = vector_model_.items.begin();
    ApplyModel();
    ApplyIterator();
}

void MainWindow::on_btn_insert_clicked()
{
    const QString text = ui->txt_elem_content->text();
    if (text.isEmpty()) return;

    if (vector_model_.items.empty()) {
        vector_model_.items.push_back(text.toStdString());
    } else if (vector_model_.iterator != vector_model_.items.end()) {
        vector_model_.iterator = vector_model_.items.insert(vector_model_.iterator, text.toStdString());
    } else {
        vector_model_.items.push_back(text.toStdString());
    }

    vector_model_.iterator = vector_model_.items.begin();
    ApplyModel();
    ApplyIterator();
}

void MainWindow::on_btn_erase_clicked()
{
    if (vector_model_.iterator != vector_model_.items.end() && !vector_model_.items.empty()) {
        vector_model_.iterator = vector_model_.items.erase(vector_model_.iterator);
        vector_model_.iterator = vector_model_.items.begin();
        ApplyModel();
        ApplyIterator();
    }
}

// Алгоритмы

void MainWindow::on_btn_min_element_clicked()
{
    if (vector_model_.items.empty()) {
        vector_model_.iterator = vector_model_.items.end();
        ApplyIterator();
        return;
    }
    vector_model_.iterator = std::min_element(vector_model_.items.begin(), vector_model_.items.end());
    ApplyIterator();
}

void MainWindow::on_btn_max_element_clicked()
{
    if (vector_model_.items.empty()) {
        vector_model_.iterator = vector_model_.items.end();
        ApplyIterator();
        return;
    }
    vector_model_.iterator = std::max_element(vector_model_.items.begin(), vector_model_.items.end());
    ApplyIterator();
}

// сорт с регистром
void MainWindow::on_btn_sort_case_insensitive_clicked()
{
    std::sort(vector_model_.items.begin(), vector_model_.items.end());
    vector_model_.iterator = vector_model_.items.begin();
    ApplyModel();
}

// сорт без регистра
void MainWindow::on_btn_sort_clicked()
{
    auto ci_less = [](const std::string &a, const std::string &b){
        std::string la = a, lb = b;
        std::transform(la.begin(), la.end(), la.begin(),
                       [](unsigned char c){ return char(std::tolower(c)); });
        std::transform(lb.begin(), lb.end(), lb.begin(),
                       [](unsigned char c){ return char(std::tolower(c)); });
        if (la == lb) return a < b;
        return la < lb;
    };
    std::stable_sort(vector_model_.items.begin(), vector_model_.items.end(), ci_less);
    vector_model_.iterator = vector_model_.items.begin();
    ApplyModel();
}

void MainWindow::on_btn_unique_clicked()
{
    if (std::is_sorted(vector_model_.items.begin(), vector_model_.items.end())) {
        auto last = std::unique(vector_model_.items.begin(), vector_model_.items.end());
        vector_model_.items.erase(last, vector_model_.items.end());
        ApplyModel();
        ApplyIterator();
    } else {
        qDebug() << "Вектор не отсортирован — операция unique пропущена.";
    }
}

void MainWindow::on_btn_reverse_clicked()
{
    std::reverse(vector_model_.items.begin(), vector_model_.items.end());
    ApplyModel();
    ApplyIterator();
}

void MainWindow::on_btn_shuffle_clicked()
{
    std::shuffle(vector_model_.items.begin(), vector_model_.items.end(), random_gen_);
    ApplyModel();
}

void MainWindow::on_pb_lower_bound_clicked()
{
    if (std::is_sorted(vector_model_.items.begin(), vector_model_.items.end())) {
        const std::string val = ui->txt_elem_content->text().toStdString();
        vector_model_.iterator = std::lower_bound(vector_model_.items.begin(),
                                                  vector_model_.items.end(), val);
        ApplyIterator();
    }
}

void MainWindow::on_pb_upper_bound_clicked()
{
    if (std::is_sorted(vector_model_.items.begin(), vector_model_.items.end())) {
        const std::string val = ui->txt_elem_content->text().toStdString();
        vector_model_.iterator = std::upper_bound(vector_model_.items.begin(),
                                                  vector_model_.items.end(), val);
        if (vector_model_.iterator == vector_model_.items.end()) {
            ui->txt_elem_content->clear();
        }
        ApplyIterator();
    }
}

void MainWindow::on_btn_sort_t_clicked()
{
    std::sort(vector_model_.items.begin(), vector_model_.items.end(),
              [](const std::string& a, const std::string& b){
                  return a.size() > b.size();
              });
    ApplyModel();
}

// Итератор

void MainWindow::on_btn_inc_iterator_clicked()
{
    vector_model_.iterator++;
    ApplyModel();
    ApplyIterator();
}

void MainWindow::on_btn_dec_iterator_clicked()
{
    vector_model_.iterator--;
    ApplyModel();
    ApplyIterator();
}

void MainWindow::on_btn_begin_clicked()
{
    if (!vector_model_.items.empty()) {
        vector_model_.iterator = vector_model_.items.begin();
        ApplyIterator();
    }
}

void MainWindow::on_btn_end_clicked()
{
    if (!vector_model_.items.empty()) {
        vector_model_.iterator = vector_model_.items.end();
        ApplyIterator();
    }
}

// Чай/Торты

void MainWindow::on_btn_weekdays_clicked()
{
    vector_model_.items = kTea;
    vector_model_.iterator = vector_model_.items.begin();
    ApplyModel();
    ApplyIterator();
}

void MainWindow::on_btn_months_clicked()
{
    vector_model_.items = kCakes;
    vector_model_.iterator = vector_model_.items.begin();
    ApplyModel();
    ApplyIterator();
}

// Память resize

void MainWindow::on_btn_resize_clicked()
{
    bool ok = false;
    const int new_size = ui->txt_size->text().toInt(&ok);
    if (ok && new_size >= 0) {
        int current_size = static_cast<int>(vector_model_.items.size());

        if (new_size > current_size) {
            for (int i = current_size; i < new_size; ++i) {
                vector_model_.items.push_back("");
            }
        } else if (new_size < current_size) {
            while (static_cast<int>(vector_model_.items.size()) > new_size) {
                if (vector_model_.iterator != vector_model_.items.end()) {
                    size_t pos = std::distance(vector_model_.items.begin(), vector_model_.iterator);
                    if (pos >= static_cast<size_t>(new_size)) {
                        vector_model_.iterator = vector_model_.items.end();
                    }
                }
                vector_model_.items.pop_back();
            }
        }

        vector_model_.iterator = vector_model_.items.begin();
        ApplyModel();
        ApplyIterator();
    }
}

void MainWindow::ApplyModel()
{
    ui->list_widget->clear();
    ui->txt_size->setText(QString::number(vector_model_.items.size()));

    size_t i = 0;
    for (const auto &s : vector_model_.items) {
        ui->list_widget->addItem(QString::number(int(i)) + ": " + QString::fromStdString(s));
        ++i;
    }
    ui->list_widget->addItem(QStringLiteral("end"));

    const bool is_empty = vector_model_.items.empty();
    if (auto b = findChild<QPushButton*>("pb_pop_front")) b->setDisabled(is_empty);
    if (auto b = findChild<QPushButton*>("btn_pop_back")) b->setDisabled(is_empty);

    ApplyIterator();
}

void MainWindow::ApplyIterator()
{
    if (vector_model_.items.empty()) {
        ui->txt_elem_content->clear();
        ui->btn_edit->setDisabled(true);
        ui->btn_erase->setDisabled(true);
        ui->pb_pop_front->setDisabled(true);
        ui->btn_pop_back->setDisabled(true);

        ui->btn_inc_iterator->setDisabled(true);
        ui->btn_dec_iterator->setDisabled(true);
        ui->btn_begin->setDisabled(true);
        ui->btn_end->setDisabled(true);

        ui->list_widget->setCurrentRow(0);
        return;
    }

    ui->btn_edit->setDisabled(false);
    ui->pb_pop_front->setDisabled(false);
    ui->btn_pop_back->setDisabled(false);
    ui->btn_begin->setDisabled(false);
    ui->btn_end->setDisabled(false);

    int current_pos = -1;
    if (vector_model_.iterator != vector_model_.items.end()) {
        current_pos = std::distance(vector_model_.items.begin(), vector_model_.iterator);
        ui->txt_elem_content->setText(QString::fromStdString(*vector_model_.iterator));
        ui->btn_edit->setDisabled(false);
        ui->btn_erase->setDisabled(false);
    } else {
        current_pos = static_cast<int>(vector_model_.items.size());
        ui->txt_elem_content->clear();
        ui->btn_edit->setDisabled(true);
        ui->btn_erase->setDisabled(true);
    }

    ui->list_widget->setCurrentRow(current_pos);

    ui->btn_dec_iterator->setDisabled(vector_model_.iterator == vector_model_.items.begin());
    ui->btn_inc_iterator->setDisabled(vector_model_.iterator == vector_model_.items.end());
}

void MainWindow::on_list_widget_currentRowChanged(int currentRow)
{
    if (currentRow < 0) return;

    static bool in_progress = false;
    if (in_progress) return;
    in_progress = true;

    vector_model_.iterator = vector_model_.items.begin();
    if (currentRow < static_cast<int>(vector_model_.items.size())) {
        std::advance(vector_model_.iterator, currentRow);
    } else if (currentRow == static_cast<int>(vector_model_.items.size())) {
        vector_model_.iterator = vector_model_.items.end();
    }

    ApplyIterator();
    in_progress = false;
}
