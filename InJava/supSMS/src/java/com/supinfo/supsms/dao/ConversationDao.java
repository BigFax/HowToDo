/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.dao;

import com.supinfo.supsms.entity.Conversation;
import com.supinfo.supsms.entity.User;
import java.util.List;
import javax.ejb.Local;

/**
 *
 * @author clement
 */
@Local
public interface ConversationDao {
    
    public Conversation createNewConversation(Conversation newConversation);
    
    public Object modifyConversation(Conversation modifiedConversation);
    
    public Conversation findConversationById(Long id);
    
    public Conversation findConversationByUsers(User connectedUser, User receiverUser);
    
    public List<Conversation> getAllConversationFromUserId(Long userId);
    
    public Boolean deleteConversation(Conversation deletedConversation);
}
