/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.service;

import com.supinfo.supsms.dao.ContactDao;
import com.supinfo.supsms.entity.Contact;
import java.util.List;
import javax.ejb.EJB;
import javax.ejb.Stateless;

/**
 *
 * @author clement
 */
@Stateless
public class ContactService {
    
    @EJB
    private ContactDao contactDao;
    
    public Contact processContactRegistration(Contact newContact) {
        this.contactDao.registerNewContact(newContact);   
        return newContact;
    } 
    
    public Object processContactModification(Contact modifiedContact) {
        return this.contactDao.modifyRegisterContact(modifiedContact);
    } 
    
    public Contact findContactById(Long contactId) {
        return this.contactDao.findContactById(contactId);
    }
    
    public Contact findContactByPhoneNumber(Long phoneNumber) {
        return this.contactDao.findContactByPhoneNumber(phoneNumber);
    }
    
    public int getNumberContactInDataBase() {
        return this.contactDao.getNumberContactInDataBase();
    }
    
    public List<Contact> getAllContact(Long id) {
        return this.contactDao.getAllContact(id);
    }
    
    public Boolean deleteContact(Contact deletedContact) {
        return this.contactDao.deleteContact(deletedContact);
    }
}
