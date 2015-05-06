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


@WebServlet(name = "LoginServlet", urlPatterns = {"/anon/login"})
public class LoginServlet extends HttpServlet {

    @EJB
    private UserService userService;
    
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.getRequestDispatcher("/jsp/anonJsp/login.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String password = req.getParameter("password");
        String phonenumber = req.getParameter("phonenumber");
        
        if(phonenumber.equals("") || password.equals("")) {
            req.getSession().setAttribute("error", "All field a required !");
            doGet(req, resp);
        } else {
            User user = this.userService.findUserByPhoneNumber(Long.valueOf(phonenumber));        
            if(user.getId() == null || !password.equals(user.getPassword())) {
                doGet(req, resp);
            } else {
                req.getSession().setAttribute("user", user);
                resp.sendRedirect(getServletContext().getContextPath());
            } 
        }  
    }
}
