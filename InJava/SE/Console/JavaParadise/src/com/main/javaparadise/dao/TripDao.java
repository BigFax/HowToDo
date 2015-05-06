/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main.javaparadise.dao;

import com.main.javaparadise.beans.Trip;
import java.util.List;

/**
 *
 * @author 14309_000
 */
public interface TripDao {
    abstract Long createTrip(Trip t);
    abstract Trip findTripById(Long id);
    abstract boolean removeTrip(Trip t);
    abstract List<Trip> findAllTrips();
}
