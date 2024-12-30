package com.starling.advent2021.day6;

import java.lang.Integer;

public class LanternfishSchool {
    private final int MAX_DAYS;
    private static final int DAYS_PER_FISH = 7;
    private static final int INITIAL_DELAY = 2;

    private int days = 0;

    private long[] fishCount = new long[DAYS_PER_FISH + INITIAL_DELAY];

    public LanternfishSchool(String input, int maxDays) {
        String[] inLines = input.split(",");

        for(String line : inLines) {
            // increment counting categories
            fishCount[Integer.parseInt(line)]++;
        }

        this.MAX_DAYS = maxDays;
    }

    public void iterateAll() {
        while(this.days < MAX_DAYS) {
            this.iterateSchool();
        }
    }

    public void iterateSchool() {
        long fishTemp = fishCount[0];
        // shift array down by one
        System.arraycopy(fishCount, 1, fishCount, 0, fishCount.length - 1);

        fishCount[DAYS_PER_FISH - 1] += fishTemp;
        fishCount[fishCount.length - 1] = fishTemp;

        this.days++;
    }

    public long getNumFish() {
        long sum = 0;

        for(long fish : fishCount) {
            sum += fish;
        }

        return sum;
    }
}
