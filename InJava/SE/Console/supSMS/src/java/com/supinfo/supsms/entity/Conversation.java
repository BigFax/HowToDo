/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.entity;

import java.io.Serializable;
import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.List;
import javax.persistence.CascadeType;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.ManyToMany;
import javax.persistence.OneToMany;

/**
 *
 * @author 14309_000
 */
@Entity
public class Conversation implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    
    @ManyToMany(mappedBy = "conversations", cascade = {CascadeType.PERSIST, CascadeType.MERGE})
    private List<User> users;
    
    @OneToMany(mappedBy = "conversation",fetch = FetchType.EAGER, cascade = {CascadeType.PERSIST, CascadeType.MERGE, CascadeType.REMOVE}, orphanRemoval=true)
    private List<Sms> sms;
    
    public Conversation() {
        this.users = new ArrayList<User>();
        this.sms = new ArrayList<Sms>();
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
        if (!(object instanceof Conversation)) {
            return false;
        }
        Conversation other = (Conversation) object;
        if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "com.supinfo.supsms.entity.Conversation[ id=" + id + " ]";
    }

    public List<User> getUsers() {
        return this.users;
    }

    public void setUsers(List<User> users) {
        this.users = users;
    }

    public List<Sms> getSms() {
        return this.sms;
    }

    public void setSms(List<Sms> sms) {
        this.sms = sms;
    }
    
    public User getRecipientOfConversation(Long idSender) {
        User retournedUser = new User();
        for(final User convUser: this.users) {
            if(convUser.getId() != idSender) {
                retournedUser = convUser;
            }
        }
        return retournedUser;
    }
    
    public Sms getLastSms() {
        Sms lastSms = new Sms();
        lastSms.setTimestamp(new Timestamp(0));
        for(final Sms convSms: this.sms) {
            System.out.println(convSms.getTimestamp().toString());
            if(convSms.getTimestamp().compareTo(lastSms.getTimestamp()) > 0) {
                lastSms = convSms;
            }
        }
        return lastSms;
    }
    
    public void addSms(Sms sms) {
        this.sms.add(sms);
    }
    
    public void addUser(User user) {
        this.users.add(user);
    }
    
    public void removeUser(User user) {
        this.users.remove(user);
    }
}
