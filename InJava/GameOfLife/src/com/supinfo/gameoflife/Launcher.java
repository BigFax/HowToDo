/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.gameoflife;

import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 14309_000
 */
public class Launcher {
    public static void main(String[] args) {
        int generation = 1, nbColumns = 0, nbRows = 0, temp, lower = 10, higher = 50;
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Give a number of columns (0 for random) : ");
        nbColumns = ((temp = sc.nextInt()) == 0) ? 0 : temp;
        System.out.print("Give a number of rows (0 for random) : ");
        nbRows = ((temp = sc.nextInt()) == 0) ? 0 : temp;
        
        nbColumns = (nbColumns == 0) ? (int) (Math.random() * (higher - lower)) + lower : nbColumns ;
        nbRows = (nbRows == 0) ? (int) (Math.random() * (higher - lower)) + lower : nbRows;
        
        /*
            Then here you have the choice : Give the nbColumns / nbRows or give an array.
        */
        
        // Give the nbColumns / nbRows :
        World world = new World(nbColumns, nbRows);
        
        // Give an array :
        /* Cell array[][] = new Cell[nbColumns][nbRows];
        World world = new World(array); */    
        
        while(true) {
            System.out.print("\n\n");
            System.out.println("Generation number : " + generation);
            
            System.out.print(world.toString());
            world.newGeneration();
            generation++;
            
            
            if(generation > 100)
                break;

            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(Launcher.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
