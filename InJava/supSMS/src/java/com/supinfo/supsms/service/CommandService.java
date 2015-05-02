/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.service;

import com.supinfo.supsms.dao.CommandDao;
import com.supinfo.supsms.entity.Command;
import java.util.List;
import javax.ejb.EJB;
import javax.ejb.Stateless;

/**
 *
 * @author clement
 */
@Stateless
public class CommandService {
    
    @EJB
    private CommandDao commandDao;
    
    public Command processCommandRegistration(Command newCommand) {
        this.commandDao.registerNewCommand(newCommand);   
        return newCommand;
    } 
    
    public Object processCommandModification(Command modifiedCommand) {
        return this.commandDao.modifyRegisterCommand(modifiedCommand);
    } 
    
    public Command findCommandById(Long commandId) {
        return this.commandDao.findCommandById(commandId);
    }
    
    public Command findCommandByPhoneNumber(Long phoneNumber) {
        return this.commandDao.findCommandByPhoneNumber(phoneNumber);
    }
    
    public int getNumberCommandInDataBase() {
        return this.commandDao.getNumberCommandInDataBase();
    }
    
    public List<Command> getAllCommand(Long id) {
        return this.commandDao.getAllCommand(id);
    }
    
    public List<Command> getAllCommands() {
        return this.commandDao.getAllCommands();
    }
    
    public Boolean deleteCommand(Command deletedCommand) {
        return this.commandDao.deleteCommand(deletedCommand);
    }
}
