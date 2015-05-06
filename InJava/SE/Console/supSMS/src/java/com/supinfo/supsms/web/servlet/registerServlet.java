package com.supinfo.supsms.web.servlet;

import com.supinfo.supsms.entity.Command;
import com.supinfo.supsms.entity.User;
import com.supinfo.supsms.service.RoleService;
import com.supinfo.supsms.service.UserService;
import java.io.IOException;
import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet(name = "registerServlet", urlPatterns = {"/anon/register"})
public class registerServlet extends HttpServlet {
    
    @EJB
    private UserService userService;
    
    @EJB
    private RoleService roleService;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.getRequestDispatcher("/jsp/anonJsp/register.jsp").forward(req, resp);
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
            req.getSession().setAttribute("error", "All field a required !");
            doGet(req, resp);
        } else {
            User user = new User();
            user.setFirstName(firstname);
            user.setLastName(lastname);
            user.setEmail(email);
            user.setPhoneNumber(Long.valueOf(phonenumber));
            user.setCreditCard(Long.valueOf(creditcard));
            user.setPassword(password);
            user.setRole(this.roleService.findRoleByName("USER"));
            Command command = new Command();
            user.addCommand(command);
            command.setUser(user);

            if(this.userService.findUserByPhoneNumber(Long.valueOf(phonenumber)).getId() == null) {
                if(this.userService.processUserRegistration(user).getId() != 0) {
                    req.getSession().setAttribute("user", user);
                    resp.sendRedirect(getServletContext().getContextPath()); 
                } else {
                    req.getSession().setAttribute("error", "An error was encoutered while creating your account");
                    doGet(req, resp);
                }
            } else {
                req.getSession().setAttribute("error", "An user with this phone number already exist");
                doGet(req, resp);
            } 
        }        
    }
}
