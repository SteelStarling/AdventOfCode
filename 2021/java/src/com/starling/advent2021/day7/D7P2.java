package com.starling.advent2021.day7;

import com.starling.advent2021.tools.IOTools;

import java.util.Arrays;

public class D7P2 {
    // As shown by r/adventofcode user u/CrumblingAway, the most efficent position can be found from this equation:
    //      https://imgur.com/FRSYtZW

    public static void main(String[] args) {
        String input = IOTools.readFileAsString("src/com/starling/advent2021/day7/input.txt");

        String[] inputLines = input.split(",");

        int[] vals = new int[inputLines.length];

        int sum = 0;
        for(int i = 0; i < inputLines.length; i++) {
            vals[i] = Integer.parseInt(inputLines[i]);
            sum += vals[i]; // add to sum each pass
        }

        int position = sum / vals.length;

        // calculate fuel
        int fuel = 0;
        for(int val : vals) {
            // use gauss to find sums (a_1 is always 1, and n and a_n are the same)
            int diff = Math.abs(position - val);
            fuel += (diff * (1 + diff)) / 2;
        }

        System.out.println(fuel);
    }
}
