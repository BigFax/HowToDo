/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.service;

import com.supinfo.supsms.dao.ConversationDao;
import com.supinfo.supsms.entity.Conversation;
import com.supinfo.supsms.entity.User;
import java.util.List;
import javax.ejb.EJB;
import javax.ejb.Stateless;

/**
 *
 * @author clement
 */
@Stateless
public class ConversationService {
    
    @EJB
    private ConversationDao conversationDao;
    
    public Conversation createNewConversation(Conversation newConversation) {
        return this.conversationDao.createNewConversation(newConversation);
    }
    
    public Object modifyConversation(Conversation modifiedCOnversation) {
        return this.conversationDao.modifyConversation(modifiedCOnversation);
    }
    
    public Conversation findConversationById(Long conversationId) {
        return this.conversationDao.findConversationById(conversationId);
    }
    
    public Conversation findConversationByUsers(User connectedUser, User receiverUser) {
        return this.conversationDao.findConversationByUsers(connectedUser, receiverUser);
    }
    
    public List<Conversation> getAllConversationFromUserId(Long userId) {
        return this.conversationDao.getAllConversationFromUserId(userId);
    } 
    
    public Boolean deleteConversation(Conversation deletedConversation) {
        return this.conversationDao.deleteConversation(deletedConversation);
    }
}
