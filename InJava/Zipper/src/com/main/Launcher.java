/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main;

import java.io.IOException;

/**
 *
 * @author 14309_000
 */
public class Launcher {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        ZipCompresser comp = new ZipCompresser();
        ZipDecompresser deComp = new ZipDecompresser();
        if(args.length > 0 && args[0].equals("compress")) {
            String[] myArray = comp.getRestArgs(args);
            System.out.println("\nCompressing...");
            comp.compress(args[1], myArray);
            System.out.println("Compressing done.");
        } else if(args.length > 0 && args[0].equals("decompress")) {
            System.out.println("\nUncompressing...");
            deComp.deCompress(args[1]);
            System.out.println("Uncompressing done.");
        } else if(args.length == 0 || args[0].equals("help")) {
            System.out.println("\nUsage: zipper [OPTION] [FILE]...\nCompress or uncompress FILEs.\n\nOption can be:\n\n"
                    + "\tcompress [ARCHIVE_NAME] \tCompress one or several files\n\t\t\t\t\tinside a new archive.\n"
                    + "\tdecompress\t\t\tDecompress files inside a archive.\n\n");
        } else {
            System.out.println("\nNothing will be done, wrong command.\n");
        }
    }
}
