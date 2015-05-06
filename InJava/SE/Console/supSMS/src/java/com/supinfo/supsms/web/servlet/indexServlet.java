package com.supinfo.supsms.web.servlet;

import com.supinfo.supsms.entity.Contact;
import com.supinfo.supsms.entity.Conversation;
import com.supinfo.supsms.entity.User;
import com.supinfo.supsms.service.ConversationService;
import com.supinfo.supsms.service.SmsService;
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


@WebServlet(name = "indexServlet", urlPatterns = {"/index"})
public class indexServlet extends HttpServlet {
    
    @EJB
    private UserService userService;
    
    @EJB
    private ConversationService ConversationService;
    
    @EJB
    private SmsService smsService;
    
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        
        if(req.getSession().getAttribute("user") != null) {
            User connectedUser = this.userService.findUserById(((User) req.getSession().getAttribute("user")).getId());
            List<Conversation> conv =  this.ConversationService.getAllConversationFromUserId(connectedUser.getId());
            if(!conv.isEmpty() && conv.get(0) != null) {
                List<Object> allConvInfo = new ArrayList<Object>();
                
                for(final Conversation theConv : conv) {
                    List<Object> subConvInfo = new ArrayList<Object>();
                    User recipientUser = theConv.getRecipientOfConversation(connectedUser.getId());
                    String contact = String.valueOf(recipientUser.getPhoneNumber());

                    for(final Contact iContact : connectedUser.getContacts()) {
                        if(iContact.getPhoneNumber() == recipientUser.getPhoneNumber()) {
                            contact = iContact.getFirstName() + " " + iContact.getLastName();
                            break;
                        }
                    }
                    subConvInfo.add(contact);
                    subConvInfo.add(theConv.getLastSms());
                    subConvInfo.add(theConv.getId());
                    allConvInfo.add(subConvInfo);
                }
                req.getSession().setAttribute("listConversation", allConvInfo);
            } else {
                
                
            }
        } else {
            req.getSession().setAttribute("smsNumber", this.smsService.getNumberSmsFromDatabase());
            req.getSession().setAttribute("userNumber", this.userService.getNumberUserInDataBase());
        }
        req.getRequestDispatcher("/index.jsp").forward(req, resp);
    }
    
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.sendRedirect(getServletContext().getContextPath());        
    }
}
