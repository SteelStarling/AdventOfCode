package com.starling.advent2021.day1;

import com.starling.advent2021.tools.IOTools;
import java.lang.Integer;

public class D1P2 {

    private static final int AVG_SIZE = 3;

    public static void main(String[] args) {
        String input = IOTools.readFileAsString("src/com/starling/advent2021/day1/input.txt");

        // split by line
        String[] inputLines = input.split("\r\n");

        int count = 0;
        int[] vals = new int[inputLines.length];
        int lastVal;
        int thisVal = 0;
        for(int i = 0; i < inputLines.length; i++) {
            vals[i] = Integer.parseInt(inputLines[i]);

            // only check averages when there are enough to actually check
            if(i >= AVG_SIZE) {
                // update values
                lastVal = thisVal;

                //reset counter to 0
                thisVal = 0;

                //count
                for(int j = 0; j < AVG_SIZE; j++) {
                    thisVal += vals[i-j];
                }

                //increment if greater and last exists
                if((i > AVG_SIZE) && (thisVal > lastVal)) {
                    count++;
                }
            }
        }

        System.out.println(count);
    }
}
