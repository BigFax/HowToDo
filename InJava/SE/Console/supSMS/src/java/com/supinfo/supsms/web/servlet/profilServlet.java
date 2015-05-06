package com.supinfo.supsms.web.servlet;

import com.supinfo.supsms.entity.User;
import com.supinfo.supsms.service.UserService;
import java.io.IOException;
import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(name = "userProfileServlet", urlPatterns = {"/auth/userProfil"})
public class profilServlet extends HttpServlet {
    
    @EJB
    private UserService userService;
    
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.getRequestDispatcher("/jsp/authJsp/userProfile.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException { 
        
        String firstname = req.getParameter("firstname");
        String lastname = req.getParameter("lastname");
        String email = req.getParameter("email");
        String phonenumber = req.getParameter("phonenumber");
        String creditcard = req.getParameter("creditcard");
        String password = req.getParameter("password");
        
        if(firstname.equals("") || lastname.equals("") || email.equals("") || phonenumber.equals("") || creditcard.equals("") || password.equals("")) {
            req.getSession().setAttribute("error", "All field are required !");
            doGet(req, resp);
        } else {
            User connectedUser = (User) req.getSession().getAttribute("user");

            connectedUser.setFirstName(firstname);
            connectedUser.setLastName(lastname);
            connectedUser.setEmail(email);
            connectedUser.setPhoneNumber(Long.valueOf(phonenumber));
            connectedUser.setCreditCard(Long.valueOf(creditcard));
            connectedUser.setPassword(password);

            Object result = this.userService.processUserModification(connectedUser);
            if(result.getClass().equals(User.class)) {
                req.getSession().removeAttribute("user");
                req.getSession().setAttribute("user", connectedUser);
                req.getSession().setAttribute("info", "Profil successfuly updated");
                resp.sendRedirect(getServletContext().getContextPath() + "/auth/userProfil");
            } else {
                req.getSession().setAttribute("error", result);
                doGet(req, resp);
            }  
        } 
    }
}
