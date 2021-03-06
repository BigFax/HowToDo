/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.entity;

import java.io.Serializable;
import java.sql.Timestamp;
import java.util.Calendar;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;

@Entity
public class Command implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    
    @ManyToOne @JoinColumn
    private User user;
    
    private Timestamp begin_at;
    
    private Timestamp expire_at;
    
    private int price;
    
    public Command() {
        this.begin_at = new Timestamp(new java.util.Date().getTime());
        
        Calendar cal = Calendar.getInstance(); 
        cal.add(Calendar.MONTH, 1);
        this.expire_at = new Timestamp(cal.getTime().getTime());
        this.price = 10;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (id != null ? id.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Command)) {
            return false;
        }
        Command other = (Command) object;
        if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "com.supinfo.supsms.entity.Command[ id=" + id + " ]";
    }
    
    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public Timestamp getBegin_at() {
        return begin_at;
    }

    public void setBegin_at(Timestamp begin_at) {
        this.begin_at = begin_at;
    }

    public Timestamp getExpire_at() {
        return expire_at;
    }

    public void setExpire_at(Timestamp expire_at) {
        this.expire_at = expire_at;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }
    
}
