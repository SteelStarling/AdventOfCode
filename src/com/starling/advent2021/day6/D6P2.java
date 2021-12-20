package com.starling.advent2021.day6;

import com.starling.advent2021.tools.IOTools;

public class D6P2 {
    public static void main(String[] args) {
        String input = IOTools.readFileAsString("src/com/starling/advent2021/day6/input.txt");

        LanternfishSchool fish = new LanternfishSchool(input, 256);

        fish.iterateAll();

        System.out.println(fish.getNumFish());
    }
}
