/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.dao.jpa;

import com.supinfo.supsms.dao.SmsDao;
import com.supinfo.supsms.entity.Sms;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

/**
 *
 * @author clement
 */
@Stateless
public class JpaSmsDao implements SmsDao{
    
    @PersistenceContext
    private EntityManager em;
    
    @Override
    public Sms createNewSms(Sms newSms) {
        try {
            this.em.persist(newSms);   
            this.em.flush();
        } catch(Exception e) {
            System.out.print(e);
        }
        return newSms;
    }
    
    @Override
    public Object modifySms(Sms modifiedSms) {
        String result = "";
        Sms dbSms = this.findSmsById(modifiedSms.getId());

        if(dbSms.getId() != null && dbSms.getId().equals(modifiedSms.getId())) {
            try {
                this.em.merge(modifiedSms);
                this.em.flush();
            } catch(Exception e) {
                result = "Error while save your modification.";
            }
        } else {
            result = "Error while save your modification.";
        }
        return result.equals("") ? modifiedSms : result;
    }
    
    @Override
    public Sms findSmsById(Long id) {
        Sms resultSms;
        try {
            resultSms = this.em.find(Sms.class, id);
        } catch(Exception e) {
            resultSms = new Sms();
        }
        
        return resultSms;
    }

    @Override
    public int getSmsNumberInDataBase() {
        Query query = this.em.createQuery("SELECT sms FROM Sms AS sms");
        return query.getResultList().size();
    }
}
