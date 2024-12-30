package com.starling.advent2021.day7;

import com.starling.advent2021.tools.IOTools;

import java.util.Arrays;

public class D7P1 {
    // median is the minimum, due to math reasons that shall not be questioned henceforth,
    // as mentioned by r/adventofcode user u/CrumblingAway referencing:
    //      https://en.wikipedia.org/wiki/Geometric_median#Properties

    public static void main(String[] args) {
        String input = IOTools.readFileAsString("src/com/starling/advent2021/day7/input.txt");

        String[] inputLines = input.split(",");

        int[] vals = new int[inputLines.length];

        for(int i = 0; i < inputLines.length; i++) {
            vals[i] = Integer.parseInt(inputLines[i]);
        }

        // sort array (I could do this myself, but why bother when Java will do it for me)
        Arrays.sort(vals);

        int medPos = (vals.length + 1) / 2; // get median position
        int median = vals[medPos]; // calculate median

        if(vals.length % 2 == 0) { // if even number, get average of two midpoints
            median = (vals[medPos - 1] + median) / 2;
        }

        // add differentials together
        int sum = 0;
        for(int i : vals) {
            sum += Math.abs(median - i);
        }

        System.out.println(sum);
    }
}
