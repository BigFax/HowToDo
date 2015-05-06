/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main.javaparadise.gui;

import com.main.javaparadise.beans.Trip;
import com.main.javaparadise.launcher.GuiLauncher;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;

/**
 *
 * @author 14309_000
 */
public class DashBoardFrame extends JFrame {
    private static JPanel root;
    private static JMenuBar menuBar;
    private static JMenu menu;
    private static JMenuItem addPlace;
    private static JMenuItem addTrip;
    private static JMenuItem quit;
    private static List<Trip> trips;
    private static TableModel tableModel;
    private static JTable table;
    
    public DashBoardFrame() {
        DashBoardFrame.root = new JPanel(new BorderLayout());
        
        /* Declare the bar and the first menu */
        DashBoardFrame.menuBar = new JMenuBar();
        DashBoardFrame.menu = new JMenu("Menu");
        
        /* Declare items and their listener */
        DashBoardFrame.addPlace = new JMenuItem("Add a Place");
        DashBoardFrame.addPlace.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new AddPlaceFrame();
            }
        });
        
        DashBoardFrame.addTrip = new JMenuItem("Add a Trip");
        DashBoardFrame.addTrip.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new AddTripFrame();
            }
        });
                
        DashBoardFrame.quit = new JMenuItem("Quit");
        DashBoardFrame.quit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                DashBoardFrame.this.dispose();
                System.exit(0);
            }
        });
        
        /* Add item to the menu */
        DashBoardFrame.menu.add(DashBoardFrame.addPlace);
        DashBoardFrame.menu.add(DashBoardFrame.addTrip);
        DashBoardFrame.menu.add(DashBoardFrame.quit);
        
        /* Add menu to the bar */
        DashBoardFrame.menuBar.add(DashBoardFrame.menu);
        
        DashBoardFrame.trips = GuiLauncher.jdbcTrip.findAllTrips();
        DashBoardFrame.tableModel = new TableModel(trips);
        DashBoardFrame.table = new JTable(tableModel);
        
        DashBoardFrame.root.add(new JScrollPane(table), BorderLayout.CENTER);
        setContentPane(root);
        
        /* Set window properties */
        setJMenuBar(menuBar);
        setSize(600, 400);
        setVisible(true);
        setTitle("Java Paradise - Dashboard");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
    }
    
    public static void refresh() {
        DashBoardFrame.trips = GuiLauncher.jdbcTrip.findAllTrips();
        DashBoardFrame.tableModel.setTrips(trips);
        DashBoardFrame.tableModel.fireTableDataChanged();
    }
}
