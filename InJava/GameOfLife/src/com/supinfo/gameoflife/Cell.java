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
interface Cell {
    Cell newGeneration(int nbNeighbours);
    String getAsString();
    boolean isAlive();
}
