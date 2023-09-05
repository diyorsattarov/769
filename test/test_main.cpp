#include <QApplication>
#include <QtWidgets>

// Define a class for chess squares
class ChessSquare : public QLabel {
public:
    ChessSquare(bool isBrown) {
        setFixedSize(50, 50);
        if (isBrown) {
            setStyleSheet("background-color: #D2B48C;");
        } else {
            setStyleSheet("background-color: #8B4513;");
        }
    }
};

// Define a class for chess pieces
class ChessPiece : public QLabel {
    Q_OBJECT

public:
    ChessPiece(const QString& text, bool isWhite) : isWhite(isWhite), isSelected(false) {
        setText(text);
        setAlignment(Qt::AlignCenter);
        setFixedSize(50, 50);
        updateStyle(); // Initialize style
    }

protected:
    void mousePressEvent(QMouseEvent* event) override {
        // Handle mouse click event
        if (!isSelected) {
            setSelected(true);
            emit pieceSelected(this);
        }
    }

public slots:
    void setSelected(bool selected) {
        isSelected = selected;
        updateStyle(); // Update style when selected/unselected
    }

signals:
    void pieceSelected(ChessPiece* selectedPiece);

private:
    bool isWhite;
    bool isSelected;

    void updateStyle() {
        if (isSelected) {
            setStyleSheet("QLabel { color: white; background-color: yellow; font-weight: bold; border: 1px solid black; }");
        } else {
            if (isWhite) {
                setStyleSheet("QLabel { color: white; background-color: transparent; font-weight: bold; border: 1px solid black; }");
            } else {
                setStyleSheet("QLabel { color: black; background-color: transparent; font-weight: bold; border: 1px solid white; }");
            }
        }
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;

    QGridLayout *chessboardLayout = new QGridLayout;

    // Create ChessSquare and ChessPiece objects
    ChessSquare* squares[8][8];
    ChessPiece* pieces[8][8];
    ChessPiece* selectedBlackPiece = nullptr; // Store the currently selected black piece
    ChessPiece* selectedWhitePiece = nullptr; // Store the currently selected white piece

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            bool isBrownSquare = (row + col) % 2 == 0;
            squares[row][col] = new ChessSquare(isBrownSquare);
            chessboardLayout->addWidget(squares[row][col], row, col);
        }
    }

    QString whitePieces[8] = {"R", "N", "B", "Q", "K", "B", "N", "R"};
    QString blackPieces[8] = {"r", "n", "b", "q", "k", "b", "n", "r"};
    QString whitePawns[8] = {"P", "P", "P", "P", "P", "P", "P", "P"};
    QString blackPawns[8] = {"p", "p", "p", "p", "p", "p", "p", "p"};

    for (int i = 0; i < 8; ++i) {
        pieces[0][i] = new ChessPiece(blackPieces[i], false);
        pieces[1][i] = new ChessPiece(blackPawns[i], false);
        pieces[6][i] = new ChessPiece(whitePawns[i], true);
        pieces[7][i] = new ChessPiece(whitePieces[i], true);

        // Connect the pieceSelected signal to select/deselect pieces for black and white
        QObject::connect(pieces[0][i], &ChessPiece::pieceSelected, [&](ChessPiece* selected) {
            if (selectedBlackPiece) {
                selectedBlackPiece->setSelected(false);
            }
            selectedBlackPiece = selected;
        });

        QObject::connect(pieces[7][i], &ChessPiece::pieceSelected, [&](ChessPiece* selected) {
            if (selectedWhitePiece) {
                selectedWhitePiece->setSelected(false);
            }
            selectedWhitePiece = selected;
        });

        chessboardLayout->addWidget(pieces[0][i], 0, i); // Black pieces on the top
        chessboardLayout->addWidget(pieces[1][i], 1, i); // Black pawns on the second row from the top
        chessboardLayout->addWidget(pieces[6][i], 6, i); // White pawns on the second row from the bottom
        chessboardLayout->addWidget(pieces[7][i], 7, i); // White pieces on the bottom
    }

    window.setLayout(chessboardLayout);
    window.setWindowTitle("Chessboard with Pieces");
    window.show();

    return app.exec();
}

#include "test_main.moc" // Add this line
