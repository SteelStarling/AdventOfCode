package com.starling.advent2021.day8;

import com.starling.advent2021.tools.IOTools;

public class D8P1 {
    public static void main(String[] args) {
        String input = IOTools.readFileAsString("src/com/starling/advent2021/day8/input.txt");

        String[] inputLines = input.split("\\r\\n");

        int sum = 0;
        for(String line : inputLines) {
            String[] splitLine = line.split("( \\| )"); // split by break
            String[] chars = splitLine[1].split(" "); // split by space
            for(String str : chars) {
                int len = str.length();
                if(len == 2 || len == 4 || len == 3 || len == 7) { //if 1, 4, 7, or 8
                    sum++;
                }
            }
        }

        System.out.println(sum);
    }
}
