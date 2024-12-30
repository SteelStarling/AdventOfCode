package com.starling.advent2021.day5;

import com.starling.advent2021.tools.IOTools;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class D5P1 {
    public static void main(String[] args) {
        String input = IOTools.readFileAsString("src/com/starling/advent2021/day5/input.txt");

        String[] inputLines = input.split("\\r\\n");

        List<Line> lines = new ArrayList<>(inputLines.length);
        for(String str : inputLines) {
            // parse line
            Line line = new Line(str);

            // only add straight lines
            if(line.isStraight()) {
                lines.add(line);
            }
        }

        int overlaps = 0;
        HashMap<Point, Integer> map = new HashMap<>();
        for(Line line : lines) {
            Point p1 = line.getP1();
            Point p2 = line.getP2();

            if(line.isHori()) { // if horizontal (check x's)
                // swap if out of order
                if(p1.getX() > p2.getX()) {
                    p1 = p2;
                    p2 = line.getP1();
                }

                for(int x = p1.getX(); x <= p2.getX(); x++) {
                    // increment value
                    Point p = new Point(x, p1.getY());
                    if(map.containsKey(p)) {
                        int val = map.get(p);
                        map.replace(p, ++val);

                        // update overlap counter
                        if (val == 2) {
                            overlaps++;
                        }
                    } else {
                        // start at 1
                        map.put(p, 1);
                    }
                }

            } else if(line.isVert()) { // if vertical (check y's)
                // swap if out of order
                if(p1.getY() > p2.getY()) {
                    p1 = p2;
                    p2 = line.getP1();
                }

                for(int y = p1.getY(); y <= p2.getY(); y++) {
                    // increment value
                    Point p = new Point(p1.getX(), y);
                    if(map.containsKey(p)) {
                        int val = map.get(p);
                        map.replace(p, ++val);

                        // update overlap counter
                        if (val == 2) {
                            overlaps++;
                        }
                    } else {
                        // start at 1
                        map.put(p, 1);
                    }
                }
            }
        }

        System.out.println(overlaps);
    }
}
