package com.starling.advent2021.tools;

import java.nio.file.*;

public class IOTools {
    /* Blantantly borrowed from Geeks for Geeks' handling here https://www.geeksforgeeks.org/different-ways-reading-text-file-java/ */
    public static String throwableReadFileAsString(String fileName) throws Exception {
        String data;
        data = new String(Files.readAllBytes(Paths.get(fileName)));
        return data;
    }

    /* handle exception? */
    public static String readFileAsString(String fileName) {
        String s = null;
        try {
            s = throwableReadFileAsString(fileName);
        } catch(Exception e) {
            System.out.println("Error: File Not Found!");
            e.printStackTrace();
        }

        return s;
    }
}
