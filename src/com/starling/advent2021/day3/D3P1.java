package com.starling.advent2021.day3;

import com.starling.advent2021.tools.IOTools;

public class D3P1 {
    public static void main(String[] args) {
        String input = IOTools.readFileAsString("src/com/starling/advent2021/day3/input.txt");

        // split by line
        String[] inputLines = input.split("\r\n");

        int gammaRate = 0;
        int epsilonRate = 0;

        // loop through each character
        for(int i = 0; i < inputLines[0].length(); i++) {
            int numOnes = 0;
            int numZeros = 0;

            // loop through each line
            for(int j = 0; j < inputLines.length; j++) {
                // increment each value
                if (inputLines[j].charAt(i) == '1') {
                    numOnes++;
                } else {
                    numZeros++;
                }
            }

            // calculate corresponding binary value
            int binaryVal = 1 << (inputLines[0].length() - 1 - i);

            if(numOnes > numZeros) {
                gammaRate += binaryVal;
            } else {
                epsilonRate += binaryVal;
            }
        }

        int consumption = gammaRate * epsilonRate;

        System.out.println("Consumption: " + consumption);
    }
}
