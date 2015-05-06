package com.supinfo.supsms.web.servlet;

import com.supinfo.supsms.entity.Conversation;
import com.supinfo.supsms.entity.Sms;
import com.supinfo.supsms.entity.User;
import com.supinfo.supsms.service.ConversationService;
import com.supinfo.supsms.service.UserService;
import java.io.IOException;
import java.sql.Timestamp;
import java.util.Hashtable;
import java.util.Properties;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.ejb.EJB;
import javax.jms.Connection;
import javax.jms.ConnectionFactory;
import javax.jms.Destination;
import javax.jms.JMSException;
import javax.jms.MessageProducer;
import javax.jms.Session;
import javax.jms.TextMessage;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet(name = "sendSmsServlet", urlPatterns = {"/auth/sendSms"})
public class sendSmsServlet extends HttpServlet {

    @EJB 
    private ConversationService conversationService;
    
    @EJB
    private UserService userService;
    
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.getRequestDispatcher("/jsp/authJsp/sendSms.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String phonenumber = req.getParameter("phonenumber");
        String message = req.getParameter("message");
        
        User connectedUser = (User) req.getSession().getAttribute("user");
        User receiverUser = this.userService.findUserByPhoneNumber(Long.valueOf(phonenumber));
        
        if(receiverUser.getId() != null) {
            Conversation conv = this.conversationService.findConversationByUsers(connectedUser, receiverUser);

            Sms newSms = new Sms();
            newSms.setUser(connectedUser);
            newSms.setMessage(message);
            newSms.setTimestamp(new Timestamp(new java.util.Date().getTime()));
            newSms.setRecipientNumber(Long.valueOf(phonenumber));

            if(conv.getUsers().isEmpty()) {
                this.conversationService.modifyConversation(conv);
                conv.addUser(connectedUser);
                conv.addUser(receiverUser);
            }

            conv.addSms(newSms);
            newSms.setConversation(conv);
            connectedUser.addConversation(conv);
            receiverUser.addConversation(conv);

            this.conversationService.modifyConversation(conv);

            /**
             * IMPLEMENTATION JMS
             * 
             * Dans le panel d'admin de Glassfish, la configuration est la suivante :
             * - Connection Factories : Celle par defaut
             * - Destination Resources : 
             *      -  JNDI Name: jms/sms
             *      -  Physical Destination Name : sms
             */
            Context ctx;
            try {
                ctx = new InitialContext();
                ConnectionFactory connectionFactory = (ConnectionFactory) ctx.lookup("jms/__defaultConnectionFactory");
                Destination destination = (Destination) ctx.lookup("jms/sms");
                Connection cnx = connectionFactory.createConnection();
                Session session = cnx.createSession(false, Session.AUTO_ACKNOWLEDGE);

                MessageProducer producer = session.createProducer(destination);

                TextMessage smsMessage = session.createTextMessage();
                smsMessage.setText(connectedUser.getPhoneNumber() + "\n\r" + newSms.getMessage() + "\n\r" + receiverUser.getPhoneNumber());
                producer.send(smsMessage);			    
                cnx.close();
                System.out.println("SMS SENT TO THE NETWORK");
            } catch (NamingException ex) {
                Logger.getLogger(sendSmsServlet.class.getName()).log(Level.SEVERE, null, ex);
            } catch (JMSException ex) {
                Logger.getLogger(sendSmsServlet.class.getName()).log(Level.SEVERE, null, ex);
            }

            resp.sendRedirect(getServletContext().getContextPath() + "/auth/conversation?id="+conv.getId());
        } else {
            req.getSession().setAttribute("error", "This phone number is not correct !");
            doGet(req, resp);
        }
        
             
    }
}
