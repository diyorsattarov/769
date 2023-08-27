#include <QApplication>
#include <QtWidgets>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;

    QLabel *queryLabel = new QLabel(QApplication::translate("nestedlayouts", "Query:"));
    QLineEdit *queryEdit = new QLineEdit();
    QTableView *resultView = new QTableView();

    QHBoxLayout *queryLayout = new QHBoxLayout();
    queryLayout->addWidget(queryLabel);
    queryLayout->addWidget(queryEdit);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(queryLayout);
    mainLayout->addWidget(resultView);
    window.setLayout(mainLayout);
    

    window.setWindowTitle(
        QApplication::translate("nestedlayouts", "Nested layout"));
    
    window.show(); // Show the window

    return app.exec(); // Start the Qt event loop
}