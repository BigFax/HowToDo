/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main.javaparadise.dao;

import com.main.javaparadise.beans.Place;
import java.util.List;

/**
 *
 * @author 14309_000
 */
public interface PlaceDao {
    abstract Long createPlace(Place p);
    abstract Place findPlaceById(Long id);
    abstract boolean updatePlace(Place p);
    abstract boolean removePlace(Place p);
    abstract List<Place> findAllPlaces();
}
