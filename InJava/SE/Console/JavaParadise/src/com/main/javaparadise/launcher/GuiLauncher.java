/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main.javaparadise.launcher;

import com.main.javaparadise.gui.DashBoardFrame;
import com.main.javaparadise.jdbc.JdbcPlaceDao;
import com.main.javaparadise.jdbc.JdbcTripDao;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 *
 * @author 14309_000
 */
public class GuiLauncher {
    
    public static Connection connection;
	
    private static final String URL = "jdbc:mysql://localhost/paradise";
    private static final String LOGIN = "root";
    private static final String PASSWORD = "";
    public static final JdbcPlaceDao jdbcPlace = new JdbcPlaceDao();
    public static final JdbcTripDao jdbcTrip = new JdbcTripDao();
    
    public GuiLauncher() {
        DashBoardFrame dbf = new DashBoardFrame();
    }

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
        
        GuiLauncher launcher = new GuiLauncher();
    }
}
