/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.dao.jpa;

import com.supinfo.supsms.dao.ConversationDao;
import com.supinfo.supsms.entity.Conversation;
import com.supinfo.supsms.entity.User;
import java.util.ArrayList;
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
public class JpaConversationDao implements ConversationDao{
    
    @PersistenceContext
    private EntityManager em;
    
    @Override
    public Conversation createNewConversation(Conversation newConversation) {
        try {
            this.em.persist(newConversation);
            this.em.flush();
        } catch(Exception e) { 
            System.out.print(e);
        }
        return newConversation;
    }
    
    @Override
    public Object modifyConversation(Conversation modifiedConversation) {
        String result = "";
        Conversation dbConversation;
         
        if(modifiedConversation.getId() == null) {
            dbConversation = this.createNewConversation(modifiedConversation) ;
        } else {
            dbConversation = this.findConversationById(modifiedConversation.getId());
        }
        if(dbConversation.getId() != null && dbConversation.getId().equals(modifiedConversation.getId())) {
            try {
                this.em.merge(modifiedConversation);
                this.em.flush();
            } catch(Exception e) {
                result = "Error while save your modification.";
            }
        } else {
            result = "Error while save your modification.";
        }
        return result.equals("") ? modifiedConversation : result;
    }
    
    @Override
    public Conversation findConversationById(Long id) {
        Conversation resultConversation;
        try {
            resultConversation = this.em.find(Conversation.class, id);
        } catch(Exception e) {
            System.out.println(e);
            resultConversation = new Conversation();
        }
        
        return resultConversation;
    }
    
    @Override
    public Conversation findConversationByUsers(User connectedUser, User receiverUser) {
        List<Conversation> listResultConversation = this.getAllConversationFromUserId(connectedUser.getId());
        Boolean find = false;
        Conversation conversation = new Conversation();
        
        for(final Conversation searchConversation: listResultConversation) {
            if(find == true || searchConversation == null) {
                break;
            }
            for(final User searchedUser : searchConversation.getUsers()) {
                if(searchedUser.getId() == receiverUser.getId()) {
                    conversation = searchConversation;
                    find = true;
                    break;
                }
            }
            
        }
        return conversation;
    }
    
    @Override
    public List<Conversation> getAllConversationFromUserId(Long userId) {
        
        Query query = this.em.createQuery("SELECT u.conversations FROM User AS u WHERE u.id = :id"); 
        query.setParameter("id", userId);
        List<Conversation> listResultConversation;
        try {
            listResultConversation = query.getResultList();    
        } catch(Exception e) {
            listResultConversation = new ArrayList<Conversation>();
        }
        
        return listResultConversation;
    }
    
    @Override
    public Boolean deleteConversation(Conversation deletedConversation) {
        Boolean result = false;
        try {
            Conversation entity = this.em.find(Conversation.class, deletedConversation.getId());
            this.em.remove(entity);  
            result = true;
        } catch(Exception e) {
            System.out.println(e);
            result = false;
        }
        return result;
    }
}
