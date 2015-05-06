/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.dao;

import com.supinfo.supsms.entity.Command;
import java.util.List;
import javax.ejb.Local;

/**
 *
 * @author clement
 */
@Local
public interface CommandDao {
    
    public Command registerNewCommand(Command newCommand);
    
    public Object modifyRegisterCommand(Command modifiedCommand);
    
    public Command findCommandById(Long commandId);
    
    public Command findCommandByPhoneNumber(Long phoneNumber);
    
    public int getNumberCommandInDataBase();
    
    public List<Command> getAllCommand(Long id);
    
    public List<Command> getAllCommands();
    
    public Boolean deleteCommand(Command deletedCommand);
    
}
