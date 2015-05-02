/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.supinfo.supsms.filter;

import com.supinfo.supsms.entity.User;
import com.supinfo.supsms.service.UserService;
import java.io.IOException;
import javax.ejb.EJB;
import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author clement
 */
@WebFilter(urlPatterns="/*")
public class BaseFilter implements Filter {
    
    @EJB
    private UserService userService;
    
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
    }
    
    @Override
    public void destroy() {
    }
    
    @Override
    public void doFilter(ServletRequest req, ServletResponse resp,FilterChain chain) throws IOException, ServletException {
        HttpServletRequest httpRequest = (HttpServletRequest) req;

        if(httpRequest.getSession().getAttribute("ephemere") == null
        && (httpRequest.getSession().getAttribute("info") != null || httpRequest.getSession().getAttribute("error") != null)) {
            httpRequest.getSession().setAttribute("ephemere", "true");
        } else {
            httpRequest.getSession().removeAttribute("info");
            httpRequest.getSession().removeAttribute("error");
            httpRequest.getSession().removeAttribute("ephemere");
        }
        
        if(httpRequest.getSession().getAttribute("user") != null) {
            httpRequest.getSession().removeAttribute("smsList");
            httpRequest.getSession().removeAttribute("userList");
            httpRequest.getSession().removeAttribute("contactName");
            httpRequest.getSession().removeAttribute("contactList");
            httpRequest.getSession().removeAttribute("recipientUser");
            httpRequest.getSession().removeAttribute("listConversation");
            
            User oldUser = (User) httpRequest.getSession().getAttribute("user");
            User newUser = this.userService.findUserById(oldUser.getId());  
            httpRequest.getSession().removeAttribute("user");
            httpRequest.getSession().setAttribute("user", newUser);
        }
        chain.doFilter(req, resp);
    }

    
}
