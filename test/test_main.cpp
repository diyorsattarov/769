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

    // Create QLabel widgets for chess pieces
    QString whitePieces[8] = {"R", "N", "B", "Q", "K", "B", "N", "R"};
    QString blackPieces[8] = {"r", "n", "b", "q", "k", "b", "n", "r"};
    QString whitePawns[8] = {"P", "P", "P", "P", "P", "P", "P", "P"};
    QString blackPawns[8] = {"p", "p", "p", "p", "p", "p", "p", "p"};

    for (int i = 0; i < 8; ++i) {
        QLabel *whitePiece = new QLabel(whitePieces[i]);
        QLabel *blackPiece = new QLabel(blackPieces[i]);
        QLabel *whitePawn = new QLabel(whitePawns[i]);
        QLabel *blackPawn = new QLabel(blackPawns[i]);

        whitePiece->setStyleSheet("QLabel { color: white; background-color: transparent; font-weight: bold; border: 1px solid black; }");
        blackPiece->setStyleSheet("QLabel { color: black; background-color: transparent; font-weight: bold; border: 1px solid white; }");
        whitePawn->setStyleSheet("QLabel { color: white; background-color: transparent; font-weight: bold; border: 1px solid black; }");
        blackPawn->setStyleSheet("QLabel { color: black; background-color: transparent; font-weight: bold; border: 1px solid white; }");

        whitePiece->setAlignment(Qt::AlignCenter);
        blackPiece->setAlignment(Qt::AlignCenter);
        whitePawn->setAlignment(Qt::AlignCenter);
        blackPawn->setAlignment(Qt::AlignCenter);

        whitePiece->setFixedSize(50, 50);
        blackPiece->setFixedSize(50, 50);
        whitePawn->setFixedSize(50, 50);
        blackPawn->setFixedSize(50, 50);

        chessboardLayout->addWidget(whitePiece, 7, i); // White pieces on the bottom
        chessboardLayout->addWidget(blackPiece, 0, i); // Black pieces on the top
        chessboardLayout->addWidget(whitePawn, 6, i); // White pawns on the second row from the bottom
        chessboardLayout->addWidget(blackPawn, 1, i); // Black pawns on the second row from the top
    }

    window.setLayout(chessboardLayout);
    window.setWindowTitle("Chessboard with Pieces");
    window.show();

    return app.exec();
}
