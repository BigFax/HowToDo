/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.dao;

import com.supinfo.supsms.entity.Sms;
import java.util.List;
import javax.ejb.Local;

/**
 *
 * @author clement
 */
@Local
public interface SmsDao {
    
    public Sms createNewSms(Sms newSms);
    
    public Object modifySms(Sms modifiedSms);
    
    public Sms findSmsById(Long id);
        
    public int getSmsNumberInDataBase();
}
