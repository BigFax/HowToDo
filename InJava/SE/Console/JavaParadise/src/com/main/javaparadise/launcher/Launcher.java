/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main.javaparadise.launcher;

import com.main.javaparadise.beans.Place;
import com.main.javaparadise.beans.Trip;
import com.main.javaparadise.jdbc.JdbcPlaceDao;
import com.main.javaparadise.jdbc.JdbcTripDao;
import java.math.BigDecimal;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 *
 * @author 14309_000
 */
public class Launcher {
    public static Connection connection;
	
    private static String URL = "jdbc:mysql://localhost/paradise";
    private static String LOGIN = "root";
    private static String PASSWORD = "";

    public static void main(String[] args) {
        // Load JDBC driver
        try {
            Class.forName(
            com.mysql.jdbc.Driver.class.getName());
        } catch(ClassNotFoundException e) {
            System.out.println("Can’t load JDBC driver.");
        }
        
        // Connect to the database
        try {
            connection = DriverManager.getConnection(URL, LOGIN, PASSWORD);
            connection.setAutoCommit(false);
        } catch (SQLException e) {
            System.out.println("Can’t connect to the database.");
        }
        
        //Test
        /*JdbcPlaceDao jdbcPlace = new JdbcPlaceDao();
        JdbcTripDao jdbcTrip = new JdbcTripDao();

        Place place = new Place("Paris");
        Place place2 = new Place("Lyon");
        jdbcPlace.createPlace(place);
        jdbcPlace.createPlace(place2);

        Trip trip = new Trip(place, place2, BigDecimal.valueOf(550));
        Trip trip2 = new Trip(place2, place, BigDecimal.valueOf(450));

        jdbcTrip.createTrip(trip);
        jdbcTrip.createTrip(trip2);

        jdbcTrip.removeTrip(trip);

        jdbcPlace.removePlace(place);
        place2.setName("Hamsterdam");
        jdbcPlace.updatePlace(place2);
        
        System.out.println("finish");*/
    }
}
