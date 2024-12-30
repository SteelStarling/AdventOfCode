package com.starling.advent2021.day6;

/**
 * Deprecated class used during testing phase - LanternfishSchool class should take precedence
 */
public class Lanternfish {
    private static final int DAYS_PER_FISH = 7;
    private static final int INITIAL_DELAY = 2;

    private int days;

    public Lanternfish() {
        this.days = DAYS_PER_FISH + INITIAL_DELAY - 1;
    }

    public Lanternfish(int days) {
        this.days = days;
    }

    public boolean increment() {
        // if hits end, reset counter and return true
        if(this.days-- == 0) {
            this.days = DAYS_PER_FISH - 1;
            return true;
        }

        return false;
    }
}
