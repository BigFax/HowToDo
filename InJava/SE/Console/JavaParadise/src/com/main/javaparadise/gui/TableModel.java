/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main.javaparadise.gui;

import com.main.javaparadise.beans.Trip;
import java.util.List;
import javax.swing.table.AbstractTableModel;

/**
 *
 * @author 14309_000
 */
public class TableModel extends AbstractTableModel {
    private List<Trip> trips;
    private String headers[] = {"ID", "Departure", "Destination", "Price"};
    
    public TableModel(List<Trip> trips) {
        this.trips = trips;
    }
    
    @Override
    public int getRowCount() {
        return trips.size();
    }

    @Override
    public int getColumnCount() {
        return 4;
    }
    
    @Override
    public String getColumnName(int columnIndex) {
        return headers[columnIndex];
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        Object result = null;
        Trip trip = trips.get(rowIndex);
        
        switch(columnIndex) {
            case 0:
                result = trip.getId();
                break;
            case 1:
                result = trip.getDeparture();
                break;
            case 2:
                result = trip.getDestination();
                break;
            case 3:
                result = trip.getPrice();
                break;
        }
        
        return result;
    }

    /**
     * @return the trips
     */
    public List<Trip> getTrips() {
        return trips;
    }

    /**
     * @param trips the trips to set
     */
    public void setTrips(List<Trip> trips) {
        this.trips = trips;
    }
    
}
