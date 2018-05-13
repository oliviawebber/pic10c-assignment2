#ifndef GRADECALCULATOR_H
#define GRADECALCULATOR_H

#include <QMainWindow>
#include <vector>
#include <cstdlib>

//Constants


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
    void compute_grade_pic10b() const;
    void compute_grade_pic10c() const;

private slots:
    void compute_grade() const;
    void change_class(int) const;

signals:
    void grade_computed(QString) const;
};

double compute_vector_average(const std::vector<int>&);

#endif // GRADECALCULATOR_H
