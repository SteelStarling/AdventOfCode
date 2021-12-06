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

        List<String> o2Lines = new ArrayList<>(inputLines.length);
        List<String> co2Lines = new ArrayList<>(inputLines.length);

        for(int i = 0; i < inputLines.length; i++) {
            o2Lines.add(inputLines[i]);
            co2Lines.add(inputLines[i]);
        }

        int o2Rate;
        int co2Rate;

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
            if(o2Ones >= o2Zeros) {
                o2Common = '0';
            }

            char co2Common = '0';
            if(co2Ones >= co2Zeros) {
                co2Common = '1';
            }

            List<String> o2Removes = new ArrayList<>(o2Lines.size());
            List<String> co2Removes = new ArrayList<>(co2Lines.size());

            //add bad items in list to remove list
            for(String s : o2Lines) {
                if(s.charAt(i) == o2Common) {
                    o2Removes.add(s);
                }
            }

            if(co2Lines.size() != 1) {
                for(String s : co2Lines) {
                    if(s.charAt(i) == co2Common) {
                        co2Removes.add(s);
                    }
                }
            }

            //remove items in remove list from list
            for(String s : o2Removes) {
                o2Lines.remove(s);
            }

            if(co2Lines.size() != 1) {
                for(String s : co2Removes) {
                    if(co2Lines.size() != 1) {
                        co2Lines.remove(s);
                    }
                }
            }
        }

        //calculate ratings
        o2Rate = Integer.parseInt(o2Lines.get(0), 2);
        co2Rate = Integer.parseInt(co2Lines.get(0), 2);

        System.out.println("o2Rate: " + o2Rate + "   co2Rate: " + co2Rate);

        //calculate life support rating
        int lifeSupportRating = o2Rate * co2Rate;

        System.out.println("Life Support Rating: " + lifeSupportRating);
    }
}
