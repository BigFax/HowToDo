package com.supinfo.supsms.web.servlet;

import com.supinfo.supsms.entity.Contact;
import com.supinfo.supsms.entity.Conversation;
import com.supinfo.supsms.entity.Sms;
import com.supinfo.supsms.entity.User;
import com.supinfo.supsms.service.ConversationService;
import com.supinfo.supsms.service.UserService;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet(name = "ConversationServlet", urlPatterns = {"/auth/conversation"})
public class ConversationServlet extends HttpServlet {
    
    @EJB
    private UserService userService;
    
    @EJB
    private ConversationService conversationService;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.getSession().removeAttribute("smsList");
        req.getSession().removeAttribute("recipientUser");
        Conversation conversation = this.conversationService.findConversationById(Long.valueOf(req.getParameter("id")));

        User connectedUser = this.userService.findUserById(((User) req.getSession().getAttribute("user")).getId());
        User recipientUser = conversation.getRecipientOfConversation(connectedUser.getId());
        String contact = String.valueOf(recipientUser.getPhoneNumber());

        for(final Contact iContact : connectedUser.getContacts()) {
            if(iContact.getPhoneNumber() == recipientUser.getPhoneNumber()) {
                contact = iContact.getFirstName() + " " + iContact.getLastName();
                break;
            }
        }
        String nameUser = connectedUser.getFirstName() + " " + connectedUser.getLastName();
        List<Object> ListSms = new ArrayList<Object>();
        for(final Sms sms : conversation.getSms()) {
            
            List<Object> infoSms = new ArrayList<Object>();
            if(sms.getUser().getId() == connectedUser.getId()) {
                infoSms.add(nameUser);
            } else {
                infoSms.add(contact);
            }   
            infoSms.add(sms);
            ListSms.add(infoSms);
        }
        
        req.getSession().setAttribute("idUser", connectedUser.getId());
        req.getSession().setAttribute("smsList", ListSms);
        req.getSession().setAttribute("contactName", contact);
        req.getRequestDispatcher("/jsp/authJsp/conversation.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.sendRedirect(getServletContext().getContextPath()); 
    }
}
