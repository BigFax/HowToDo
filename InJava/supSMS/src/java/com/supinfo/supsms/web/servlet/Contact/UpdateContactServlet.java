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
import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(name = "UpdateContactServlet", urlPatterns = {"/auth/updateContact"})
public class UpdateContactServlet extends HttpServlet {

    @EJB
    private ContactService contactService;
    
    @EJB
    private UserService userService;
    
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.getSession().setAttribute("contact", this.contactService.findContactById(Long.parseLong(req.getParameter("id"))));
        req.getRequestDispatcher("/jsp/authJsp/contact/updateContact.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String firstname = req.getParameter("firstname");
        String lastname = req.getParameter("lastname");
        String email = req.getParameter("email");
        String phonenumber = req.getParameter("phonenumber");
        String postaladdress = req.getParameter("postaladdress");
        
        if(firstname.equals("") || lastname.equals("") || email.equals("") || phonenumber.equals("") || postaladdress.equals("")) {
            req.getSession().setAttribute("error", "All field are required !");
            doGet(req, resp);
        } else {
            Contact contact = new Contact();
            contact.setId(Long.valueOf(req.getParameter("id")));
            contact.setFirstName(firstname);
            contact.setLastName(lastname);
            contact.setEmail(email);
            contact.setPostalAddress(postaladdress);
            contact.setPhoneNumber(Long.valueOf(phonenumber));
            
            contact.setUser((User) req.getSession().getAttribute("user"));
            if(this.userService.findUserByPhoneNumber(Long.valueOf(phonenumber)) != null) {
                if(((User) req.getSession().getAttribute("user")).getPhoneNumber() != Long.valueOf(phonenumber)) {
                    if(this.contactService.processContactModification(contact).getClass().equals(Contact.class)) {
                        resp.sendRedirect(getServletContext().getContextPath() + "/auth/manageContact"); 
                    } else {
                        req.getSession().setAttribute("error", "An error was encoutered while updating your contact");
                        doGet(req, resp);
                    }
                } else {
                    req.getSession().setAttribute("error", "This phone number is yours !");
                    doGet(req, resp);
                }
            } else {
                req.getSession().setAttribute("error", "An error was encoutered while updating your contact");
                doGet(req, resp);
            } 
        } 
    }
}
