/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.web.servlet.Contact;

import com.supinfo.supsms.entity.Contact;
import com.supinfo.supsms.entity.User;
import com.supinfo.supsms.service.ContactService;
import com.supinfo.supsms.service.UserService;
import java.io.IOException;
import java.lang.reflect.Field;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet(name = "ContactServlet", urlPatterns = {"/auth/manageContact"})
public class ContactServlet extends HttpServlet {

    @EJB
    private ContactService contactService;
    
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        User user = (User) req.getSession().getAttribute("user");
        
        List<Contact> contacts = this.contactService.getAllContact(user.getId());
        
        /*List<Contact> contacts = this.contactService.getAllContact(user.getId()); // renvoie une " List " de " Contact "
        System.out.println(contacts); // Affiche " [null] "
        System.out.println(contacts.size()); // Affiche " 1 "*/
        
        if(contacts.size() != 0) {
            req.getSession().setAttribute("contactList", contacts);
        }
        
        req.getRequestDispatcher("/jsp/authJsp/contact/listContact.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
         
    }
}
