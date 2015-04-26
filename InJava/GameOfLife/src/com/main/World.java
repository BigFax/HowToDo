/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main;

/**
 *
 * @author 14309_000
 */
public class World {
    private Cell array[][];
    
    public World(int nbColumns, int nbRows) {
        this.array = new Cell[nbColumns][nbRows]; 
        this.initializeWorld();
    }
    
    public World(Cell[][] world) {
        this.array = world;
        int nbColumns = world.length, nbRows = world[0].length;
        this.array = new Cell[nbColumns][nbRows];
        
        this.initializeWorld();
    }
    
    public void newGeneration() {
        int nbNeighbours = 0;
        for (int y = 0; y < this.array[0].length; y++) {
            for (int x = 0; x < this.array.length; x++) {
                for (int j = y - 1; j <= y + 1; j++) {
                    for (int i = x - 1; i <= x + 1; i++) {
                        if (i >= 0 && i < this.array.length - 1 && j >= 0 && j < this.array[0].length - 1) {
                            if (this.array[i][j].isAlive())
                                nbNeighbours++;
                        }
                    }
                }
                this.array[x][y] = this.array[x][y].newGeneration(nbNeighbours);
                nbNeighbours = 0;
            }
        }
    }
    
    @Override
    public String toString() {
        String display = "";
        for(int y = 0; y < this.array[0].length; y++) {
            for(int x = 0; x < this.array.length; x++) {
                display += this.array[x][y].getAsString();
                display += " ";
            }
            display += "\n";
        }
        return display;
    }
    
    private void initializeWorld() {
        int random, lower = 0, higher = 100;
        boolean newCell;
        
        for (int y = 0; y < this.array[0].length; y++) {
            for (int x = 0; x < this.array.length; x++) {
                random = (int) (Math.random() * (higher - lower)) + lower;
                
                // If the random is even, else if odd.
                if (random % 2 == 0) {
                    // Put 20% or the Cell as new for more random.
                    random = (int) (Math.random() * (higher - lower)) + lower;
                    newCell = (random <= 20);
                    this.array[x][y] = new AliveCell(newCell);
                } else if (random % 2 != 0) {
                    this.array[x][y] = new DeadCell();
                }
            }
        }
    }
}
