package com.starling.advent2021.day8;

public class SevenSegmentDisplay {

    private static final String zero  = "abcefg";
    private static final String one   = "cf";
    private static final String two   = "acdeg";
    private static final String three = "acdfg";
    private static final String four  = "bcdf";
    private static final String five  = "abdfg";
    private static final String six   = "abdefg";
    private static final String seven = "acf";
    private static final String eight = "abcdefg";
    private static final String nine  = "abcdfg";

    private String[] uniques = new String[10];
    private String[] outputs = new String[4];
    private int output;

    public SevenSegmentDisplay() {

    }
}
