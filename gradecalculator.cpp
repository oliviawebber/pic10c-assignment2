#include "gradecalculator.h"
#include "ui_gradecalculator.h"

GradeCalculator::GradeCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GradeCalculator)
{
    ui->setupUi(this);
}

GradeCalculator::~GradeCalculator()
{
    delete ui;
}

void GradeCalculator::compute_grade() const {
    bool schema_a = ui->radioButton->isChecked();
    bool schema_b = ui->radioButton_2->isChecked();

    std::vector<int> hw_grades;
    hw_grades.push_back(ui->spinBox->value());
    hw_grades.push_back(ui->spinBox_9->value());
    hw_grades.push_back(ui->spinBox_10->value());
    hw_grades.push_back(ui->spinBox_11->value());
    hw_grades.push_back(ui->spinBox_12->value());
    hw_grades.push_back(ui->spinBox_13->value());
    hw_grades.push_back(ui->spinBox_15->value());
    hw_grades.push_back(ui->spinBox_14->value());

    double hw_overall = 0;
    for(size_t i = 0; i < hw_grades.size(); ++i) {
        hw_overall += hw_grades[i];
    }
    hw_overall /= hw_grades.size();

    int midterm_1 = ui->spinBox_16->value();
    int midterm_2 = ui->spinBox_17->value();
    int final = ui->spinBox_18->value();

    double overall_grade = 0;

    if(schema_a) {
        overall_grade = (0.25 * hw_overall) + (0.2 * (midterm_1 + midterm_2)) + (.35 * final);
        emit grade_computed(QString::number(overall_grade));
    }
    if(schema_b) {
        double best_midterm;
        if(midterm_1 > midterm_2)
            best_midterm = midterm_1;
        else
            best_midterm = midterm_2;
        overall_grade = (0.25 * hw_overall) + (0.3 * best_midterm) + (.44 * final);
        emit grade_computed(QString::number(overall_grade));
    }
}
