#ifndef GRADECALCULATOR_H
#define GRADECALCULATOR_H

#include <QMainWindow>
#include <vector>
#include <iostream>

namespace Ui {
class GradeCalculator;
}

class GradeCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit GradeCalculator(QWidget *parent = 0);
    ~GradeCalculator();

private:
    Ui::GradeCalculator *ui;

private slots:
    void compute_grade_a() const;

signals:
    void grade_computed(QString);
};

#endif // GRADECALCULATOR_H
