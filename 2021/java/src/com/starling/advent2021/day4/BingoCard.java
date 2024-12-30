package com.starling.advent2021.day4;

import java.lang.Integer;

public class BingoCard {
    private static final int BOARD_SIZE = 5;

    private static final int MARK_NUMBER = -1; // number to put if a tile should be marked

    private int[][] boardNums = new int[BOARD_SIZE][BOARD_SIZE];

    public BingoCard(String[] stringIn) {
        for(int i = 0; i < BOARD_SIZE; i++) {
            // split by any number of spaces
            String[] line = stringIn[i].split("\\s+");
            for(int j = 0; j < BOARD_SIZE; j++) {
                //parse strings to ints
                this.boardNums[i][j] = Integer.parseInt(line[j]);
            }
        }
    }

    public BingoCard(int[][] board) {
        this.boardNums = board;
    }

    /**
     * Function: getScore
     * Purpose: Calculates the specified BingoCard's score
     * @param lastCall - the last value called
     * @return  an int corresponding to the BingoCard's score
     */
    public int getScore(int lastCall) {
        int score = 0;
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                //only count if not marked
                if(this.boardNums[i][j] != MARK_NUMBER) {
                    score += this.boardNums[i][j];
                }
            }
        }

        score *= lastCall;

        return score;
    }

    /**
     * Function: printBoard
     * Purpose: Prints the board state
     */
    public void printBoard() {
        for(int i = 0; i < boardNums.length; i++) {
            for(int j = 0; j < boardNums[i].length; j++) {
                System.out.printf("%2d ", boardNums[i][j]);
            }
            System.out.println();
        }
    }

    /**
     * Function: markCard
     * Purpose: Marks all spaces on a card matching the specified bingo call, then checks if the bingo card has just won
     * @param bingoCall - the called bingo value
     * @return a boolean that is true if the card wins after this call, false if not
     */
    public boolean markCard(int bingoCall) {
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                //sets matching values to be marked
                if(this.boardNums[i][j] == bingoCall) {
                    this.boardNums[i][j] = MARK_NUMBER;
                }
            }
        }

        return this.hasWon();
    }

    /**
     * Function: hasWon
     * Purpose: Checks if the specified Bingo Card has just won
     * @return  a boolean stating if the Bingo Card has just won
     */
    public boolean hasWon() {
        //return if either is true
        return checkHorizVert() /*|| checkDiags()*/;
    }

//    /**
//     * Function: checkDiags
//     * Purpose: Checks if either of the specified Bingo Card's diagonals have won
//     * @return  a boolean stating if either of the Bingo Card's diagonals have won
//     */
//    public boolean checkDiags() {
//        boolean diagFlag1 = true;
//        boolean diagFlag2 = true;
//
//        for(int i = 0; i < BOARD_SIZE; i++) {
//            if(this.boardNums[i][i] != MARK_NUMBER) {
//                diagFlag1 = false;
//            }
//
//            if(this.boardNums[BOARD_SIZE - i - 1][BOARD_SIZE - i - 1] != MARK_NUMBER) {
//                diagFlag2 = false;
//            }
//        }
//
//        return diagFlag1 || diagFlag2;
//    }

    /**
     * Function: checkHorizVert
     * Purpose: Checks if the specified Bingo Card's horizontals or verticals have won
     * @return  a boolean stating if the Bingo Card's horizontals or verticals have won
     */
    public boolean checkHorizVert() {
        for(int i = 0; i < BOARD_SIZE; i++) {
            //set flags to true
            boolean horizFlag = true;
            boolean vertiFlag = true;
            for(int j = 0; j < BOARD_SIZE && (horizFlag || vertiFlag); j++) {
                // check horizontals
                if(boardNums[i][j] != MARK_NUMBER) {
                    horizFlag = false;
                }

                if(boardNums[j][i] != MARK_NUMBER) {
                    vertiFlag = false;
                }
            }

            //if either is true, return true
            if(horizFlag || vertiFlag) {
                return true;
            }
        }

        return false;
    }
}
