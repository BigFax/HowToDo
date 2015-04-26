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
public class AliveCell implements Cell {
    private boolean newBorn = false;
		
    public AliveCell(boolean newBorn) {
        this.newBorn = newBorn;
    }

    @Override
    public Cell newGeneration(int nbNeighbours) {
        if(nbNeighbours < 2 || nbNeighbours > 3)
            return new DeadCell();
        else
            return new AliveCell(false);
    }

    @Override
    public String getAsString() {
        if(this.newBorn)
            return "0";
        else
            return "+";
    }

    @Override
    public boolean isAlive() {
            return true;
    }

    public boolean isNewBorn() {
            return newBorn;
    }
}
