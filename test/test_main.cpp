#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;

    QGridLayout *chessboardLayout = new QGridLayout;

    // Create QLabel widgets for the chessboard squares
    QLabel *squares[8][8];
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            squares[row][col] = new QLabel();
            bool isBrownSquare = (row + col) % 2 == 0;
            if (isBrownSquare) {
                squares[row][col]->setStyleSheet("background-color: #D2B48C;"); // Light brown for brown squares
            } else {
                squares[row][col]->setStyleSheet("background-color: #8B4513;"); // Brown for light brown squares
            }
            squares[row][col]->setFixedSize(50, 50);

            chessboardLayout->addWidget(squares[row][col], row, col);
        }
    }

    window.setLayout(chessboardLayout);
    window.setWindowTitle("Chessboard");
    window.show();

    return app.exec();
}
