#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;

    // Create a 8x8 grid layout for the chessboard
    QGridLayout *chessboardLayout = new QGridLayout;

    // Create QLabel widgets for the chessboard squares
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            QLabel *square = new QLabel();
            if ((row + col) % 2 == 0) {
                square->setStyleSheet("background-color: white;");
            } else {
                square->setStyleSheet("background-color: black;");
            }
            square->setFixedSize(50, 50); // Adjust the size as needed
            chessboardLayout->addWidget(square, row, col);
        }
    }

    window.setLayout(chessboardLayout);
    window.setWindowTitle("Chessboard");
    window.show();

    return app.exec();
}
