package com.starling.advent2021.day4;

import com.starling.advent2021.tools.IOTools;

public class D4P1 {
    public static void main(String[] args) {
        String input = IOTools.readFileAsString("src/com/starling/advent2021/day4/input.txt");

        BingoGame bingo = new BingoGame(input);

        // print score
        System.out.println(bingo.makeMoves());
    }
}
