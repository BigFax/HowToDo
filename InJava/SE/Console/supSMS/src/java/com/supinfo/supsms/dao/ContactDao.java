/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.dao;

import com.supinfo.supsms.entity.Contact;
import java.util.List;
import javax.ejb.Local;

/**
 *
 * @author clement
 */
@Local
public interface ContactDao {
    
    public Contact registerNewContact(Contact newContact);
    
    public Object modifyRegisterContact(Contact modifiedContact);
    
    public Contact findContactById(Long contactId);
    
    public Contact findContactByPhoneNumber(Long phoneNumber);
    
    public int getNumberContactInDataBase();
    
    public List<Contact> getAllContact(Long id);
    
    public Boolean deleteContact(Contact deletedContact);
    
}
