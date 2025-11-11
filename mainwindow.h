#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <random>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Model {
    using container = std::vector<std::string>;
    container items;
    container::iterator iterator;
    Model() : items(), iterator(items.begin()) {}
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void SetRandomGen(const std::mt19937& random_gen);

private slots:
    void on_btn_push_back_clicked();
    void on_btn_pop_back_clicked();
    void on_btn_clear_clicked();

    void on_btn_weekdays_clicked(); // Чай
    void on_btn_months_clicked(); // Торты
    void on_btn_edit_clicked();

    void on_btn_dec_iterator_clicked();
    void on_btn_inc_iterator_clicked();
    void on_btn_begin_clicked();

    void on_btn_end_clicked();
    void on_btn_erase_clicked();
    void on_btn_insert_clicked();

    void on_list_widget_currentRowChanged(int currentRow);
    void on_btn_resize_clicked();
    void on_btn_find_clicked();

    void on_btn_count_clicked();
    void on_btn_min_element_clicked();
    void on_btn_max_element_clicked();

    void on_btn_sort_clicked();
    void on_btn_sort_case_insensitive_clicked();
    void on_btn_shuffle_clicked();

    void on_btn_unique_clicked();
    void on_btn_reverse_clicked();
    void on_btn_sort_t_clicked();
    
    void on_pb_lower_bound_clicked();
    void on_pb_upper_bound_clicked();
    void on_pb_pop_front_clicked();
    void on_pb_push_front_clicked();

private:
    void ApplyModel();
    void ApplyIterator();

    Ui::MainWindow *ui;
    Model vector_model_;
    std::mt19937 random_gen_{ std::random_device{}() };
};

#endif
