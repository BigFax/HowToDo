/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.dao.jpa;

import com.supinfo.supsms.dao.ContactDao;
import com.supinfo.supsms.entity.Contact;
import java.util.List;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

/**
 *
 * @author clement
 */
@Stateless
public class JpaContactDao implements ContactDao{
    
    @PersistenceContext
    private EntityManager em;
    
    @Override
    public Contact registerNewContact(Contact newContact){
        try {
            this.em.persist(newContact);   
            this.em.flush();
        } catch(Exception e) {
            System.out.print(e);
        }
        return newContact;
    }
    
    @Override
    public Object modifyRegisterContact(Contact modifiedContact) {
        String result = "";
        Contact dbContact = this.findContactById(modifiedContact.getId());
        if(dbContact.getId() != null && dbContact.getId().equals(modifiedContact.getId())) {
            try {
                this.em.merge(modifiedContact);
                this.em.flush();
            } catch(Exception e) {
                result = "Error while save your modification.";
            }
        } else {
            result = "Error while save your modification.";
        }
        return result.equals("") ? modifiedContact : result;
    }
    
    @Override
    public Contact findContactById(Long contactId) {
        Contact resultContact;
        try {
            resultContact = em.find(Contact.class, contactId);
        } catch(Exception e) {
            resultContact = new Contact();
        }
        
        return resultContact;
    }
    
    @Override
    public Contact findContactByPhoneNumber(Long phoneNumber) {
        Query query = this.em.createQuery("SELECT contact FROM Contact AS contact WHERE contact.phoneNumber = :phone"); 
        query.setParameter("phone", phoneNumber);
        Contact resultContact;
        try {
            resultContact = (Contact)query.getSingleResult();    
        } catch(Exception e) {
            resultContact = new Contact();
        }
        return resultContact;
    }
    
    @Override
    public int getNumberContactInDataBase() {
        Query query = this.em.createQuery("SELECT contact FROM Contact AS contact");
        return query.getResultList().size();   
    }
    
    @Override
    public List<Contact> getAllContact(Long id){
        Query query = this.em.createQuery("SELECT u.contacts FROM User AS u WHERE u.id = :id");
        query.setParameter("id", id);
        return query.getResultList();
    }
    
    @Override
    public Boolean deleteContact(Contact deletedContact) {
        Boolean result = false;
        try {
            Contact entity = this.em.getReference(Contact.class, deletedContact.getId());
            this.em.remove(entity);  
            this.em.flush();
            result = true;
        } catch(Exception e) {
            System.out.println(e);
            result = false;
        }
        return result;
    }
}
