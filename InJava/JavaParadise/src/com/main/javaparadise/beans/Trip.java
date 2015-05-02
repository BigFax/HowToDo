/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.main.javaparadise.beans;

import java.io.Serializable;
import java.math.BigDecimal;

/**
 *
 * @author 14309_000
 */
public class Trip implements Serializable {
    private Long id;
    private Place departure;
    private Place destination;
    private BigDecimal price;
    
    public Trip(Place departure, Place destination, BigDecimal price) {
        this.departure = departure;
        this.destination = destination;
        this.price = price;
    }

    /**
     * @return the id
     */
    public Long getId() {
        return id;
    }

    /**
     * @param id the id to set
     */
    public void setId(Long id) {
        this.id = id;
    }

    /**
     * @return the departure
     */
    public Place getDeparture() {
        return departure;
    }

    /**
     * @param departure the departure to set
     */
    public void setDeparture(Place departure) {
        this.departure = departure;
    }

    /**
     * @return the destination
     */
    public Place getDestination() {
        return destination;
    }

    /**
     * @param destination the destination to set
     */
    public void setDestination(Place destination) {
        this.destination = destination;
    }

    /**
     * @return the price
     */
    public BigDecimal getPrice() {
        return price;
    }

    /**
     * @param price the price to set
     */
    public void setPrice(BigDecimal price) {
        this.price = price;
    }
    
}
