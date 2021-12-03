package com.starling.advent2021.day2;

import com.starling.advent2021.tools.IOTools;

public class D2P2 {
    public static void main(String[] args) {
        String input = IOTools.readFileAsString("src/com/starling/advent2021/day2/input.txt");

        // split by line
        String[] inputLines = input.split("\r\n");

        int x = 0;
        int y = 0;
        int aim = 0;

        //get input line
        for (String str : inputLines) {
            int val = Integer.parseInt(str.substring(str.indexOf(" ") + 1)); //parse into integer

            switch (str.charAt(0)) {
                case 'f': //forward case
                    x += val;
                    y += aim * val;
                    break;
                case 'd': //down case
                    aim += val;
                    break;
                case 'u': //up case
                    aim -= val;
                    break;
                default:
                    System.out.println("Default case triggered, something weird happened.");
            }
        }

        System.out.println("x * y is: " + (x * y));
    }
}
