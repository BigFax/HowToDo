/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main.javaparadise.gui;

import com.main.javaparadise.beans.Trip;
import com.main.javaparadise.beans.Place;
import com.main.javaparadise.launcher.GuiLauncher;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.math.BigDecimal;
import java.util.List;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author 14309_000
 */
public class AddTripFrame extends JFrame {
    private JComboBox from;
    private JComboBox to;
    private JTextField price;
    
    public AddTripFrame() {
        JPanel root = new JPanel(new BorderLayout());
        
        JPanel inputs = new JPanel(new GridBagLayout());
        GridBagConstraints constraints = new GridBagConstraints();
        GridBagConstraints constraints2 = new GridBagConstraints();
        constraints.fill = GridBagConstraints.HORIZONTAL;
        constraints.insets = new Insets(10, 25, 10, 0);
        constraints2.fill = GridBagConstraints.HORIZONTAL;
        constraints2.insets = new Insets(10, 0, 10, 0);
        
        List<Place> dropDownList;
        dropDownList = GuiLauncher.jdbcPlace.findAllPlaces();
        constraints.gridy = 1;
        constraints2.gridy = 1;
        inputs.add(new JLabel("From : "), constraints2);
        this.from = new JComboBox(new PlaceComboBoxModel(dropDownList));
        inputs.add(this.from, constraints);
        constraints.gridy = 2;
        constraints2.gridy = 2;
        inputs.add(new JLabel("To : "), constraints2);
        this.to = new JComboBox(new PlaceComboBoxModel(dropDownList));
        inputs.add(this.to, constraints);
        constraints.gridy = 3;
        constraints2.gridy = 3;
        inputs.add(new JLabel("Price : "), constraints2);
        this.price = new JTextField();
        inputs.add(this.price, constraints);
        inputs.add(new JLabel("$"), constraints2);
        
        JPanel submit = new JPanel(new FlowLayout());
        
        /* Cancel button and Listener */
        JButton cancelButton = new JButton("Cancel");
        cancelButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                AddTripFrame.this.dispose();
            }
        });
        submit.add(cancelButton);
        
        /* Submit button and Listener */
        JButton subButton = new JButton("Add Trip");
        subButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Trip trip = new Trip((Place) from.getSelectedItem(), (Place) to.getSelectedItem(), new BigDecimal(price.getText()));
                Long id = GuiLauncher.jdbcTrip.createTrip(trip);
                JOptionPane.showConfirmDialog(AddTripFrame.this, "Trip added into DB with ID: " + id, "Message", JOptionPane.DEFAULT_OPTION);
                DashBoardFrame.refresh();
            }
        });
        submit.add(subButton);
        
        root.add(inputs, BorderLayout.NORTH);
        root.add(submit, BorderLayout.CENTER);
        
        setContentPane(root);
        
        /* Set window properties */
        setSize(400, 300);
        setVisible(true);
        setTitle("JavaParadise");
        setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
        setLocationRelativeTo(null);
    }
}
