package com.starling.advent2021.day4;

import java.lang.Integer;

public class BingoGame {
    private int[] callList; //stores bingo calls

    private BingoCard[] cardList; //stores bingo cards

    public BingoGame(String callString, String[] cardStrings) {
        String[] callStrings = callString.split(","); //split by commas

        //setup callList
        this.callList = new int[callStrings.length];
        for(int i = 0; i < callStrings.length; i++) {
            this.callList[i] = Integer.parseInt(callStrings[i]);
        }

        //setup cardList
        cardList = new BingoCard[cardStrings.length];
        for(int i = 0; i < cardStrings.length; i++) {
            String[] bingoIn = cardStrings[i].split("\n");
            cardList[i] = new BingoCard(bingoIn);
        }
    }

    public BingoGame(String stringInput) {
        int callCardDiv = stringInput.indexOf("\r\n"); //find first newline
        String callString = stringInput.substring(0, callCardDiv);
        String cardString = stringInput.substring(callCardDiv + 3); //skip to after newlines

        //split by double newlines to split cards
        String[] cardStrings = cardString.split("\\n\\r");

        //copy from previous BingoGame constructor
        String[] callStrings = callString.split(","); //split by commas

        //setup callList
        this.callList = new int[callStrings.length];
        for(int i = 0; i < callStrings.length; i++) {
            this.callList[i] = Integer.parseInt(callStrings[i]);
        }

        //setup cardList
        cardList = new BingoCard[cardStrings.length];
        for(int i = 0; i < cardStrings.length; i++) {
            cardStrings[i] = cardStrings[i].trim();
            String[] bingoIn = cardStrings[i].split("\\n\\s?");
            cardList[i] = new BingoCard(bingoIn);
        }
    }

    /**
     * Function: makeMoves
     * Purpose:  Makes all moves until a winning card is found, then returns its score
     * @return  an int with the score of the winning card, or -1 if no card won
     */
    public int makeMoves() {
        for(int i = 0; i < callList.length; i++) {
            int call = callList[i];
            for(BingoCard card : cardList) {
                //mark card and return if won
                if(card.markCard(call)) {
                    return card.getScore(call);
                }
            }
        }

        return -1;
    }
}
