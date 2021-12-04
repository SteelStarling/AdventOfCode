package com.starling.advent2021.day3;

import com.starling.advent2021.tools.IOTools;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

public class D3P2 {

    public static void main(String[] args) {
        String input = IOTools.readFileAsString("src/com/starling/advent2021/day3/input.txt");

        // split by line
        String[] inputLines = input.split("\r\n");

        List<String> o2Lines = new ArrayList<String>(inputLines.length);
        List<String> co2Lines = new ArrayList<String>(inputLines.length);

        for(int i = 0; i < inputLines.length; i++) {
            o2Lines.add(inputLines[i]);
            co2Lines.add(inputLines[i]);
        }

        int o2Rate = 0;
        int co2Rate = 0;

        // loop through each character
        for(int i = 0; i < inputLines[0].length(); i++) {
            int o2Ones = 0;
            int o2Zeros = 0;

            int co2Ones = 0;
            int co2Zeros = 0;

            // loop through each line (O2)
            for(int j = 0; j < o2Lines.size(); j++) {
                // increment each value
                if (o2Lines.get(j).charAt(i) == '1') {
                    o2Ones++;
                } else {
                    o2Zeros++;
                }
            }

            // loop through each line (CO2)
            for(int j = 0; j < co2Lines.size(); j++) {
                // increment each value
                if (co2Lines.get(j).charAt(i) == '1') {
                    co2Ones++;
                } else {
                    co2Zeros++;
                }
            }

            char o2Common = '1';
            if(o2Ones > o2Zeros) {
                o2Common = '0';
            }

            char co2Common = '1'
            if(co2Ones > co2Zeros) {
                co2Common = '0';
            }

            for(String s : o2Lines) {
                s.charAt(j);
            }
        }

        //calculate ratings
        o2Rate = Integer.parseInt(o2Lines.get(0));
        co2Rate = Integer.parseInt(co2Lines.get(0));

        //calculate life support rating
        int lifeSupportRating = o2Rate * co2Rate;

        System.out.println("Life Support Rating: " + lifeSupportRating);
    }
}
