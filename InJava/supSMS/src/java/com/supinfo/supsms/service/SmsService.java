/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.service;

import com.supinfo.supsms.dao.SmsDao;
import com.supinfo.supsms.entity.Sms;
import javax.ejb.EJB;
import javax.ejb.Stateless;

/**
 *
 * @author clement
 */
@Stateless
public class SmsService {
    
    @EJB
    private SmsDao smsDao;
    
    public Sms createNewSms(Sms newSms) {
        return this.smsDao.createNewSms(newSms);
    }
    
    public Object modifySms(Sms modifiedSms) {
        return this.smsDao.modifySms(modifiedSms);
    }

    public int getNumberSmsFromDatabase(){
        return this.smsDao.getSmsNumberInDataBase();
    }
}
