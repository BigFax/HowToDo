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

@WebServlet(name = "CreateContactServlet", urlPatterns = {"/auth/createContact"})
public class CreateContactServlet extends HttpServlet {

    @EJB
    private ContactService contactService;
    
    @EJB
    private UserService userService;
    
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.getRequestDispatcher("/jsp/authJsp/contact/createContact.jsp").forward(req, resp);
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
            contact.setFirstName(firstname);
            contact.setLastName(lastname);
            contact.setEmail(email);
            contact.setPostalAddress(postaladdress);
            contact.setPhoneNumber(Long.valueOf(phonenumber));
            User test = (User) req.getSession().getAttribute("user");
            contact.setUser(test);
            test.addContact(contact);
            if(this.contactService.findContactByPhoneNumber(Long.valueOf(phonenumber)).getId() == null) {
                if(this.userService.processUserModification(test).getClass().equals(User.class)) {
                    req.getSession().setAttribute("info", "Contact succesfully created");
                    resp.sendRedirect(getServletContext().getContextPath() + "/auth/manageContact");
                } else {
                    req.getSession().setAttribute("error", "An error was encoutered while creating your account");
                    doGet(req, resp);
                }
            } else {
                req.getSession().setAttribute("error", "An contact with this phone number already exist");
                doGet(req, resp);
            } 
        } 
    }
}
