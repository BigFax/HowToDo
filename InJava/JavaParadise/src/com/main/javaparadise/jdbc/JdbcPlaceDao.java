/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main.javaparadise.jdbc;

import com.main.javaparadise.beans.Place;
import com.main.javaparadise.dao.PlaceDao;
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
public class JdbcPlaceDao implements PlaceDao {
    @Override
    public Long createPlace(Place p) {
        try {
            String insert = "INSERT INTO place (name) VALUES (?)";
            PreparedStatement req = GuiLauncher.connection.prepareStatement(insert);
            req.setString(1, p.getName());
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
        
        return p.getId();
    }
    
    @Override
    public Place findPlaceById(Long id) {
        try {
            String update = "SELECT * FROM place WHERE id = ?";
            PreparedStatement req = GuiLauncher.connection.prepareStatement(update);
            req.setInt(1, id.intValue());
            ResultSet result = req.executeQuery();
            if (result.next()) {
                Place place = new Place(result.getString(2));
                place.setId(result.getLong(1));
                return place;
            }
        } catch (SQLException e) {
            try {
                System.out.println("Error findPlaceById " + e);
                GuiLauncher.connection.rollback();
            } catch (SQLException e1) {
                System.out.println(e1);
            }
        }
        
        return null;
    }

    @Override
    public boolean updatePlace(Place p) {
        try {
            String update = "UPDATE place SET name = ? WHERE id = ?";
            PreparedStatement req = GuiLauncher.connection.prepareStatement(update);
            req.setInt(1, Integer.valueOf(p.getId().toString()));
            req.setString(2, p.getName());
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
    public boolean removePlace(Place p) {
        try {
            String delete = "DELETE FROM place WHERE id = ?";
            PreparedStatement req = GuiLauncher.connection.prepareStatement(delete);
            req.setInt(1, Integer.decode(p.getId().toString()));
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
    public List<Place> findAllPlaces() {
        List<Place> places = new ArrayList<>();
        try {
            PreparedStatement req = GuiLauncher.connection.prepareStatement("SELECT * FROM place");
            ResultSet result = req.executeQuery();
            while (result.next()) {
                Place place = new Place(result.getString(2));
                place.setId(result.getLong(1));
                places.add(place);
            }
            
        } catch (SQLException e) {
            try {
                System.out.println("Error findAllPlaces " + e);
                GuiLauncher.connection.rollback();
            } catch (SQLException e1) {
                System.out.println(e1);
            }
        }
        return places;
    }
}
