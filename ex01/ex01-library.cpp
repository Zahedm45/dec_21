#include <iostream>
#include "ex01-library.h"

using namespace std;

bool is_move_possible(Square source_sq, Square dest_sq, int r1, int c1, int r2, int c2);
// Task 1(a).  Implement this function
Square **createChessboard(unsigned int n) {

    Square **squares = new Square*[n];
    for (unsigned int i = 0; i < n; ++i) {
        squares[i] = new Square[n];
    }

    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            squares[i][j].piece = none;
            squares[i][j].team = nobody;
        }
    }


    return squares;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c, unsigned int n) {


    for (unsigned int i = 0; i < n; ++i) {

        for (unsigned int j = 0; j < n; ++j) {

            Square curr = c[i][j];

            if (curr.piece == none) {
                cout << "_" ;
            } else{

                if (curr.piece == rook && curr.team == black) {
                    cout << "R" ;
                } else if (curr.piece == rook && curr.team == white) {
                    cout << "r" ;

                } else if (curr.piece == bishop && curr.team == black) {
                    cout << "B" ;

                } else if (curr.piece == bishop && curr.team == white) {
                    cout << "b" ;
                }
            }

            cout << " ";
        }

        cout << endl;

    }
}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int n, int r1, int c1, int r2, int c2) {

    int n2 = (int) n;
    if (r1 == r2 && c1 == c2) return false;
    if (r1 >= n2 || c1 >= n2 || r2 >= n2 || c2 >= n2) return false;

    Square source_sq = c[r1][c1];
    Square dest_sq = c[r2][c2];

    bool success = is_move_possible(source_sq, dest_sq, r1, c1, r2, c2);

    if (success) {
        c[r2][c2].piece = source_sq.piece;
        c[r2][c2].team = source_sq.team;

        c[r1][c1].piece = none;
        c[r1][c1].team = nobody;
        return true;
    }


    return false;
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int n, int row, int col) {
    Square target_sq = c[row][col];

    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            Square source_sq = c[i][j];
            if (is_move_possible(source_sq, target_sq, (int)i, (int)j, row, col)) {
                return true;
            }

        }
    }


    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        delete[] c[i];
    }
    delete[] c;
}


bool is_move_possible(Square source_sq, Square dest_sq, int r1, int c1, int r2, int c2) {
    int delta_y = abs(r1 - r2);
    int delta_x = abs(c1 - c2);
    if (delta_x == 0 || delta_y == 0) {
        if (source_sq.piece == rook && (dest_sq.piece == none || dest_sq.team != source_sq.team)) {
            return true;
        }

    } else if (delta_y % delta_x == 0) {
        if (delta_y / delta_x == 1) {
            if (source_sq.piece == bishop && (dest_sq.piece == none || dest_sq.team != source_sq.team)) {
                 return true;
            }
        }
    }

    return false;
}