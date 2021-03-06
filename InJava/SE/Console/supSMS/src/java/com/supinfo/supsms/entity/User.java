/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.entity;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToMany;
import javax.persistence.OneToMany;
import javax.persistence.ManyToOne;
import javax.validation.constraints.NotNull;

/**
 *
 * @author clement
 */
@Entity
public class User implements Serializable {
    private static final long serialVersionUID = 1L;
   
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    
    @NotNull
    @Column(nullable=false)
    private String firstName;

    @NotNull
    @Column(nullable=false)
    private String lastName;
    
    @NotNull
    @Column(nullable=false)
    private String email;
    
    @NotNull
    @Column(nullable=false)
    private Long phoneNumber;
    
    @NotNull
    @Column(nullable=false)
    private Long creditCard;

    @NotNull
    @Column(nullable=false)
    private String password;
    
    @ManyToOne
    @JoinColumn(name="role_fk")
    private Role userRole;

    @ManyToMany(cascade = {CascadeType.PERSIST, CascadeType.MERGE, CascadeType.REMOVE})
    private List<Conversation> conversations;
    
    @OneToMany(mappedBy = "user", cascade = {CascadeType.PERSIST, CascadeType.MERGE, CascadeType.REMOVE}) @JoinColumn
    private List<Contact> contacts;
    
    @OneToMany(mappedBy = "user", cascade = {CascadeType.PERSIST, CascadeType.MERGE, CascadeType.REMOVE}) @JoinColumn
    private List<Command> commands;
    
    @OneToMany(mappedBy = "user",fetch = FetchType.LAZY, cascade = {CascadeType.PERSIST, CascadeType.MERGE, CascadeType.REMOVE}, orphanRemoval=true)
    @JoinColumn
    private List<Sms> sms;
    
    public User() {
        this.conversations = new ArrayList<Conversation>();
        this.contacts = new ArrayList<Contact>();
	this.commands = new ArrayList<Command>();
        this.sms = new ArrayList<Sms>();
    }
    
    public String toString() {
        String toString = 
                "ID : " + this.id +"\n"+
                "Firstname : " + this.firstName + "\n"+
                "Lastname : " + this.lastName + "\n"+
                "Email : " + this.email +"\n"+
                "phone number : " + this.phoneNumber +"\n"+
                "creditcard : " + this.creditCard +"\n"+
                "password : " + this.password +"\n";
        return toString;
    }

    /**
     * @return the id
     */
    public Long getId() {
        return this.id;
    }

    /**
     * @param id the id to set
     */
    public void setId(Long id) {
        this.id = id;
    }

    /**
     * @return the FirstName
     */
    public String getFirstName() {
        return this.firstName;
    }

    /**
     * @param firstName the FirstName to set
     */
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    /**
     * @return the LastName
     */
    public String getLastName() {
        return this.lastName;
    }

    /**
     * @param lastName the LastName to set
     */
    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    /**
     * @return the Email
     */
    public String getEmail() {
        return this.email;
    }

    /**
     * @param email the Email to set
     */
    public void setEmail(String email) {
        this.email = email;
    }
    
    /**
     * @return the phone number
     */
    public Long getPhoneNumber() {
        return this.phoneNumber;
    }

    /**
     * @param phoneNumber the phone number to set
     */
    public void setPhoneNumber(Long phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
    
    /**
     * @return the phone number
     */
    public Long getCreditCard() {
        return this.creditCard;
    }

    /**
     * @param creditCard the credit crad number to set
     */
    public void setCreditCard(Long creditCard) {
        this.creditCard = creditCard;
    }
    
    /**
     * @return the Email
     */
    public String getPassword() {
        return this.password;
    }

    /**
     * @param password the Email to set
     */
    public void setPassword(String password) {
        this.password = password;
    }
    
    /**
     * @return the Role
     */
    public Role getRole() {
        return this.userRole;
    }
    
    /**
     * @param newRole the role to set
     */
    public void setRole(Role newRole) {
        this.userRole = newRole;
    }
    
    public List<Conversation> getConversations() {
        return this.conversations;
    }

    public void setConversations(List<Conversation> conversations) {
        this.conversations = conversations;
    }
    
    public void addConversation(Conversation conversation) {
        this.conversations.add(conversation);
    }

    public List<Contact> getContacts() {
        return this.contacts;
    }

    public void setContacts(List<Contact> contacts) {
        this.contacts = contacts;
    }
    
    public void addContact(Contact contact) {
        this.contacts.add(contact);
    }
    
    public void removeContact(Contact contact) {
        this.contacts.remove(contact);
    }
    
    public List<Sms> getSms() {
        return this.sms;
    }
    
    public void setSms(List<Sms> sms) {
        this.sms = sms;
    }

    public List<Command> getCommands() {
        return this.commands;
    }

    public void setCommands(List<Command> commands) {
        this.commands = commands;
    }
    
    public void addCommand(Command command) {
        this.commands.add(command);
    }
    
    public void removeCommand(Command command) {
        this.commands.remove(command);
    }
}
