package com.starling.advent2021.day1;

import com.starling.advent2021.tools.IOTools;
import java.lang.Integer;

public class D1P1 {
    public static void main(String[] args) {
        String input = IOTools.readFileAsString("src/com/starling/advent2021/day1/input.txt");

        // split by line
        String[] inputLines = input.split("\r\n");

        int count = 0;

        int lastVal;
        int thisVal = Integer.parseInt(inputLines[0]);
        for(int i = 1; i < inputLines.length; i++) {
            lastVal = thisVal;
            thisVal = Integer.parseInt(inputLines[i]);

            if(thisVal > lastVal) {
                count++;
            }
        }

        System.out.println(count);
    }
}
