/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main.javaparadise.gui;

import com.main.javaparadise.beans.Place;
import com.main.javaparadise.launcher.GuiLauncher;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author 14309_000
 */
public class AddPlaceFrame extends JFrame {
    private JTextField field;
    
    public AddPlaceFrame() {
        JPanel root = new JPanel(new BorderLayout());
        
        JPanel form = new JPanel();
        field = new JTextField();
        field.setPreferredSize(new Dimension(200, 25));
        form.add(field);
        
        JButton subButton = new JButton("Add Place");
        subButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Place place = new Place(field.getText());
                Long id = GuiLauncher.jdbcPlace.createPlace(place);
                JOptionPane.showConfirmDialog(AddPlaceFrame.this, "Place added into DB with ID: " + id, "Message", JOptionPane.DEFAULT_OPTION);
                DashBoardFrame.refresh();
            }
        });
        
        form.add(subButton);
        
        root.add(form, BorderLayout.NORTH);
        
        setContentPane(root);
        
        /* Set window properties */
        setSize(400, 300);
        setVisible(true);
        setTitle("JavaParadise");
        setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
        setLocationRelativeTo(null);
    }
}
