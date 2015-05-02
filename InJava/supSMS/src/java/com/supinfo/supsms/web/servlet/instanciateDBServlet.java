package com.supinfo.supsms.web.servlet;

import com.supinfo.supsms.entity.Conversation;
import com.supinfo.supsms.entity.Role;
import com.supinfo.supsms.entity.Sms;
import com.supinfo.supsms.entity.User;
import com.supinfo.supsms.service.ConversationService;
import com.supinfo.supsms.service.RoleService;
import com.supinfo.supsms.service.SmsService;
import com.supinfo.supsms.service.UserService;
import java.io.IOException;
import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.List;
import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet(name = "instanciateDBServlet", urlPatterns = {"/instanciatedb"})
public class instanciateDBServlet extends HttpServlet {
    
    @EJB
    private UserService userService;
    
    @EJB
    private RoleService roleService;
    
    @EJB
    private ConversationService conversationService;
    
    @EJB
    private SmsService smsService;
    
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        
        Role adminRole = new Role();
        adminRole.setRoleName("ADMIN");
        this.roleService.processRoleRegistration(adminRole);
        
        Role userRole = new Role();
        userRole.setRoleName("USER");
        this.roleService.processRoleRegistration(userRole);

        User admin = new User();
        admin.setFirstName("admin");
        admin.setLastName("admin");
        admin.setEmail("admin@admin.com");
        admin.setPhoneNumber(0L);
        admin.setCreditCard(0L);
        admin.setPassword("admin");
        admin.setRole(adminRole);
        this.userService.processUserRegistration(admin);
        
        
        
        resp.sendRedirect(getServletContext().getContextPath());
    }
}
