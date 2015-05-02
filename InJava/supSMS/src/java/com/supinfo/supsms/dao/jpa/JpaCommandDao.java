/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.dao.jpa;

import com.supinfo.supsms.dao.CommandDao;
import com.supinfo.supsms.entity.Command;
import java.util.List;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;
import javax.persistence.TypedQuery;
import javax.persistence.criteria.CriteriaBuilder;
import javax.persistence.criteria.CriteriaQuery;
import javax.persistence.criteria.Root;

/**
 *
 * @author clement
 */
@Stateless
public class JpaCommandDao implements CommandDao{
    
    @PersistenceContext
    private EntityManager em;
    
    @Override
    public Command registerNewCommand(Command newCommand){
        try {
            this.em.persist(newCommand);   
            this.em.flush();
        } catch(Exception e) {
            System.out.print(e);
        }
        return newCommand;
    }
    
    @Override
    public Object modifyRegisterCommand(Command modifiedCommand) {
        String result = "";
        Command dbCommand = this.findCommandById(modifiedCommand.getId());
        if(dbCommand.getId() != null && dbCommand.getId().equals(modifiedCommand.getId())) {
            try {
                this.em.merge(modifiedCommand);
                this.em.flush();
            } catch(Exception e) {
                result = "Error while save your modification.";
            }
        } else {
            result = "Error while save your modification.";
        }
        return result.equals("") ? modifiedCommand : result;
    }
    
    @Override
    public Command findCommandById(Long commandId) {
        Command resultCommand;
        try {
            resultCommand = em.find(Command.class, commandId);
        } catch(Exception e) {
            resultCommand = new Command();
        }
        
        return resultCommand;
    }
    
    @Override
    public Command findCommandByPhoneNumber(Long phoneNumber) {
        Query query = this.em.createQuery("SELECT command FROM Command AS command WHERE command.phoneNumber = :phone"); 
        query.setParameter("phone", phoneNumber);
        Command resultCommand;
        try {
            resultCommand = (Command)query.getSingleResult();    
        } catch(Exception e) {
            resultCommand = new Command();
        }
        return resultCommand;
    }
    
    @Override
    public int getNumberCommandInDataBase() {
        Query query = this.em.createQuery("SELECT command FROM Command AS command");
        return query.getResultList().size();   
    }
    
    @Override
    public List<Command> getAllCommand(Long id){
        Query query = this.em.createQuery("SELECT u.commands FROM User AS u WHERE u.id = :id");
        query.setParameter("id", id);
        return query.getResultList();
    }
    
    @Override
    public List<Command> getAllCommands(){
        CriteriaBuilder cb = em.getCriteriaBuilder();
        CriteriaQuery<Command> cq = cb.createQuery(Command.class);
        Root<Command> rootEntry = cq.from(Command.class);
        CriteriaQuery<Command> all = cq.select(rootEntry);
        TypedQuery<Command> allQuery = em.createQuery(all);
        return allQuery.getResultList();
    }
    
    @Override
    public Boolean deleteCommand(Command deletedCommand) {
        Boolean result = false;
        try {
            Command entity = this.em.getReference(Command.class, deletedCommand.getId());
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
