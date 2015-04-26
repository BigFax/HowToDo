/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.gameoflife;

/**
 *
 * @author 14309_000
 */
public class DeadCell implements Cell {
    @Override
    public Cell newGeneration(int nbNeighbours) {
        if(nbNeighbours == 3) {
            return new AliveCell(true);				
        } else {
            return new DeadCell();
        }
    }
    
    @Override
    public String getAsString() {
        return "-";
    }

    @Override
    public boolean isAlive() {		
        return false;
    }
}
