/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main.javaparadise.gui;

import com.main.javaparadise.beans.Place;
import java.util.List;
import javax.swing.ComboBoxModel;
import javax.swing.event.ListDataListener;

/**
 *
 * @author 14309_000
 */
public class PlaceComboBoxModel implements ComboBoxModel<Place> {
    private List<Place> places;
    private Place selectedPlace;

    public PlaceComboBoxModel(List<Place> places) {
        this.places = places;
    }

    @Override
    public void setSelectedItem(Object anItem) {
        selectedPlace = (Place) anItem;
    }

    @Override
    public Place getSelectedItem() {
        return selectedPlace;
    }

    @Override
    public int getSize() {
        return places.size();
    }

    @Override
    public Place getElementAt(int index) {
        return places.get(index);
    }

    @Override
    public void addListDataListener(ListDataListener listeners) {

    }

    @Override
    public void removeListDataListener(ListDataListener listeners) {

    }
}
