#include <QApplication>
#include <QtWidgets>

// Function to create a QLabel for chess pieces with styled text
QLabel* createPieceLabel(const QString& pieceText, bool isBlue)
{
    QLabel* label = new QLabel(pieceText);
    label->setAlignment(Qt::AlignCenter);

    // Set text colors and outline based on piece color
    if (isBlue) {
        label->setStyleSheet("QLabel { color: blue; background-color: transparent; font-weight: bold; border: 1px solid black; }");
    } else {
        label->setStyleSheet("QLabel { color: red; background-color: transparent; font-weight: bold; border: 1px solid black; }");
    }

    label->setFixedSize(50, 50);
    return label;
}

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
            bool isWhiteSquare = (row + col) % 2 == 0;
            if (isWhiteSquare) {
                squares[row][col]->setStyleSheet("background-color: white;");
            } else {
                squares[row][col]->setStyleSheet("background-color: black;");
            }
            squares[row][col]->setFixedSize(50, 50);

            // Add chess pieces with styled text
            QString pieceText = "";
            bool isBluePiece = row == 1; // Second row is for blue pieces
            bool isRedPiece = row == 6;  // Second-to-last row is for red pieces
            if (isBluePiece || isRedPiece) {
                pieceText = "P"; // Pawn
            } else if ((row == 0 || row == 7) && (col == 0 || col == 7)) {
                pieceText = "R"; // Rook
            } else if ((row == 0 || row == 7) && (col == 1 || col == 6)) {
                pieceText = "N"; // Knight
            } else if ((row == 0 || row == 7) && (col == 2 || col == 5)) {
                pieceText = "B"; // Bishop
            } else if ((row == 0 || row == 7) && col == 3) {
                pieceText = "Q"; // Queen
            } else if ((row == 0 || row == 7) && col == 4) {
                pieceText = "K"; // King
            }
            
            QLabel* pieceLabel = createPieceLabel(pieceText, isBluePiece || isRedPiece);
            chessboardLayout->addWidget(pieceLabel, row, col);
        }
    }

    window.setLayout(chessboardLayout);
    window.setWindowTitle("Chessboard with Pieces");
    window.show();

    return app.exec();
}
