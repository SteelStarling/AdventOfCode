package com.starling.advent2021.day6;

import java.lang.Integer;

public class LanternfishSchool {
    private static final int MAX_DAYS = 80;
    private static final int DAYS_PER_FISH = 7;
    private static final int INITIAL_DELAY = 2;

    private int days = 0;

    private int[] fishCount = new int[DAYS_PER_FISH + INITIAL_DELAY];

    public LanternfishSchool(String input) {
        String[] inLines = input.split(",");

        for(String line : inLines) {
            // increment counting categories
            fishCount[Integer.parseInt(line)]++;
        }
    }

    public void iterateAll() {
        while(this.days < 80) {
            this.iterateSchool();
        }
    }

    public void iterateSchool() {
        int fishTemp = fishCount[0];
        for(int i = 1; i < fishCount.length; i++) {
            fishCount[i - 1] = fishCount[i];
        }

        fishCount[DAYS_PER_FISH - 1] += fishTemp;
        fishCount[fishCount.length - 1] = fishTemp;

        this.days++;
    }

    public long getNumFish() {
        long sum = 0;

        for(int fish : fishCount) {
            sum += fish;
        }

        return sum;
    }
}
