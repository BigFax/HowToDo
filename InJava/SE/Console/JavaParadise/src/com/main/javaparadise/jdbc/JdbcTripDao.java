/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main.javaparadise.jdbc;

import com.main.javaparadise.beans.Place;
import com.main.javaparadise.beans.Trip;
import com.main.javaparadise.dao.TripDao;
import com.main.javaparadise.launcher.GuiLauncher;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author 14309_000
 */
public class JdbcTripDao implements TripDao {
    @Override
    public Long createTrip(Trip t) {
        try {
            String insert = "INSERT INTO trip (id_departure, id_destination, price) VALUES (?, ?, ?)";
            PreparedStatement req = GuiLauncher.connection.prepareStatement(insert);
            req.setInt(1, Integer.valueOf(t.getDeparture().getId().toString()));
            req.setInt(2, Integer.valueOf(t.getDestination().getId().toString()));
            req.setInt(3, Integer.valueOf(t.getPrice().toString()));
            req.executeUpdate();
            GuiLauncher.connection.commit();
        } catch (SQLException e) {
            try {
                System.out.println("Error " + e);
                GuiLauncher.connection.rollback();
            } catch (SQLException e1) {
                System.out.println(e1);
            }
        }

        return t.getId();
    }

    @Override
    public Trip findTripById(Long id) {
        return null;
    }

    @Override
    public boolean removeTrip(Trip t) {
        try {
            String delete = "DELETE FROM trip WHERE id = ?";
            PreparedStatement req = GuiLauncher.connection.prepareStatement(delete);
            req.setInt(1, Integer.decode(t.getId().toString()));
            req.executeUpdate();
            GuiLauncher.connection.commit();
        } catch (SQLException e) {
            try {
                System.out.println("Error " + e);
                GuiLauncher.connection.rollback();
            } catch (SQLException e1) {
                System.out.println(e1);
            }
        }

        return false;
    }
    
    @Override
    public List<Trip> findAllTrips() {
        List<Trip> trips = new ArrayList<>();
        try {
            PreparedStatement req = GuiLauncher.connection.prepareStatement("SELECT * FROM trip");
            ResultSet result = req.executeQuery();
            while (result.next()) {
                Place departure = GuiLauncher.jdbcPlace.findPlaceById(result.getLong(2));
                Place destination = GuiLauncher.jdbcPlace.findPlaceById(result.getLong(3));
                Trip trip = new Trip(departure, destination, result.getBigDecimal(4));
                trip.setId(result.getLong(1));
                trips.add(trip);
            }
            
        } catch (SQLException e) {
            try {
                System.out.println("Error findAllTrips " + e);
                GuiLauncher.connection.rollback();
            } catch (SQLException e1) {
                System.out.println(e1);
            }
        }
        return trips;
    }
}
