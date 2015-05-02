/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.web.servlet.Contact;

import com.supinfo.supsms.entity.Contact;
import com.supinfo.supsms.entity.Conversation;
import com.supinfo.supsms.entity.User;
import com.supinfo.supsms.service.ContactService;
import com.supinfo.supsms.service.ConversationService;
import com.supinfo.supsms.service.UserService;
import java.io.IOException;
import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(name = "DeleteContactServlet", urlPatterns = {"/auth/deleteContact"})
public class DeleteContactServlet extends HttpServlet {

    @EJB
    private ContactService contactService;
    
    @EJB
    private UserService userService;
    
    @EJB
    private ConversationService conversationService;

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Long contactId = Long.valueOf(req.getParameter("id"));
        User connectedUser = this.userService.findUserById(((User) req.getSession().getAttribute("user")).getId());
        User contactUser = this.userService.findUserByPhoneNumber(this.contactService.findContactById(contactId).getPhoneNumber());
        
        connectedUser.removeContact(this.contactService.findContactById(contactId));
        
        Conversation conv = this.conversationService.findConversationByUsers(connectedUser, contactUser);
        conv.removeUser(connectedUser);
        
        if(this.contactService.deleteContact(this.contactService.findContactById(contactId)) == true) {
            if(this.userService.processUserModification(connectedUser).getClass().equals(User.class) 
                && this.conversationService.deleteConversation(conv)) {
                req.getSession().setAttribute("info", "Contact successfuly deleted");
            } else {
                req.getSession().setAttribute("error", "Error while deleting contact");
            }
            
        } else {
            req.getSession().setAttribute("error", "Error while deleting contact");
        }
        
        resp.sendRedirect(getServletContext().getContextPath() + "/auth/manageContact");
    }
}
