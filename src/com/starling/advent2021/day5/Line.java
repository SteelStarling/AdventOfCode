package com.starling.advent2021.day5;

public class Line {

    private Point p1;
    private Point p2;
    private boolean isVert;
    private boolean isHori;
    private boolean isDiagD;
    private boolean isDiagU;

    public Line(String input) {
        // calculate points
        String[] inputLines = input.split(" -> ");
        this.p1 = new Point(inputLines[0]);
        this.p2 = new Point(inputLines[1]);

        // calculate if straight line
        this.isVert = this.calcVert();
        this.isHori = this.calcHori();

        // calculate if exactly diagonal
        this.isDiagD = this.calcDiagD();
        this.isDiagU = this.calcDiagU();
    }

    public Line(int x1, int y1, int x2, int y2) {
        this(new Point(x1, y1), new Point(x2, y2));
    }

    public Line(Point p1, Point p2) {
        // calculate points
        this.p1 = p1;
        this.p2 = p2;

        // calculate if straight line
        this.isVert = this.calcVert();
        this.isHori = this.calcHori();

        // calculate if exactly diagonal
        this.isDiagD = this.calcDiagD();
        this.isDiagU = this.calcDiagU();
    }

    public Point getP1() {
        return p1;
    }

    public Point getP2() {
        return p2;
    }

    public boolean isHori() {
        return isHori;
    }

    public boolean isVert() {
        return isVert;
    }

    public boolean isStraight() {
        return this.isVert || this.isHori;
    }

    public boolean isDiagD() {
        return isDiagD;
    }

    public boolean isDiagU() {
        return isDiagU;
    }

    public boolean isDiag() {
        return this.isDiagU || this.isDiagD;
    }

    public boolean isUsable() {
        return this.isStraight() || this.isDiag();
    }

    public boolean calcVert() {
        return p1.getX() == p2.getX();
    }

    public boolean calcHori() {
        return p1.getY() == p2.getY();
    }

    public boolean calcDiagU() {
        return (p1.getX() - p2.getX()) == (p1.getY() - p2.getY());
    }

    public boolean calcDiagD() {
        return -(p1.getX() - p2.getX()) == (p1.getY() - p2.getY());
    }

    public String toString() {
        return p1.toString() + " -> " + p2.toString();
    }
}
